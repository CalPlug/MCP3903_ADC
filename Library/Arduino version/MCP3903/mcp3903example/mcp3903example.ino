/*
mcp3903example.ino
Arduino example for the MCP3903 - Example tested 
Extended from the Arduino Library for MCP3903 A/D Converter
 * MCP3903 Library
 * Kerry D. Wong
 * http://www.kerrywong.com, http://www.kerrywong.com/2014/05/10/mcp3903-library/, https://github.com/kerrydwong/MCP3903) * 5/2014
Modified for use for the Microsemi Future Creative Board by Yutian Ren and Michael Klopfer, Ph.D.
University of California, Irvine
2018
*/
#include <SPI.h>
#include "MCP3903.h"
//Set the gains and offsets for your ADC channels:
#define ch1_gain 1.0
#define ch1_offset 0.0
MCP3903 mymcp3903;  //Initialize object
void setup()
{
    SPI.begin(); //Start SPI
      mymcp3903.init(15); // Setings for your Arduino's SPI pins used for interfacing(pinCS)
    Serial.begin(9600); //set serial comm at 9600 bps
      mymcp3903.reset(MCP3903::OSR_256); 
    mymcp3903.setGain(1,MCP3903::GAIN_8);
}
void loop()
{
    //example to print out the ADC value of channel 1
    Serial.print("Channel 1 ADC Value: "); //Start your line here
    double Ch1 = mymcp3903.readADC(1);
    double Ch1Cal = (Ch1* ch1_gain)+ch1_offset;
      Serial.println(Ch1);//Add value then end your line
    delay(100);  //Delay, then rerun loop
}