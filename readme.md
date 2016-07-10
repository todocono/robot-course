## Intro
This is a short course about robotics, designed to have in about 10 sessions an outcome of team members building robots and experimenting with different setups.

It has been used both in at least four countries in several iterations. It is, of course, far from perfect. But it is something, at least, that tries to give a comprehensive view to beginners about what robots really are and how to create them.

Please help to improve it and it's code by placing an issue on the master branch. You are also welcome to ask for a Pull Request @todocono.


## Content
  1. Team Building - Activity
  2. Robotics - Intro
  3. Mechanics Basics
  4. Electronics Basics
  5. Maze Solving - Activity
  6. Software Basics
  7. Sensors
  8. Telecommunication
  9. Analog signals
  10. Chain Reaction - Activity
  11. Learning Outcomes
  10. Authors & Contributors

## 0. Instructions for the instructions
This set of instructions go hand in hand with the set of code examples hosted at http://github.com/todocono/robot-course.

The mechanical kit can be purchased at http://multiplo.org and the electronics are based on Arduino UNO & L298N.

It is a good strategy to establish rules about how to use the materials at the beginning. For example, the instructor will only have one rule to ask for the attention of the students. Stating a clear set of expectations always help to focus the group.

## 1. Team Building - Activity

Any activity would do it. Here is a suggestion of one that it is my favorite.

      1. Receive instructions.

      2. Team up, groups of at least 3 people.

      3. Gather the materials. (marshmallow, 20 spaghetti, 1m of tape, 1m of thread)

      4. Build for 18 minutes. The tallest tower that stands for 1 minute wins.

      5. Watch the video https://www.youtube.com/watch?v=1p5sBzMtB3Q

      6. Answer:
        -  how many people did he test?
        -  where did he test it?
        -  where were the best engineers?
        -  who had the worst performance?
        -  how did kindergarten kids perform?
        -  where do these answers leave us a team?

Notes:
- There is a video that complements with graphs of why is this happening: https://www.youtube.com/watch?v=vi9CILGF2YQ

