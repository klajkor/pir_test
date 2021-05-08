# PIR Test Example

This test code shows how to configure gpio and how to use gpio interrupt for PIR sensor.
Code is based on official ESP-IDF gpio test example.

## Framework
 * ESP-IDF + FreeRTOS

## GPIO functions:

 * GPIO26: output for LED
 * GPIO34: input, pulled down with external resistor, interrupt from rising edge and falling edge

## Test:
 * Connect LED with proper resistor (e.g. 330 ohm) to GPIO26
 * Connect PIR sensor (HC-SR501) to GPIO34
 * Also pull down GPIO34 with 10kohm resistor to GND
