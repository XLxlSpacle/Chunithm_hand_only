
#include <Keyboard.h>

int Press_State [6] = {0,0,0,0,0,0};

//引脚定义
int Air_Pin     [6] = {9,10,18,19,20,21};
int Air_Key      [] = {4,5,6,7,8,9};
int Air_Switch      = 5;
int Button_Pin      = 8;
//判定阈值
int linmindu = 200;

void setup()
{
  int Air_Pin_Init = 0;   //pin air引脚为input
  while(Air_Pin_Init <= 5){
      pinMode(Air_Pin[Air_Pin_Init], INPUT); 
      Air_Pin_Init++;
  };

  pinMode(Air_Switch, INPUT);
  pinMode(Button_Pin, INPUT);

  Keyboard.begin(); //Init keyboard emulation
  Serial.begin(9600);

}

void loop()
{
  Button();

  if (digitalRead(Air_Switch) == 1){      //air部分
    air(1);
    air(2);
    air(3);
    air(4);
    air(5);
    air(6);
  }
}

//按钮部分
void Button(){

  if(analogRead(Button_Pin) > 200){
    if(analogRead(Button_Pin) > 300){
      if(analogRead(Button_Pin) > 400){
        if(analogRead(Button_Pin) > 500){
          if(analogRead(Button_Pin) > 600){
            if(analogRead(Button_Pin) > 700){
              if(analogRead(Button_Pin) > 820){
                if(analogRead(Button_Pin) > 999){
                    Keyboard.press(0x33);
                    delay(250);
                    Keyboard.release(0x33);
                }else{
                    Keyboard.press(KEY_RETURN);
                    delay(250);
                    Keyboard.release(KEY_RETURN);
                }
              }else{
                    Keyboard.press(0x31);
                    delay(250);
                    Keyboard.release(0x31);

              }
            }
          }
        }
      }
    }
  }

}

//检测输出air部分
bool air(int number){
  number--;   //将传入的编号减一，方便看
  char key = (char)(Air_Key[number] + '0');   //转换int为char（keybord.press/release只能char）
  if       (analogRead(Air_Pin[number]) < linmindu)   //与阈值对比
  {
    if (Press_State[number] == 0){      //检测是否已经被按下，避免持续输出
      Keyboard.press(key);            //按下
      Press_State[number] = 1;      //设置已按下状态值1
      return true;
    }
  }else if (analogRead(Air_Pin[number]) > linmindu)
  {
      if (Press_State[number] == 1){
      Keyboard.release(key);      //释放
      Press_State[number] = 0;    //初始化状态值
      return false;
    }
  }
}