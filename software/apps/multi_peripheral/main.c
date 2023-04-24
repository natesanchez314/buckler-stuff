// Display app
//
// Write messages to a Newhaven OLED display over SPI

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_error.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_serial.h"
#include "nrfx_gpiote.h"
#include "nrf_drv_spi.h"

#include "buckler.h"
#include "display.h"
#include "lsm9ds1.h"
#include <math.h>
#include "timestamp.h"

NRF_TWI_MNGR_DEF(twi_mngr_instance, 5, 0);
float timestamp = 0.0;
float pi = 0.0f;

float getAngle(float gravX, float gravY, float gravZ) {
   float rad = acos(gravZ / sqrtf((gravX * gravX) + (gravY * gravY) + (gravZ * gravZ)));
   return rad * 180 / pi;
 }

 float getAngleX(float gravX, float gravY, float gravZ) {
   float rad = atan(gravX / sqrtf((gravY * gravY) + (gravZ * gravZ)));
   return rad * 180 / pi;
 }

 float getAngleY(float gravX, float gravY, float gravZ) {
   float rad = atan(gravY / sqrtf((gravX * gravX) + (gravZ * gravZ)));
   return rad * 180 / pi;
 }

 float getAngleZ(float gravX, float gravY, float gravZ) {
   float rad = atan(sqrtf((gravX * gravX) + (gravY * gravY)) / gravZ);
   return rad * 180 / pi;
 }

int main(void) {
  ret_code_t error_code = NRF_SUCCESS;

  // initialize RTT library
  error_code = NRF_LOG_INIT(NULL);
  APP_ERROR_CHECK(error_code);
  NRF_LOG_DEFAULT_BACKENDS_INIT();
  printf("Log initialized\n");

  // initialize i2c master (two wire interface)
  nrf_drv_twi_config_t i2c_config = NRF_DRV_TWI_DEFAULT_CONFIG;
  i2c_config.scl = BUCKLER_SENSORS_SCL;
  i2c_config.sda = BUCKLER_SENSORS_SDA;
  i2c_config.frequency = NRF_TWIM_FREQ_100K;
  error_code = nrf_twi_mngr_init(&twi_mngr_instance, &i2c_config);
  APP_ERROR_CHECK(error_code);

  // initialize LSM9DS1 driver
  lsm9ds1_init(&twi_mngr_instance);
  printf("lsm9ds1 initialized\n");

  lsm9ds1_start_gyro_integration();

  // initialize spi master
  nrf_drv_spi_t spi_instance = NRF_DRV_SPI_INSTANCE(1);
  nrf_drv_spi_config_t spi_config = {
    .sck_pin = BUCKLER_LCD_SCLK,
    .mosi_pin = BUCKLER_LCD_MOSI,
    .miso_pin = BUCKLER_LCD_MISO,
    .ss_pin = BUCKLER_LCD_CS,
    .irq_priority = NRFX_SPI_DEFAULT_CONFIG_IRQ_PRIORITY,
    .orc = 0,
    .frequency = NRF_DRV_SPI_FREQ_4M,
    .mode = NRF_DRV_SPI_MODE_2,
    .bit_order = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST
  };
  error_code = nrf_drv_spi_init(&spi_instance, &spi_config, NULL, NULL);
  APP_ERROR_CHECK(error_code);

  pi = 2.0f * acos(0.0f);

  // initialize display driver
  display_init(&spi_instance);
  printf("Display initialized\n");
  nrf_delay_ms(1000);

  /*char bufA0[15] = {0};
  char bufA1[17] = {0};
  char bufG0[15] = {0};
  char bufG1[17] = {0};
  char bufAngle0[17] = {0};
  char bufAngle1[17] = {0};

  float tiltAngle = 0.0f;*/

  init_SDCard();

  // Write test numbers in a loop
  while(1) {
    // get measurements
    lsm9ds1_measurement_t acc_measurement = lsm9ds1_read_accelerometer();
    lsm9ds1_measurement_t gyr_measurement = lsm9ds1_read_gyro_integration();
    lsm9ds1_measurement_t mag_measurement = lsm9ds1_read_magnetometer();

    /*snprintf(bufA0, 15, "Ax: %1.3f Ay:", acc_measurement.x_axis);
    snprintf(bufA1, 17, "%1.3f Az: %1.3f", acc_measurement.y_axis, acc_measurement.z_axis);
    snprintf(bufG0, 15, "Gx: %1.3f Gy:", gyr_measurement.x_axis);
    snprintf(bufG1, 17, "%1.3f Gz: %1.3f", gyr_measurement.x_axis, gyr_measurement.x_axis);*/
    /*tiltAngle = getAngle(acc_measurement.x_axis, acc_measurement.y_axis, acc_measurement.z_axis);

    if (tiltAngle < 45.0f) {
      snprintf(bufAngle0, 17, "Tilt Angle:");
      snprintf(bufAngle1, 17, "%f", tiltAngle);
    } else {
      snprintf(bufAngle0, 17, "!!! DANGER OF");
      snprintf(bufAngle1, 17, "OVERTURN!!!");
    }

    /*display_write(bufA0, 0);
    display_write(bufA1, 1);
    //i += 7;
    nrf_delay_ms(1000);

    display_write(bufG0, 0);
    display_write(bufG1, 1);
    //i += 7;
    nrf_delay_ms(1000);*/

    //display_write(bufAngle0, 0);
    //display_write(bufAngle1, 1);
    //i += 7;

    nrf_delay_ms(200);

    if (!gpio_read(BUCKLER_BUTTON0)) {

      timestamp = get_timestamp();

      simple_logger_log("Time,%f,,Acc,%f,%f,%f,,Gyr,%f,%f,%f,,Ang,%f,%f,%f\n",
        timestamp,
        acc_measurement.x_axis,
        acc_measurement.y_axis,
        acc_measurement.z_axis,
        gyr_measurement.x_axis,
        gyr_measurement.y_axis,
        gyr_measurement.z_axis,
        getAngleX(acc_measurement.x_axis, acc_measurement.y_axis, acc_measurement.z_axis),
        getAngleY(acc_measurement.x_axis, acc_measurement.y_axis, acc_measurement.z_axis),
        getAngleZ(acc_measurement.x_axis, acc_measurement.y_axis, acc_measurement.z_axis));

      printf("%f - Wrote line to SD card\n", timestamp);
      // Signal that lines were written
      gpio_clear(BUCKLER_LED0);
    } else {
      printf("%f - Not writing\n", timestamp);
      gpio_set(BUCKLER_LED0);
    }

    nrf_delay_ms(200);
  }
}
