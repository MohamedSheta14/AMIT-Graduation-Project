#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include "ALL.h"
#include "mUArT.h"
#include "SPI.h"
#include "mLCD.h"

char data;
int main(){
    UART_init(9600); // UART initialization
    SPI_init(master,SPI_PS_128); // SPI initialization as master
    while (1) {
        data = UART_receive();  // Recieving the data through UART
        SPI_TRANSMIT(data);   // Transmitting data through SPI
        }
    return 0;
}