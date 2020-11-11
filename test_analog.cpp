#include <string>
#include "AnalogIn.h"
#include <iostream>
using namespace std;


float getTemperature(int adc_value) {     // from the TMP36 datasheet
	   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
	   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
	    return (25.0f + diff_degreesC);
}


int main(){  
	
	AnalogIn AIN(0);
        AIN.getNumber();
	AIN.setNumber(0);
	AIN.readADCsample();
	std::cout << "The ADC value input is: " << AIN.readADCsample() << endl;
	float temp = getTemperature(AIN.readADCsample());
	float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
	cout << "Temperature is " << temp << "°C (" << fahr << "°F)" << endl;
}

