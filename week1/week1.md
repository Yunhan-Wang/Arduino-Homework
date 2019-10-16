# Week1 homework

A game like Simon says. I made 10 levels. First, you need to press any button to start the game.


[simon says video](https://www.youtube.com/watch?v=Wuwy5Wc79yc)


![simon says picture](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week1/simon-pic1.JPG)

## This is the code.
``` arduino

int level = 1;
const int levelCount=10;
int LED[levelCount];
int selectedLED[levelCount];


int frequency = 1000;

void setup() 
{
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if (level == 1)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    randomLED();
  }

  if (digitalRead(9) == HIGH || digitalRead(10) == HIGH ||digitalRead(11) == HIGH|| level != 1) 
  {
    startGame();    
    playGame(); 
    digitalWrite(9,LOW);  
  }
}

void startGame()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  for (int i = 0; i < level; i++)
  {
    digitalWrite(LED[i], HIGH);
    delay(frequency);
    digitalWrite(LED[i], LOW);
    delay(200);
   }
}

void playGame()
{
  int flag = 0; 

  for (int i = 0; i < level; i++)
  {
    flag = 0;
    while(flag == 0)
    {
      //LED1
       if (digitalRead(9) == HIGH) 
      {
        digitalWrite(2, HIGH);
        selectedLED[i] = 2;
        flag = 1;
        delay(200);
        if (selectedLED[i] != LED[i])
        {
           wrong();
           return;
        }
        digitalWrite(2, LOW);
      }
      

  if (digitalRead(10) == HIGH)
      {
        digitalWrite(3, HIGH);
        selectedLED[i] = 3;
        flag = 1;
        delay(200);
        if (selectedLED[i] != LED[i])
        {
          wrong();
          return;
        }
        digitalWrite(3, LOW);
      }

   
       if (digitalRead(11) == HIGH)
       {
         digitalWrite(4, HIGH);
         selectedLED[i] = 4;
         flag = 1;
         delay(200);
         if (selectedLED[i] != LED[i])
         {
           wrong();
           return;
         }
        digitalWrite(4, LOW);
      }

 
    }
  }
  right();
}

void randomLED()
{
  randomSeed(millis()); 

  for (int i = 0; i < levelCount; i++)
  {
    LED[i] = random(2,5); // 2,3,4
  }
}

void wrong()
{
  for (int i = 0; i < 2; i++)
  {
    for(int a=0 ; a<3 ; a++)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      delay(100);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(100);
     
    }
    
  }
  level = 1; // restart
  frequency = 1000;
}

void right()
{
   digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(200);
  
  

  if (level < levelCount)
  {
    level++;
    frequency -= 100;
  }
  else
  {
    for (int b=0 ; b< levelCount ; b++ )
    {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      delay(100);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      delay(100);
      digitalWrite(2, LOW);
      
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      delay(20);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      delay(20);

      
    }
    level=1; 
  }
   
}   
   ```


# test
At the beginning,I misunderstood the homework requirement. But the game didn't work so well.

Press the corresponding button according to the order of LEDS lighting.
``` 
char switch_flag=0;
char key_state[3][3] = {{0,0,0}, {0,0,0},{0,0,0}};        
long time1 = 0;

void setup() {
  
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
}

void loop() {
  if( digitalRead(2) == 0 && switch_flag==0){

    switch_flag=1;
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(12,HIGH);  
    delay(1000);      
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);

  }
  if(switch_flag==1){
    if(digitalRead(2)==0||digitalRead(3)==0||digitalRead(4)==0){

      digitalWrite(8,LOW);
      digitalWrite(10,LOW);
      digitalWrite(12,LOW);
      
      for(int i=0; i<3; i++){
        time1 = millis();
        while(digitalRead(2) && digitalRead(3) && digitalRead(4)){
          if(millis() - time1 >1000){
            break;
          }
        }
        if(digitalRead(2) == 0){
          while(digitalRead(2) == 0);
          key_state[i][0] = 1;
        }
        else if(digitalRead(3) == 0){
          while(digitalRead(3) == 0);
          key_state[i][1] = 1;
        }
        else if(digitalRead(4) == 0){
          while(digitalRead(4) == 0);
          key_state[i][2] = 1;
        }
        else{
          key_state[i][0] = 0;
          key_state[i][1] = 0;
          key_state[i][2] = 0;
        }
      }
      delay(300); 
      for(int i=0; i<3; i++){
        digitalWrite( 8,key_state[i][0]);
        digitalWrite(10,key_state[i][1]);
        digitalWrite(12,key_state[i][2]);
        delay(500);
        digitalWrite( 8,!key_state[i][0]);
        digitalWrite(10,!key_state[i][1]);
        digitalWrite(12,!key_state[i][2]);
        delay(500);
      }
      digitalWrite( 8,key_state[0][0]|key_state[1][0]|key_state[2][0]);
      digitalWrite(10,key_state[0][1]|key_state[1][1]|key_state[2][1]);
      digitalWrite(12,key_state[0][2]|key_state[1][2]|key_state[2][2]);
      delay(300); 
      for(int i=0; i<3; i++){
        digitalWrite( 8,key_state[i][0]);
        digitalWrite(10,key_state[i][1]);
        digitalWrite(12,key_state[i][2]);
        delay(500);
        digitalWrite( 8,!key_state[i][0]);
        digitalWrite(10,!key_state[i][1]);
        digitalWrite(12,!key_state[i][2]);
        delay(500);
      }
      digitalWrite( 8,LOW);
      digitalWrite(10,LOW);
      digitalWrite(12,LOW);
    }


  }
  
}
```

![circult picture](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week1/tast.JPG)
![Logic diagram](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week1/IMG_0648.JPG)




