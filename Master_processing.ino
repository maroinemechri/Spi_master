
//SPI Master Device
//We need to import SPI.h library first 

#include"spiSelfMaster.h"
char SlaveSelection=10;
int count = 0;
void setup()


{
  
  //Set SlaveSelection pin as output.
//initialise spi protocol
   spi_init_master ();
  //Start the SPI communication.

  Serial.begin(9600);
}
 
void loop()
{
char  tab[6]="1234";
    for(int count=0; count<5; count++){
    Serial.println((char  )tab[count]);
    sendSerialData(tab[count] , SlaveSelection);
      delay(2000);
    }
    delay(500);
    Serial.println("/////////");
}
 
void sendSerialData(char data, int SlaveSelection)
{
  //Enable slave arduino with setting the SlaveSelection pin to 0Volt
  digitalWrite(SlaveSelection, LOW);
  // Wait for a moment 
  delay(10);
  //We sent the data here and wait for the response from device
  
  //send with register code
  //Serial.println(data);
  unsigned char receivedValue= spi_tranceiver ( data);   
  //And then write the answer to the serial port
  //Disable slave arduino with setting the SlaveSelection pin to 5Volt
  digitalWrite(SlaveSelection, HIGH);
}
