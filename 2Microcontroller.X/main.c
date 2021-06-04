#include <stdio.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <avr/io.h>
#include"KIT_IO.h"
#include "ALL.h"
#include "SPI.h"
#include "mLCD.h"

char data;
int main() {
    SPI_INIT(slave, SPI_PS_128);  // initialization of SPI as slave
    LEDs_init();  // initialization of led
    while (1) {
        data = SPI_RECEIVE();  // Receiving data through SPI
        if (data == 'a') {   
            LED0_TOGGLE();   
        } else if
            (data == 'b') {
            LED1_TOGGLE();
        }
        else {
        }
    }
    return 0;
}