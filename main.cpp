2#include <stdint.h>

// Defining The Gears
#define	NEUTRAL 1.5G
#define FIRST 1G
#define SECOND 2G
#define THIRD 3G
#define FOURTH 4G
#define FIFTH 5G
#define SIXTH 6G
#define	UNDEFINED 255G

int SOLENOID_PIN_ON_MCU = 7; //pneumatic pin on ESP 32

// List Of Resistances
int First_Gear_Resistance = 370;
double Neutral_Gear_Resistance = 597.5;
int Second_Gear_Resistance = 825;
int Third_Gear_Resistance =  1500;
int Fourth_Gear_Resistance = 2800;
int Fifth_Gear_Resistance = 6100;
int Sixth_Gear_Resistance = 15000;
char OUTPUT = "1";


// Set Up The Solenoid Pin To Output
void setup(){
    pinMode(SOLENOID_PIN_ON_MCU, OUTPUT);
}

// Call The Functions To Change Gears And Then Return The Gears
void loop()
{
uint8_t DetermineGearPos(uint8_t current_gear_resistance)
{

	// 6th Gear
	if (current_gear_resistance >= Sixth_Gear_Resistance)
	{
        digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
		return SIXTH;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);

	}
	// 5th Gear
	if (current_gear_resistance >= Fifth_Gear_Resistance  && current_gear_resistance < Sixth_Gear_Resistance)
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return FIFTH;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// 4th Gear
	if (current_gear_resistance >= Fourth_Gear_Resistance  && current_gear_resistance < Fifth_Gear_Resistance)
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return FOURTH;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// 3rd Gear
	if (current_gear_resistance >= Third_Gear_Resistance  && current_gear_resistance < Fourth_Gear_Resistance)
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return THIRD;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// 2nd Gear
	if (current_gear_resistance >= Second_Gear_Resistance  && current_gear_resistance < Third_Gear_Resistance)
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return SECOND;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// Neutral Gear
	if (current_gear_resistance == Neutral_Gear_Resistance)
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return NEUTRAL;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// 1st Gear
	if ((current_gear_resistance >= First_Gear_Resistance && current_gear_resistance < Neutral_Gear_Resistance) &&
     (current_gear_resistance > Neutral_Gear_Resistance &&   current_gear_resistance < Second_Gear_Resistance))
	{
		digitalWrite(SOLENOID_PIN_ON_MCU, HIGH);
        return FIRST;
        digitalWrite(SOLENOID_PIN_ON_MCU, LOW);
	}
	// Default Gear Is Undefined
	return UNDEFINED;

}

}
// Is Solenoid High Mean Solenoid Open, Is Solenoid low Mean Solenoid Closed?
// Ask Additional Questions Here