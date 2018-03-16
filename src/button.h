#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button{
  public:
  static String defaultName;
  Button(int pin, bool defaultState,String name=defaultName):
          pin(pin),prevPressedState(0),defaultState(defaultState),name(name){
    String nS=defaultName.substring(1);
    int n=nS.toInt()+1;
    defaultName=String("b")+n;
  };

  /**
   * Return the simple actual value, the digital voltage level 
   */
  bool getState() const{
    return digitalRead(pin);
  }

  /**
   * Get the button name 
   */
  String getName() const{
    return name;
  }

  /**
   * Return is the button is pressed
   */
  bool isPressed() const {
    return digitalRead(pin) != defaultState;
  }

  /**
   * This function return true if the state is changed from the last reading.
   * The direction parameter is optional. If a variable is passed: 
   *  true  = not pressed --> pressed
   *  false = pressed --> not pressed
   */
  bool isChanged(bool *direction=nullptr){
    bool actualState=isPressed();
    bool result = actualState != prevPressedState;
    
    if(result && direction!=nullptr){
      if(!prevPressedState && actualState){
        *direction=true;
      }else{
        *direction=false;
      }
    }
    prevPressedState = actualState;
    return result;
  }
  
  private:
  int pin;
  bool prevPressedState;
  bool defaultState;
  String name;
};

#endif