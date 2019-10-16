
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
