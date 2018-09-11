/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 * @defgroup pwm_example_main main.c
 * @{
 * @ingroup pwm_example
 * 
 * @brief  PWM Example Application main file.
 *
 * This file contains the source code for a sample application using PWM.
 *
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"

APP_PWM_INSTANCE(PWM0,1);                   // Create the instance "PWM0" using TIMER1.
APP_PWM_INSTANCE(PWM1,1); 
APP_PWM_INSTANCE(PWM2,1); 
APP_PWM_INSTANCE(PWM3,1);

static volatile bool ready_flag;            // A flag indicating PWM status.

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
    ready_flag = true;
}

int main(void)
{
     
	ret_code_t err_code;
	LEDS_CONFIGURE(LEDS_MASK);
        nrf_gpio_cfg_input(13,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(14,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(15,NRF_GPIO_PIN_PULLUP);
        nrf_gpio_cfg_input(16,NRF_GPIO_PIN_PULLUP);
	uint32_t button1; 
	uint32_t button2; 
	uint32_t button3; 
        uint32_t button4; 
	
	while(true)
		{
			nrf_delay_ms(200);
			button1 = nrf_gpio_pin_read(13);
			button2 = nrf_gpio_pin_read(14);
			button3 = nrf_gpio_pin_read(15);
                        button4 = nrf_gpio_pin_read(16);
                       
		if (!button1)
		{
                        app_pwm_config_t pwm0_cfg = APP_PWM_DEFAULT_CONFIG_1CH(1000L, BSP_LED_0);
			err_code = app_pwm_init(&PWM0,&pwm0_cfg,pwm_ready_callback);
			APP_ERROR_CHECK(err_code);
			app_pwm_enable(&PWM0);	
			for (uint32_t i=100; i > 63; i--)
                        {
			while (app_pwm_channel_duty_set(&PWM0, 0, i) == NRF_ERROR_BUSY);
                        nrf_delay_ms(1000);
                        }
                }
		
		if (!button2)
		{
			app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(1000L, BSP_LED_0);
			err_code = app_pwm_init(&PWM1,&pwm1_cfg,pwm_ready_callback);
			APP_ERROR_CHECK(err_code);
			app_pwm_enable(&PWM1);	
			for (uint8_t i=100; i > 55; i--)
                        {
			while (app_pwm_channel_duty_set(&PWM1, 0, i) == NRF_ERROR_BUSY);
                        nrf_delay_ms(20);
                        }
    }
		
		if (!button3)
		{
			app_pwm_config_t pwm2_cfg = APP_PWM_DEFAULT_CONFIG_1CH(1000L, BSP_LED_0);
			err_code = app_pwm_init(&PWM2,&pwm2_cfg,pwm_ready_callback);
			APP_ERROR_CHECK(err_code);
			app_pwm_enable(&PWM2);	
			for (uint8_t i=100; i > 26; i--)
                        {
			while (app_pwm_channel_duty_set(&PWM2, 0, i) == NRF_ERROR_BUSY);
                        nrf_delay_ms(20);
                        }
    }
                if (!button4)
                {
                    app_pwm_config_t pwm0_cfg = APP_PWM_DEFAULT_CONFIG_1CH(1000L, BSP_LED_0);
			err_code = app_pwm_init(&PWM0,&pwm0_cfg,pwm_ready_callback);
			APP_ERROR_CHECK(err_code);
			app_pwm_enable(&PWM0);	
                    for (uint8_t i=26; i < 100 ; i++)
                        {
			while (app_pwm_channel_duty_set(&PWM0, 0, i) == NRF_ERROR_BUSY);
                        nrf_delay_ms(20);
                        }
                }

	}
}


/** @} */
