#ifndef rgbled_h
#define rgbled_h

#include <inttypes.h>

// Simple class that defines a rgb led 


class rgbled 
{
 public:
   rgbled(int led_red, int led_green, int led_blue, char kind_of_led); // initialized with Pins
   void out(uint8_t red, uint8_t green, uint8_t blue);
   void preset(uint8_t preset_number); 

 private:
   int _led_r; // LED representing red
   int _led_g; // LED representing green
   int _led_b; // LED representing blue
   char _kind_of_rgb;
   void controlLED(int led, uint8_t value); // internal method to turn LED on/off
};
#endif
