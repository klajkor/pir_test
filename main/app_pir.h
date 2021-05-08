/*
 * app_pir.h
 *
 *  Created on: 2021. May 8.
 *      Author: Robert Klajko
 */

#ifndef INC_APP_PIR_H_
#define INC_APP_PIR_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define GPIO_OUTPUT_IO_0    26
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


#endif /* INC_APP_PIR_H_ */