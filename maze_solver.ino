#include<NewPing.h>
#include<Servo.h>
Servo mot;
 
// define servo

int in1=1; int in2=2 ;  int in3=3 ; int in4=4;
int enb_mot_R =9;
int enb_mot_L =9;
// define motors 

int trig=5;
int echo=6;
int maxdist=100;
NewPing us(trig,echo,maxdist);
float x;   float y;    float z;
// define ultra sonic 

void setup() {
  // put your setup code here, to run once:
  mot.attach(10);
  Serial.begin(9600);
mot.write(90);
for(int i=1;i<=4;i++)
pinMode(i,OUTPUT);
pinMode(enb_mot_R,OUTPUT);
pinMode(enb_mot_L,OUTPUT);
}

void forward(int,int,int,int,int,int);
void backward(int,int,int,int,int,int,float);
void turnright(int,int,int,int,int,int,float);
void turnleft(int,int,int,int,int,int,float);


void loop() {
  // put your main code here, to run repeatedly:
for (int i=1 ;i<=4;i++)
digitalWrite(i,0);
// make motors turn off
x=us.ping_cm();
Serial.println(x);
y=x;
while(x>=10)
{
  forward(in1,in2,in3,in4,enb_mot_R,enb_mot_L );
  x=us.ping_cm();
  Serial.println(x);
}
for (int i=1 ;i<=4;i++)
digitalWrite(i,0);
mot.write(180);
delay(500);
x=us.ping_cm();
Serial.println(x);
// make the servo turns and measeure the distance 
if (x>10)
{
z=x;
turnright(in1,in2,in3,in4,enb_mot_R,enb_mot_L,z );
Serial.println("turnright");
}
else 
{ 
  mot.write(0);
  delay(500);
  x=us.ping_cm();
  Serial.println(x);
  if(x>10)
  {
  z=x;
turnleft (in1,in2,in3,in4,enb_mot_R,enb_mot_L,z );
Serial.println(x);
  }
else
{
  backward(in1,in2,in3,in4,enb_mot_R,enb_mot_L ,y);
  Serial.println("backward noo");
}
}
}
 void forward(int in1,int in2,int in3,int in4,int enb_mot_R,int enb_mot_L )
 {
  digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enb_mot_R,200);
      analogWrite(enb_mot_L,200);
      Serial.println("forward");
    }




    
 void backward(int in1,int in2,int in3,int in4,int enb_mot_R,int enb_mot_L,float y )
 {
  mot.write(90);
  delay(1000);
  x=us.ping_cm();
 while(x<y)
 {
  Serial.println("enter");
   digitalWrite(in2,HIGH);
   digitalWrite(in1,LOW);
   digitalWrite(in4,HIGH);
    digitalWrite(in3,LOW);
    analogWrite(enb_mot_R,200);
      analogWrite(enb_mot_L,200);
      x=us.ping_cm();
      Serial.println("infinite loop");
    }
    Serial.println("backward");

  mot.write(180);
delay(1000);
x=us.ping_cm();
Serial.println(x);
// make the servo turns and measeure the distance 
if (x>10)
{
z=x;
turnright(in1,in2,in3,in4,enb_mot_R,enb_mot_L ,z);
}
else 
{
  z=x;
turnleft (in1,in2,in3,in4,enb_mot_R,enb_mot_L,z );
}
 }


 void turnright (int in1,int in2,int in3,int in4,int enb_mot_R,int enb_mot_L,float z )
  {
    mot.write(90);
    x=us.ping_cm();
    while(x<z)
    {
      digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    analogWrite(enb_mot_R,200);
      analogWrite(enb_mot_L,0);
      }
      Serial.println("turn right");
  }
    void turnleft (int in1,int in2,int in3,int in4,int enb_mot_R,int enb_mot_L,float z )
    {
      mot.write(90);
    x=us.ping_cm();
    while(x<z)
    {
      digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
   digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(enb_mot_R,200);
      analogWrite(enb_mot_L,0);
      }
      Serial.println("turn left");
      
      }
      
