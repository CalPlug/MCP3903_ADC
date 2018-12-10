//mcp3903example.c
//Sample components for C based Example

//Initialize MCP3903 Communication
MCP3903ResetOSR(OSR_256, &g_core_spi0);   //MCP3903 Send with OSR256 (oversampling ratio) constant (value of 0x3, see library), changing this can change output value formatting for signed values, be careful, these may not work with current signed-bit read structure!  OSR_256 known working, it look like it's sign bit, but gets shifted over as OSR decreases
MCP3903SetGain(1, GAIN_1, &g_core_spi0);   //MCP3903 Set ADC channel 1 with gain of 1 (gain of 8 is value of 0x3, see library)
			
double ch1_gain = 2.36; //(a default value of 2.36 is used in relation to the reference voltage)
double ch1_offset = 0;

printf("ADC Value for Ch 1: %f \n", (((MCP3903ReadADC(1, &g_core_spi0)*ch1_gain) + ch1_offset)));  //Periodically read out ADC value, use printf versus iprintf because of floating point values,use linker flag (--specs=rdimon.specs -u_printf_float for MicroSemi SmartFusion2)

	}
	return 0;
	}