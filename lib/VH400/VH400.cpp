#include "VH400.h"

VH400::VH400(int analog_pin, int pwr_pin){

	this->analog_pin = analog_pin;
	this->pwr_pin = pwr_pin;

	pinMode(this->analog_pin, INPUT);
	pinMode(this->pwr_pin, OUTPUT);
	digitalWrite(this->pwr_pin, LOW);

}

float VH400::readVoltage(){

	return analogRead(this->analog_pin);

}

double VH400::getVWC(){
	
	float V = readVoltage();

	if(V < 1.1f){
		return (10*V) - 1;
	}else if(V >= 1.1f && V < 1.3f){
		return (25*V) - 17.5;
	}else if(V >= 1.3f && V < 1.82f){
		return (48.08*V) - 47.5;
	}else if(V >= 1.82 && V < 2.2f){
		return (26.32*V) - 47.5;
	}else if(V >= 2.2f && V <= 3.0f){
		return (62.5*V) - 87.5;
	}

	else return -1;
}

double VH400::getVWC(double voltage){
	
	float V = voltage;

	if(V < 1.1f){
		return (10*V) - 1;
	}else if(V >= 1.1f && V < 1.3f){
		return (25*V) - 17.5;
	}else if(V >= 1.3f && V < 1.82f){
		return (48.08*V) - 47.5;
	}else if(V >= 1.82 && V < 2.2f){
		return (26.32*V) - 47.5;
	}else if(V >= 2.2f && V <= 3.0f){
		return (62.5*V) - 87.5;
	}

	else return -1;
}
