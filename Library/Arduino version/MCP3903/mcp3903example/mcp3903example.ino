/*
mcp3903example.ino
Arduino example for the MCP3903 - Example tested 
Extended from the Arduino Library for MCP3903 A/D Converter
 * MCP3903 Library
 * Kerry D. Wong
 * http://www.kerrywong.com, http://www.kerrywong.com/2014/05/10/mcp3903-library/, https://github.com/kerrydwong/MCP3903) * 5/2014
Minor Arduino Feature extensions by Zhi Luo, Kaixin Chen, Yaxin "Erica" Deng, Yutian Ren, and Michael Klopfer, Ph.D.
University of California, Irvine
2018
*/

#include <SPI.h>
#include "MCP3903.h"


//Set the gains and offsets for your ADC channels:
#define ch0_gain 2.383490972 //these are values for calibration. By setting these values, reads will be the same as the inputs. 
#define ch0_offset -0.007884781 //the maximum read for each channel will be around 0.7866. The deviation for these values is around 2%

#define ch1_gain 2.383490972
#define ch1_offset -0.007884781

#define ch2_gain 2.383490972
#define ch2_offset -0.007884781

#define ch3_gain 2.383490972
#define ch3_offset -0.007884781

#define ch4_gain 2.383490972
#define ch4_offset -0.007884781

#define ch5_gain 2.383490972
#define ch5_offset -0.007884781


MCP3903 mymcp3903;  //Initialize mymcp3903 object for the MCP3903 

void setup()
{
    //esp.begin(); Needed with ESP8266 for ESP class functions
  Serial.begin(9600); //set serial comm at 9600 bps
  SPI.begin(); //Start SPI
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));  //Start SPI transaction with defined parameters 
        mymcp3903.init(10); // (10 for UNO; 15 for esp8266)Setings for your Arduino's/ESP8266's SPI pin used for interfacing(pinCS) - make sure this is the pin you have your CS on!
        mymcp3903.reset(MCP3903::OSR_256); 
        mymcp3903.setGain(1,MCP3903::GAIN_8);
  //Need to initialize all channels to use
  SPI.endTransaction(); //End SPI transaction

}


void loop()
{
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));  //Start SPI transaction with defined parameters 

    
  //Print out the ADC value of channel 0
  Serial.print("Channel 0 ADC Value: "); //Start your line here
    double ch0 = mymcp3903.readADC(0);
    double ch0Cal = (ch0* ch0_gain)+ch0_offset;
    Serial.println(ch0Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  
  //Print out the ADC value of channel 1
    Serial.print("Channel 1 ADC Value: "); //Start your line here
    double ch1 = mymcp3903.readADC(1);
    double ch1Cal = (ch1* ch1_gain)+ch1_offset;
    Serial.println(ch1Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  
  //Print out the ADC value of channel 2
    Serial.print("Channel 2 ADC Value: "); //Start your line here
    double ch2 = mymcp3903.readADC(2);
    double ch2Cal = (ch2* ch2_gain)+ch2_offset;
    Serial.println(ch2Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  //Print out the ADC value of channel 3
  Serial.print("Channel 3 ADC Value: "); //Start your line here
    double ch3 = mymcp3903.readADC(3);
    double ch3Cal = (ch3* ch3_gain)+ch3_offset;
    Serial.println(ch3Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  //Print out the ADC value of channel 4
  Serial.print("Channel 4 ADC Value: "); //Start your line here
    double ch4 = mymcp3903.readADC(4);
    double ch4Cal = (ch4* ch4_gain)+ch4_offset;
    Serial.println(ch4Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  //Print out the ADC value of channel 5
  Serial.print("Channel 5 ADC Value: "); //Start your line here
    double ch5 = mymcp3903.readADC(5);
    double ch5Cal = (ch5* ch5_gain)+ch5_offset;
    Serial.println(ch5Cal);//Add value then end your line
  delay(10);  //Delay before next Ch read (totally optional)
  
  
  
    delay(100);  //Delay, then re-run loop to read sensors again
  //SPI.endTransaction(); //End SPI transaction - we are keeping this open for this example
}
