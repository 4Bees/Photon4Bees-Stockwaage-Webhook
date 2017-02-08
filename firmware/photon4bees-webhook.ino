// This #include statement was automatically added by the Particle IDE.
#include "application.h" //Notwendig damit die externe RGB-LED schon beim Booten leuchtet!
#include "HX711.h"

#define DOUT  A0
#define CLK  A1

HX711 scale(DOUT, CLK);

float offset = 276.9;
float scalefactor = 31679.0;

float floatGewicht = 0;
String  stringGewicht = "";


void setup() {
  // put your setup code here, to run once:
  scale.set_scale(scalefactor);                      //this value is obtained by calibrating the scale with known weights;
                                                 /*   How to Calibrate Your Scale
                                                      1.Call set_scale() with no parameter.
                                                      2.Call set_tare() with no parameter.
                                                      3.Place a known weight on the scale and call get_units(10).
                                                      4.Divide the result in step 3 to your known weight. You should get about the parameter you need to pass to set_scale.
                                                      5.Adjust the parameter in step 4 until you get an accurate reading.
                                                  */

}

void loop() {


  scale.power_up();
  //scale.get_units(10) returns the medium of 10 measures
  floatGewicht = (scale.get_units(10) - offset);
  stringGewicht =  String(floatGewicht, 2);

  Particle.publish("cloud4bees", JSON(), PRIVATE); // Send JSON Particle Cloud

  scale.power_down();



}


String JSON() {
 String ret = "&field1=";
  ret.concat(stringGewicht);
  /*ret.concat("&field2=");
  ret.concat(20);
  ret.concat("&field3=");
  ret.concat(30);
  */
  return ret;
}
