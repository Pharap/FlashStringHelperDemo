#include <Arduboy2.h>

#include "FlashStringHelper.h"

//
// Data
//

// Each string should exist on its own as a char array in progmem.
// Note that these are all implicitly null-terminated.
const char string0[] PROGMEM = "Zero";
const char string1[] PROGMEM = "One";
const char string2[] PROGMEM = "Two";
const char string3[] PROGMEM = "Three";
const char string4[] PROGMEM = "Four";
const char string5[] PROGMEM = "Five";
const char string6[] PROGMEM = "Six";
const char string7[] PROGMEM = "Seven";
const char string8[] PROGMEM = "Eight";
const char string9[] PROGMEM = "Nine";
const char string10[] PROGMEM = "Ten";

// Then there should be an array  holding pointers to each of those char arrays.
// Note the type 'const char * const', this is important.
const char * const strings[] PROGMEM
{
	string0,
	string1,
	string2,
	string3,
	string4,
	string5,
	string6,
	string7,
	string8,
	string9,
	string10,
};

// An example of a lone string for the sake of demonstration.
const char exampleString[] PROGMEM = "Example";

//
// Usage
//

Arduboy2 arduboy;

// Index variable for the sake of demonstration
uint8_t stringIndex = 3;

void setup()
{
	arduboy.begin();
}

void loop()
{
	if(!arduboy.nextFrame())
		return;
		
	arduboy.pollButtons();
	
	if(arduboy.justPressed(UP_BUTTON))
	{
		if(stringIndex > 0)
			--stringIndex;
	}
	
	if(arduboy.justPressed(DOWN_BUTTON))
	{
		if(stringIndex < 10)
			++stringIndex;
	}
	
	arduboy.clear();
	
	// `asFlashStringHelper` converts a char array into a printable format.
	// Specifically it converts it to `const __FlashStringHelper *`,
	// a dummy type used by Arduino's `Print` class to recognise a string in progmem.
	arduboy.println(asFlashStringHelper(exampleString));
	
	// Print a blank line
	arduboy.println();
	
	// `readFlashStringPointer` reads the pointer out of the array,
	// and then converts it to `const __FlashStringHelper *`.
	arduboy.println(readFlashStringPointer(&strings[stringIndex]));
	
	arduboy.display();
}
