//mcp3903example.ino
//Arduino example for the MCP3903
/*Extended from the Arduino Library for MCP3903 A/D Converter
 * MCP3903 Library
 * Kerry D. Wong
 * http://www.kerrywong.com, http://www.kerrywong.com/2014/05/10/mcp3903-library/, https://github.com/kerrydwong/MCP3903) * 5/2014

Modified for use for the Microsemi Future Creative Board by Yutian Ren and Michael Klopfer, Ph.D.
University of California, Irvine
2018
*/

#include "MCP3903.h"
#include <SPI.h>


MCP3903 mcp3903;  //Initialize object
SPISettings settingsA(2000000, MSBFIRST, SPI_MODE0); //settings for the SPI for the MCP3903 (either 0,0 or 1,1, according to the datasheet are compatable modes)

void setup()
{
    SPI.begin(); //Start SPI
	mcp3903.init(11, 12, 13, 10) // Setings for your Arduino's SPI pins used for interfacing(pinMOSI, pinMISO, pinSPIClock, pinCS)
    Serial.begin(9600); //printo tout on serial monitor at 9600bps
    //Set your pins in the library
    SPI.beginTransaction(settingsA); //Start SPI transaction
	mcp3903.reset(MCP3903::OSR_256); 
    mcp3903.setGain(1,MCP3903::GAIN_8);
	SPI.endTransaction(); //End SPI transaction	
}

double ch1_gain = 2.36; //Your calibration gain for Ch1- (a default value of 2.36 is used in relation to the reference voltage, this may vary)
double ch1_offset = 0; //Your calibration offset for Ch1

void loop()
{
	//example to print out the ADC value of channel 1
    Serial.print("Channel 1 ADC Value: "); //Start your line here
	SPI.beginTransaction(settingsA); //Start SPI transaction
	Serial.println(mcp3903.readADC(1) * ch1_gain , ch1_offset); //Add value then end your line
	SPI.endTransaction(); //End SPI transaction
    delay(100);  //Delay, then rerun loop
}
