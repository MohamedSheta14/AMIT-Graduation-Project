
#ifndef MSPI_H
#define	MSPI_H
#define master 1 
#define slave 0

#define SPI_PS_2  4
#define SPI_PS_4   0
#define SPI_PS_8   5 
#define SPI_PS_16   1
#define SPI_PS_32   6
#define SPI_PS_64  2
#define SPI_PS_128  3
#define SPI_NONE 8 

#define MOSI 5
#define MISO 6
#define SS   4
#define SCK 7

#include <xc.h> // include processor files - each processor file is guarded.  

void SPI_INIT(int Master_Slave, int PRESCALER);
char SPI_RECEIVE();
void SPI_TRANSMIT(char data);
void SPI_TRANSMIT_slave(char slaveSelect , char data);



#endif	/* XC_HEADER_TEMPLATE_H */

