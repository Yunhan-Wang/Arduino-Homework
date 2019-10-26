
# week 04- Homework

## Lab 2 - Hook up a serve

### We shot video during the test.
[video]（https://www.youtube.com/watch?v=vLa5kDIXVlY）

We did more test by changing the angle.

### also picture
![picture](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab2/lab2-pic.JPG)

## Lab 3 = Hook up a motor

### Use one button 
Use a button to control the motor

[video](https://youtu.be/Dcgj1qJ0zxI)

### some pictures
![Required parts]（https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab3/IMG_2574.JPG）
![circuit](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab3/IMG_0081.JPG)

### Use two buttons

### Use two buttons to increase or decrease the rotational speed of the motor.

### We shot video during the test.

[video](https://youtu.be/cvXaumNCuzw)

### picture
![circuit](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab3/IMG_9543.JPG)

### code
```
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
```

## Lab 4 - Hook up an MPR121

### pictures

！[circuit](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab4/IMG_5840.JPG)
![text](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab4/IMG_6653.HEIC)
![Comment  "return" line to activate that mode](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab4/IMG_7021.JPG)

### video
[](https://www.youtube.com/watch?v=MO5HFnMI1N8)


## Lab 5 - make a sensor

### picture

![](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/week4/lab5/IMG_5085.JPG)

### video
[](https://youtu.be/nca0cxSPlDI)

### we added a led.
[](https://youtu.be/nD59btzgHxk)