- Detailed instructions are hosted [here] (http://marshmallowchallenge.com/instructions). You will need them if you are an instructor and this is the first time you run it.

## 2. Robotics

### 2.1 Introduction
Read the provided material. Use online resources to answer:
-  what does "Robot" mean?
-  what were the first robots?
-  what different kind of robots are available?
-  which parts does a robot have?

### 2.2 Microcontrollers - Firmware
Connect the USB cable. Use the [Arduino Software](http://arduino.cc). Select the port and the board type under Tools menu.

Note: in case you are using W###340 chipset, use the following [link for the drivers]( http://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html)


### 2.3 Microcontrollers - Digital Outputs
Use the code example [Blink](https://www.arduino.cc/en/Tutorial/Blink). Press the Upload button. Change the 1000 number into other numbers and answer:
-  what is 1000?
-  how fast our eyes can see?
-  how fast can a microcontroller update an output?


### 2.4 Microcontrollers - Breadboard & buzzer
Use the code example [Tones](https://www.arduino.cc/en/Tutorial/ToneMelody). Connect the arduino output to the pin 8 to the buzzer. Buzzer to GND:
-  does the buzzer work in any way we connect it?
-  what does GND stand for?
-  how are the lines of the breadboard connected?

![image](https://cloud.githubusercontent.com/assets/981310/16712931/30da32e8-46c9-11e6-9fc9-28f0140eec92.png)



## 3. Mechanics Basics

### 3.1 Introduction
Read the provided material. Use online resources to answer:
-  what does a "stable structure" mean?
-  what is "the Center of Mass" or "Center of Gravity"?
-  what is a differential robot?

### 3.2 Iteration by prototyping and testing

- BigDog: [video] (https://www.youtube.com/watch?v=cNZPRsrwumQ)
- Spot: [video] (https://www.youtube.com/watch?v=M8YjvHYbZ9w)
- Spotmini: [video](https://www.youtube.com/watch?v=tf7IEVTDjng)

### 3.3 Assembly
Use the instructions to create the first basic structure. Build on top of that your unique model.

Make sure that, USB motor cables and power can be connected easily. Make the breadboard and the Arduino pins accessible.


## 4. Electronics Basics

### 4.1.1 Introduction
Identify the following:
  -  microcontroller
  -  USB chip
  -  motor driver
  -  motors
  -  batteries

### 4.1.2 Driving motors
![image](https://cloud.githubusercontent.com/assets/981310/16714428/47c0c568-46f5-11e6-9bb5-4953842f1826.png)



### 4.2 Motor driver L298N & batteries
Without disconnecting the buzzer, we will connect the motor driver and the batteries.


![image](https://cloud.githubusercontent.com/assets/981310/16712935/767d7aa8-46c9-11e6-98f1-a6fee6d2bb37.png)

Note1: detailed datasheet of the L298N motor driver is [here](https://www.sparkfun.com/datasheets/Robotics/L298_H_Bridge.pdf)

Note2: if the battery polarity is reversed, both the driver and the Arduino will become useless. It is recommended for the instructor to check one by one before switiching ON.


### 4.2 Code example with digitalWrite
Example:
```Arduino
int speedPin_M1 = 9;     //M1 Speed Control
int speedPin_M2 = 3;     //M2 Speed Control
int directionPin_M1A = 6;     //M1 Direction Control
int directionPin_M1B = 7;     //M1 Direction Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 5;     //M1 Direction Control

void setup() {                               // Serial initialization
 pinMode(directionPin_M1A, OUTPUT);
 pinMode(directionPin_M1B, OUTPUT);
 pinMode(directionPin_M2A, OUTPUT);
 pinMode(directionPin_M2B, OUTPUT);
 pinMode(directionPin_ENA, OUTPUT);
 pinMode(directionPin_ENA, OUTPUT);
 digitalWrite (speedPin_M2, HIGH);             //no PWM Speed Control yet
 digitalWrite(directionPin_M1A, LOW);
 digitalWrite(directionPin_M1B, HIGH);
 digitalWrite (speedPin_M1, HIGH);             //no PWM Speed Control yet
 digitalWrite(directionPin_M2A, LOW);
 digitalWrite(directionPin_M2B, HIGH);  
 delay(1000);                                  //WAITS FOR 1 SECOND
 digitalWrite (speedPin_M1, LOW);              //stops the motors
 digitalWrite (speedPin_M2, LOW);              //
 delay(1000);                                  //WAITS FOR 1 SECOND
 digitalWrite (speedPin_M2, HIGH);             //no PWM Speed Control yet
 digitalWrite(directionPin_M1A, HIGH);
 digitalWrite(directionPin_M1B, LOW);  
 digitalWrite (speedPin_M1, HIGH);             //no PWM Speed Control yet
 digitalWrite(directionPin_M2A, HIGH);
 digitalWrite(directionPin_M2B, LOW);
 delay(2000);                                  //WAITS FOR 2 SECONDS
}

void loop() {
  //do nothing
}
```


### 4.3 Pulse Width Modulation

Read the materials provided and answer:
- What is the difference between a digital and an analog signal?
- Which pins can give a P.W.M. output ?
- How does the A.D.C. module work?
- How many bits is the maximum output?

![image](https://cloud.githubusercontent.com/assets/981310/16713699/74f16398-46e2-11e6-9d79-b35ab8189bac.png)


### 4.4 Speed control with analogWrite
Read the reference of [AnalogWrite](https://www.arduino.cc/en/Reference/AnalogWrite)

Use this new information to transform your software into a speed controlled one. Make the robot go in a circle.

## 5. Maze Solving - Activity
### 5.1 Rules setting
Each team will have a starting point and they need to navigate through fixed obstacles.

### 5.2 Activity Objectives
All participants will practice sequential programming, becoming more familiar with the challenges of connecting their planned software with the real limitations when testing it.

## 6. Software Basics I
### 6.1 Intro
Watch the following video. Darpa challenge 2015: [video] (https://www.youtube.com/watch?v=8P9geWwi9e0)

Debate:
- which is the most difficult task?
- what do the algorithms need to consider?
- Why is called the "Darpa Challenge"?


### 6.2 Control Structures: while & for
Use the following information:
https://www.arduino.cc/en/Reference/For
https://www.arduino.cc/en/Reference/while

Build a software that plays a melody at each corner of a square.



### 6.3 Communication
Use the following information:
https://www.arduino.cc/en/Reference/For
https://www.arduino.cc/en/Reference/while

Build a software that plays a melody at each corner of a square.



### 6.4 Control Structures: variables
Use the following information:
https://www.arduino.cc/en/Reference/For
https://www.arduino.cc/en/Reference/while

Build a software that plays a melody at each corner of a square.


## 7. Sensors
### 7.1 Analog Sensors: Light Detection
Use this circuit:
![image](https://cloud.githubusercontent.com/assets/981310/16713846/08642324-46e6-11e6-94fb-d65f544d99f6.png)

With this software:
https://www.arduino.cc/en/Tutorial/AnalogInput

Your goal is to create a light sensing software.

### 7.2.1 Digital Sensors: Ultrasound - Hardware
As an example of a digital sensor, we have the ultrasonic module HC-SR04
[datasheet](http://www.robotshop.com/media/files/PDF/datasheet-sen026.pdf)

Use the following diagram to wire it to your board:
![image](https://cloud.githubusercontent.com/assets/981310/16713761/ed20dc4e-46e3-11e6-8337-91260704a771.png)


### 7.2.2 Digital Sensors: Ultrasound - Software

Given the following function, read the value in centimeters. :
```Arduino
int ultraSound( void ) {
  long duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;
  return (int)distance;
}
```

## 8. Software Basics II
### 6.3 Control Structures: if
### 6.3 Control Structures: Switch case


### 8.2 Wifi
### 8.3 Infrared signals
![image](https://cloud.githubusercontent.com/assets/981310/16713730/5fa7f4ba-46e3-11e6-866e-ad6c14f96c6d.png)


## 9. Analog signals

## 10. Chain Reaction - Activity
### 10.1 Rules setting
Each robot/machine will receive one input. Each one should have the ability to have one physical movement as an output. All machines should be connected together. No movement can last less than two seconds. No robot can directly touch other robot.

### 10.2 Activity Objectives
Through this physical challenge, all knowledge is applied by the participants. The collaboration between the teams and the curiosity of how


## 11. What we can learn from "making" a robot ...
The expected learning outcomes can be stated as some of the following. What we have to add on top of those is that the technological fluency achieved has no limits.

- Understand fundamentals of computer programming and interactivity
- Apply and implement coding techniques to solve problems
- Integrate and associate the techniques used both in software and hardware development
- Build a mechanical structure and do the electrical connections to make it fully autonomous.
- Program a microcontroller by writing programs that display messages, remember values, make computations with math operators, and interact with external circuits.
- Build and adjust an autonomous control system that monitors sensor input and responds with motion output.
- Identify and apply additional STEM concepts including physics (the light spectrum, frequency, sound, motion) and engineering skills (mechanics, troubleshooting, problem­solving, subsystem testing, and setpoints).

## 12 Authors and Contributors
You can find the author, Rudi both on wechat, twitter and Github as @todocono .Feel free to open an issue or start a wiki for it and to shoot for a Pull Request if you want to improve the code or the content.

 Back in 2012, Julian da Silva @miniBloq and Monica Paves @monicapaves served as an inspiration for this course.

Additional resources were used from numerous graphics and examples, specially from Arduino website:
https://www.arduino.cc/en/Tutorial/BuiltInExamples
https://www.arduino.cc/en/Reference/HomePage
