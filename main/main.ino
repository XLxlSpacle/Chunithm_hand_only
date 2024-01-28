
#include <Keyboard.h>
int ir1 = 9;   // Set a button to any pin
int ir2 = 10;  // Set a button to any pin
int ir3 = 18;  // Set a button to any pin
int ir4 = 19;  // Set a button to any pin
int ir5 = 20;  // Set a button to any pin
int ir6 = 21;  // Set a button to any pin
int linmindu = 200;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
int p5 = 0;
int p6 = 0;

void setup()
{
  pinMode(ir1, INPUT);  // Set the button as an input
  pinMode(ir2, INPUT);  // Set the button as an input
  pinMode(ir3, INPUT);  // Set the button as an input
  pinMode(ir4, INPUT);  // Set the button as an input
  pinMode(ir5, INPUT);  // Set the button as an input
  pinMode(ir6, INPUT);  // Set the button as an input

  Keyboard.begin(); //Init keyboard emulation
  Serial.begin(9600);

}

void loop()
{
  iir1();
  iir2();
  iir3();
  iir4();
  iir5();
  iir6();
}

void iir1(){
    int val = analogRead(ir1);
  if (val < linmindu)
  {
    if (p1 == 0){
      // Keyboard.press('6');
      // Keyboard.press('7'); 
      // Keyboard.press('8');  
      // Keyboard.press('9');
      // Keyboard.press('5');
      Keyboard.press('4');
      p1 = 1;
    }
  }else if (val > linmindu)
  {
      if (p1 == 1){
      // Keyboard.release('6'); 
      // Keyboard.release('7'); 
      // Keyboard.release('8'); 
      // Keyboard.release('9'); 
      // Keyboard.release('5');  
      Keyboard.release('4');  
      p1 = 0;
    }
  }
  // Serial.println(val);
}


void iir2(){
    int val = analogRead(ir2);
  if (val < linmindu)
  {
    if (p2 == 0){
    // Keyboard.press('6');
    // Keyboard.press('7'); 
    // Keyboard.press('8');  
    // Keyboard.press('9');
    Keyboard.press('5');
    // Keyboard.press('4');
      p2 = 1;
    }

  }else if (val > linmindu)
  {
      if (p2 == 1){
    // Keyboard.release('6'); 
    // Keyboard.release('7'); 
    // Keyboard.release('8'); 
    // Keyboard.release('9'); 
    Keyboard.release('5');  
    // Keyboard.release('4');  
      p2 = 0;
    }
  }
  // Serial.println(val);
}


void iir3(){
    int val = analogRead(ir3);
   if (val < linmindu)
  {
    if (p3 == 0){
    Keyboard.press('6');
    // Keyboard.press('7'); 
    // Keyboard.press('8');  
    // Keyboard.press('9');
    // Keyboard.press('5');
    // Keyboard.press('4');
      p3 = 1;
    }

  }else if (val > linmindu)
  {
      if (p3 == 1){
    Keyboard.release('6'); 
    // Keyboard.release('7'); 
    // Keyboard.release('8'); 
    // Keyboard.release('9'); 
    // Keyboard.release('5');  
    // Keyboard.release('4');  
      p3 = 0;
    }
  }
  // Serial.println(val);
}


void iir4(){
    int val = analogRead(ir4);
   if (val < linmindu)
  {
    if (p4 == 0){
    // Keyboard.press('6');
    Keyboard.press('7'); 
    // Keyboard.press('8');  
    // Keyboard.press('9');
    // Keyboard.press('5');
    // Keyboard.press('4');
      p4 = 1;
    }

  }else if (val > linmindu)
  {
      if (p4 == 1){
    // Keyboard.release('6'); 
    Keyboard.release('7'); 
    // Keyboard.release('8'); 
    // Keyboard.release('9'); 
    // Keyboard.release('5');  
    // Keyboard.release('4');  
      p4 = 0;
    }
  }
  // Serial.println(val);
}


void iir5(){
    int val = analogRead(ir5);
   if (val < linmindu)
  {
    if (p5 == 0){
    // Keyboard.press('6');
    // Keyboard.press('7'); 
    Keyboard.press('8');  
    // Keyboard.press('9');
    // Keyboard.press('5');
    // Keyboard.press('4');
      p5 = 1;
    }

  }else if (val > linmindu)
  {
      if (p5 == 1){
    // Keyboard.release('6'); 
    // Keyboard.release('7'); 
    Keyboard.release('8'); 
    // Keyboard.release('9'); 
    // Keyboard.release('5');  
    // Keyboard.release('4');  
      p5 = 0;
    }
  }
  // Serial.println(val);
}


void iir6(){
    int val = analogRead(ir6);
   if (val < linmindu)
  {
    if (p6 == 0){
    // Keyboard.press('6');
    // Keyboard.press('7'); 
    // Keyboard.press('8');  
    Keyboard.press('9');
    // Keyboard.press('5');
    // Keyboard.press('4');
      p6 = 1;
    }

  }else if (val > linmindu)
  {
      if (p6 == 1){
    // Keyboard.release('6'); 
    // Keyboard.release('7'); 
    // Keyboard.release('8'); 
    Keyboard.release('9'); 
    // Keyboard.release('5');  
    // Keyboard.release('4');  
      p6 = 0;
    }
  }
  // Serial.println(val);
}