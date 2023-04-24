#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"

// Create the instance "PWM1" using TIMER1.
APP_PWM_INSTANCE(PWM1, 1);

int main(void)
{
    ret_code_t err_code;

    /* 2-channel PWM, 200Hz, output on Buckler LED pins. */
    app_pwm_config_t config_pwm = APP_PWM_DEFAULT_CONFIG_2CH(5000, 25, 24);

    /* Switch the polarity of the second channel. */
    config_pwm.pin_polarity[1] = APP_PWM_POLARITY_ACTIVE_HIGH;

    /* Initialize PWM. */
    err_code = app_pwm_init(
      &PWM1,
      &config_pwm,
      NULL
    );
    APP_ERROR_CHECK(err_code);
    /* Enable PWM. */
    app_pwm_enable(&PWM1);

    uint32_t value = 0;
    while (value <= 100)
    {
      /* Your code for modifying the duty cycle value */
      err_code = app_pwm_channel_duty_set(
        &PWM1,
        0,
        value);
      err_code = app_pwm_channel_duty_set(
        &PWM1,
        1,
        value);
      APP_ERROR_CHECK(err_code);
      value += 1;
      nrf_delay_ms(25);
    }
}
