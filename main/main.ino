
#include <Keyboard.h>

int Press_State [6] = {0,0,0,0,0,0};

//引脚定义
int Air_Pin     [6] = {9,10,18,19,20,21};
int Air_Key      [] = {4,5,6,7,8,9};
int Air_Switch      = 4;
//判定阈值
int linmindu = 200;

void setup()
{
  int Air_Pin_Init = 0;   //pin air引脚为input
  while(Air_Pin_Init <= 5){
      pinMode(Air_Pin[Air_Pin_Init], INPUT); 
      Air_Pin_Init++;
  };

  pinMode(4, INPUT);

  Keyboard.begin(); //Init keyboard emulation
  Serial.begin(9600);

}

void loop()
{
  if (digitalRead(Air_Switch) == 1){
    air(1);
    air(2);
    air(3);
    air(4);
    air(5);
    air(6);
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