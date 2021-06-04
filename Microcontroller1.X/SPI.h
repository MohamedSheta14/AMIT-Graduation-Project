/* 
 * File:   SPI.h
 * Author: pc
 *
 * Created on May 7, 2021, 12:59 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

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

#define MOSI   5
#define MISO   6
#define SCK    7
#define SS     4
    

void SPI_init(int MASTER_SLAVE, int PRESCALAR);
void SPI_TRANSMIT (char data);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

