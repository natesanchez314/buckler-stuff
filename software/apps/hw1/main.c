#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "boards.h"
#include "nrf_delay.h"
#include "nrfx_gpiote.h"

int main(void) {
  //bsp_board_init(BSP_INIT_LEDS);
  ret_code_t err = NRF_SUCCESS;

  if (!nrfx_gpiote_is_init()) {
    err = nrfx_gpiote_init();
  }
  APP_ERROR_CHECK(err);

  nrfx_gpiote_out_config_t config = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(true);
  err = nrfx_gpiote_out_init(BUCKLER_LED1, &config);
  APP_ERROR_CHECK(err);

  while (true) {
    nrf_gpio_pin_toggle(BUCKLER_LED1);
    nrf_delay_ms(500);
  }
}

#include <stdio.h>
#include <pthread.h>

int myVar = 0;

void* incVar(void* arg) {
  while (myVar < 1000000) {
    myVar++;
  }
  return NULL;
}

int main() {

  while (myVar < 1000000) {
    myVar++;
  }

  return 0;
}
