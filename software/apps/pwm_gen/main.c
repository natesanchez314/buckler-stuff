
#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"
#include "nrfx_gpiote.h"

void timer_init() {
  NRF_TIMER4->PRESCALER = 0x04;
  NRF_TIMER4->MODE = 0x0;
  NRF_TIMER4->BITMODE = 0x2;

  NRF_TIMER2->PRESCALER = 0x04;
  NRF_TIMER2->MODE = 0x0;
  NRF_TIMER2->BITMODE = 0x2;

  NRF_TIMER3->MODE = 0x01;
  NRF_TIMER3->BITMODE = 0x1;

  NRF_TIMER3->CC[2] = 100;

  NRF_TIMER4->TASKS_CLEAR = 0x01;
  NRF_TIMER4->TASKS_START = 0x01;
  NRF_TIMER3->TASKS_START = 0x01;
  NRF_TIMER2->TASKS_CLEAR = 0x01;
}

uint32_t read_timer4() {
  NRF_TIMER4->TASKS_CAPTURE[1] = 1;
  return NRF_TIMER4->CC[1];
}

uint32_t read_timer2() {
  NRF_TIMER2->TASKS_CAPTURE[1] = 1;
  return NRF_TIMER2->CC[1];
}

uint32_t read_counter() {
  NRF_TIMER3->TASKS_CAPTURE[1] = 1;
  return NRF_TIMER3->CC[1];
}

void myHandler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {
  if (pin == 18) {
    if (nrf_gpio_pin_read(18) == 1) {
      NRF_TIMER2->TASKS_START = 0x1;
      NRF_TIMER3->TASKS_COUNT = 0x1;
    } else {
      NRF_TIMER2->TASKS_STOP = 0x1;
    }
  }
}

void calculate_freq_and_duty_cycle() {
  NRF_TIMER4->TASKS_STOP = 0x1;
  NRF_TIMER2->TASKS_STOP = 0x1;
  uint32_t timeHigh = read_timer2();
  uint32_t totalTime = read_timer4();
  uint32_t count = read_counter();



  float timePeriod = (float)totalTime / (float)count;
  float frequency = 1.0f / timePeriod;
  frequency /= 2.0f;
  float duty_cycle = (float)timeHigh / (float)totalTime;

  duty_cycle *= 100;

  printf("Frequency: %f microseconds\n", frequency);
  nrf_delay_ms(25);
  printf("Frequency: %f hz\n", frequency * 1000000.0f);
  nrf_delay_ms(25);
  printf("Duty cycle:%2.3f%%\n", duty_cycle);

}

nrfx_gpiote_evt_handler_t gpiote_handler = myHandler;

APP_PWM_INSTANCE(PWM1, 1);

int main(void) {
  // Input pin
  nrfx_gpiote_init();
  nrfx_gpiote_in_config_t in_config;
  in_config.sense = NRF_GPIOTE_POLARITY_TOGGLE;
  in_config.pull = NRF_GPIO_PIN_NOPULL;
  in_config.is_watcher = false;
  in_config.skip_gpio_setup = false;

  nrfx_gpiote_in_init(
    18,
    &in_config,
    myHandler);

  nrfx_gpiote_in_event_enable(18, true);

  // PWM stuff
  ret_code_t err_code;
  app_pwm_config_t config_pwm = APP_PWM_DEFAULT_CONFIG_1CH(400, 11);
  err_code = app_pwm_init(
    &PWM1,
    &config_pwm,
    NULL);

  APP_ERROR_CHECK(err_code);
  app_pwm_enable(&PWM1);
  err_code = app_pwm_channel_duty_set(
    &PWM1,
    0,
    50);

  timer_init();

  while (read_timer4() < 5000000) {
    __WFI();
    nrf_delay_ms(25);
  }

  calculate_freq_and_duty_cycle();
}
