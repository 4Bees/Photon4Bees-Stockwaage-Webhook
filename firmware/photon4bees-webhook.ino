// This #include statement was automatically added by the Particle IDE.
#include "application.h" //Notwendig damit die externe RGB-LED schon beim Booten leuchtet!
#include "HX711.h"

#define DOUT  A0
#define CLK  A1

HX711 scale(DOUT, CLK);

String str_scalefactor = "";
String str_offset = "";

float offset = 0;
float scalefactor = 1;

float floatGewicht = 0;
String  stringGewicht = "";


void setup() {
  // put your setup code here, to run once:
  // Begin serial communication
    Serial.begin(115200);

    // Listen for the webhook response, and call gotWeatherData()
    Particle.subscribe("hook-response/get_scalefactor", gotScalefactor, MY_DEVICES);
    Particle.subscribe("hook-response/get_offset", gotOffset, MY_DEVICES);

    // Give ourselves 10 seconds before we actually start the
    // program.  This will open the serial monitor before
    // the program sends the request
    for(int i=0;i<10;i++) {
        Serial.println("waiting " + String(10-i) + " seconds before we publish");
        delay(1000);
    }

    // publish the event that will trigger our Webhook
    Particle.publish("get_scalefactor");
    delay(1000);
    Particle.publish("get_offset");
    delay(5000);
    scalefactor = str_scalefactor.toFloat();
    offset = str_offset.toFloat();

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

    Serial.print("Scalefactor: ");
    Serial.println(str_scalefactor);
    Serial.print("Offset: ");
    Serial.println(str_offset);
    delay(10000);

    scale.power_up();
    //scale.get_units(10) returns the medium of 10 measures
    floatGewicht = (scale.get_units(10) - offset);
    stringGewicht =  String(floatGewicht, 2);

    Particle.publish("cloud4bees", JSON(), PRIVATE); // Send JSON Particle Cloud

    scale.power_down();



}

// This function will get called when scalefactor comes in
void gotScalefactor(const char *name, const char *data) {
    str_scalefactor = String(data);
}

// This function will get called when offset comes in
void gotOffset(const char *name, const char *data) {
    str_offset = String(data);
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
