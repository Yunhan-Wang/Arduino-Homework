int switchPin1=3;
int switchPin2=6;
int motorspeed=9;
int a=0;
void setup() {
  pinMode(switchPin1,INPUT);
  pinMode(switchPin2,INPUT);
  pinMode(motorspeed,OUTPUT);

}

void loop() {
  { if(LOW== digitalRead(switchPin1))
    {a=a+10;
    analogWrite(motorspeed,a);
    delay(100);
      
      }

    if(LOW== digitalRead(switchPin2))
    {
      
      a=a-10;
      analogWrite(motorspeed,a);
    delay(100);
      
    }
  }
}
