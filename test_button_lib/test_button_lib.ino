#include "button.h"

Button button(D6,1,"My Button");

void setup() {
  Serial.begin(115200);
  while(!Serial);

  Serial.println("Booting...");
  pinMode(D6,INPUT_PULLUP);

}

void loop() {
  Serial.print(String("Is phy state: ") + button.getState() + 
                        " Is pressed: " + button.isPressed());
  bool dir=0;
  bool res = button.isChanged(&dir);
  Serial.print(String(" Is changed: ") + (bool)res );
  if(res){
    Serial.print(String(" Pressed: ") + (bool)dir);
  }
  Serial.println();
  
  
  delay(100);
}
