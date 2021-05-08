/**
 * Brief:
 * This test code shows how to configure gpio and how to use gpio interrupt for PIR sensor.
 *
 * GPIO status:
 * GPIO26: output
 * GPIO34:  input, pulled down with external resistor, interrupt from rising edge and falling edge
 *
 * Test:
 * Connect LED with proper resistor (e.g. 330 ohm) to GPIO26
 * Connect PIR sensor (HC-SR501) to GPIO34
 * Also pull down GPIO34 with 10kohm resistor to GND
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#include "app_pir.h"

void app_main(void)
{
    pir_gpio_init();
    pir_task_init();
    pir_gpio_intr_config();
        
    // Everything is done in the PIR FreeRTOS task, pir_gpio_task().
    // See more in app_pir.c

    while(1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
