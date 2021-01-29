#include"spiSelfMaster.h"

void spi_init_master (void)
{
   // pinMode(SlaveSelection, OUTPUT);
   //and Make it HIGH to prevent to start communication right away
   // Set MOSI, SCK, SS, as Output
    
    DDRB=(1<<5)|(1<<3)|(1<<2);
      //and Make it HIGH to prevent to start communication right away
    PORTB |=(1<<2);
 
    // Enable SPI, Set as Master
    // Prescaler: Fosc/16, Enable Interrupts
    //The MOSI, SCK pins are as per ATMega8

   //SPCR=(1<<SPE)|(1<<MSTR);
   SPCR=(1<<SPE)|(1<<MSTR)|(1<< SPR1)|(1<<SPR0);//declare the frequency /128
   

 // Enable Global Interrupts  
 sei();
}

//Function to send and receive data for both master and slave

unsigned char spi_tranceiver (unsigned char data)

{
    // Load data into the buffer
    SPDR = data;
 
    //Wait until transmission complete
    while(!(SPSR & (1<<7)));   // Return received data

  return(SPDR);
}
