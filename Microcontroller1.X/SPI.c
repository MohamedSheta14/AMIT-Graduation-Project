#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "SPI.h"
#define F_CPU 16000000UL
#define master  1
#define slave   0
#define SPI_PS_2  4
#define SPI_PS_4  0
#define SPI_PS_8  5
#define SPI_PS_16 1
#define SPI_PS_32 6
#define SPI_PS_64 7
#define SPI_PS_128 3

void SPI_init(int MASTER_SLAVE, int PRESCALAR){
    if (MASTER_SLAVE) {
        SPCR |= (1<<MSTR);
        SPCR |= (PRESCALAR > 3) ? (PRESCALAR &(~1<<2)): PRESCALAR;
        SPSR |= (PRESCALAR > 3);
        DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);         
    }
    else{ 
        SPCR &=~(1<<MSTR);
        DDRB |= (1<<MISO);
    } 
    SPCR |= (1 << SPE);
}
    // Enable SPI    
void SPI_TRANSMIT (char data) {
    SPDR = data;
    while (!(SPSR & (1<<SPIF)));
}

void SPI_TRANSMIT_slave(char slaveSelect , char data) {
    PORTA &= ~(1<<slaveSelect);
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
    PORTA |= (1<<slaveSelect);
    
}

char SPI_RECEIVE() {
    while (!(SPSR & (1 << SPIF)));

    return SPDR;
}