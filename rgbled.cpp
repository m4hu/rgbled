#include <rgbled.h>
#include <Arduino.h>
#include <inttypes.h>

#define DEBUG
rgbled::rgbled(int led_red, int led_green, int led_blue, char kind_of_led) 
{
  _led_r = led_red;		// led_red etc auf die private _led_r übergeben
  _led_b = led_blue;	// led_blue etc auf die private _led_b übergeben
  _led_g = led_green;	// led_green etc auf die private _led_g übergeben

  pinMode(_led_r, OUTPUT);
  pinMode(_led_b, OUTPUT);
  pinMode(_led_g, OUTPUT);
 
 // wenn kind_of_led der Buchstabe a, dann _kind_of_rgb auf eins setzen,
  if (kind_of_led == 'a'){
	  _kind_of_rgb = 1;
  }
  // wenn kind_of_led der Buchstabe c, dann _kind_of_rgb auf null setzen,
  else if (kind_of_led == 'c') {
	  _kind_of_rgb = 0;
  }
  
  
}

void rgbled::out(uint8_t red, uint8_t green, uint8_t blue) 
{
  
   // Ausgabe mit controlLED
    controlLED(_led_r, red);
	controlLED(_led_b, blue);
	controlLED(_led_g, green);
      
}

void rgbled::preset(uint8_t preset_number)
{
   int helligkeit = 0;
   int fade = 5;
   int i = 0;
   
   switch (preset_number)
   {
	case 1:   //red pulsierend
		
		for (i=0;i>=99; i++){
		controlLED(_led_r, helligkeit);
		helligkeit = helligkeit + fade;
		delay(25);
			if (helligkeit == 0 || helligkeit == 255)
			{
			fade = -fade;
			}
		}
		controlLED(_led_r, 0);
		break;
	case 2:   //blue pulsierend
		
		for (i=0; i>=99;  i++){
		controlLED(_led_b, helligkeit);
		helligkeit = helligkeit + fade;
		delay(25);
			if (helligkeit == 0 || helligkeit == 255)
			{
			fade = -fade;
			}
		}
		controlLED(_led_b, 0);
		break;
	case 3:   //green pulsierend
		
		for (i=0; i>=99;  i++){
		controlLED(_led_g, helligkeit);
		helligkeit = helligkeit + fade;
		delay(25);
			if (helligkeit == 0 || helligkeit == 255)
			{
			fade = -fade;
			}
		}
		controlLED(_led_g, 0);
		break;
	default:
		break;
   }
   
}


void rgbled::controlLED(int led, uint8_t value) 
{
  uint8_t pwm_value=0;
 
 // abfrage ob _kind_of_rgb == 0 oder == 1
  pwm_value = map(value, 0, 100, 0, 255);
  if (_kind_of_rgb == 0){
	  analogWrite(led, pwm_value);
  }

  else if (_kind_of_rgb == 1){
	  analogWrite(led, ~pwm_value);
  }
  
 
  // Ausgabe über analogWrite normal (mit gemeinsamer Kathode) oder komplementiert (mit gemeinsamer Anode)
  
}
