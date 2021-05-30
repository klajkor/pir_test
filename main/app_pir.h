/*
 * app_pir.h
 *
 *  Created on: 2021. May 8.
 *      Author: Robert Klajko
 */

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define GPIO_OUTPUT_IO_0    25
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0))
#define GPIO_PIR_INPUT     34
#define GPIO_INPUT_PIN_SEL  ((1ULL<<GPIO_PIR_INPUT))
#define ESP_INTR_FLAG_DEFAULT 0

//static xQueueHandle gpio_evt_queue;

//static void IRAM_ATTR pir_gpio_isr_handler(void* arg);
//static void pir_gpio_task(void* arg);
void pir_gpio_init(void);
void pir_gpio_intr_config(void);
void pir_task_init(void);

typedef struct gpio_struct_t
{
    uint32_t gpio_pin;
    int32_t gpio_level;
} gpio_struct_t;
