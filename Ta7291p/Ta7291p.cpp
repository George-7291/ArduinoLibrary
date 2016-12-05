#include "Ta7291p.h"

Ta7291p::Ta7291p(int pin4, int pin5, int pin6){
	this->pin4 = pin4;
	this->pin5 = pin5;
	this->pin6 = pin6;
	Ta7291p();
}

Ta7291p::Ta7291p(void){
	this->pwm = 0;
	this->brake = false;
	pinMode(pin5,OUTPUT);
	pinMode(pin6,OUTPUT);
}

Ta7291p::~Ta7291p(void){
}

void Ta7291p::commitPwm(int pwm){
	this->pwm = pwm;
	if(this->pwm > 0 && this->pwm < 256){
		digitalWrite(this->pin5,HIGH);
		digitalWrite(this->pin6,LOW);
		analogWrite(this->pin4,this->pwm);
	}
	else if(this->pwm < 0 && this->pwm > -256){
		digitalWrite(this->pin5,LOW);
		digitalWrite(this->pin6,HIGH);
		analogWrite(this->pin4,this->pwm * -1);
	}
	else if(this->pwm == 0){
		digitalWrite(this->pin5,LOW);
		digitalWrite(this->pin6,LOW);
		analogWrite(this->pin4,this->pwm);
	}
	else{
		this->pwm = 0;
		digitalWrite(this->pin5,LOW);
		digitalWrite(this->pin6,LOW);
		analogWrite(this->pin4,this->pwm);
	}
}

void Ta7291p::applyBrake(bool brake){
	this->brake = brake;
	if(this->brake){
		digitalWrite(this->pin5,HIGH);
		digitalWrite(this->pin6,HIGH);
		analogWrite(this->pin4, 0);
	}
	else{
		this->commitPwm(this->pwm);
	}
}

int Ta7291p::fetchPwm(void){
	return this->pwm;
}

bool Ta7291p::isBraked(void){
	return this->brake;
}