/*
 * app_pir.c
 *
 *  Created on: 2021. May 8.
 *      Author: Robert Klajko
 */

#include "app_pir.h"

static xQueueHandle gpio_evt_queue = NULL;

static void IRAM_ATTR pir_gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void pir_gpio_task(void* arg)
{
    uint32_t pir_input_pin;
    int pir_input_level;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &pir_input_pin, portMAX_DELAY)) {
            pir_input_level=gpio_get_level(pir_input_pin);
            printf("GPIO[%d] intr, val: %d\n", pir_input_pin, pir_input_level);
            gpio_set_level(GPIO_OUTPUT_IO_0, pir_input_level);
        }
    }
}

void pir_gpio_init(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_POSEDGE;
    //bit mask of the pins, use GPIO4/5 here
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}

void pir_gpio_intr_config(void)
{
    //change gpio intrrupt type for one pin
    gpio_set_intr_type(GPIO_PIR_INPUT, GPIO_INTR_ANYEDGE);
    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(GPIO_PIR_INPUT, pir_gpio_isr_handler, (void*) GPIO_PIR_INPUT);
}

void pir_task_init(void)
{
    //create a queue to handle gpio event from isr
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    //start gpio task
    xTaskCreate(pir_gpio_task, "pir_gpio_task", 2048, NULL, 10, NULL);
}
