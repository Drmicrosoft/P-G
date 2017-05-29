/*
  Mega multple serial test
 
 Receives from the main serial port, sends to the others. 
 Receives from serial port 1, sends to the main serial (Serial 0).
 
 This example works only on the Arduino Mega
 
 The circuit: 
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:
 
 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach
 
 This example code is in the public domain.
 
 */
#include <Servo.h> 
Servo myservo;  
Servo myservo1;  
Servo myservo2;  
Servo myservo3;  
Servo myservo4;  
Servo myservo5;  
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
            myservo.attach(9);  // attaches the servo on pin 9 to the servo object              
            myservo1.attach(3);  // attaches the servo on pin 9 to the servo object              
                        myservo2.attach(5);  // attaches the servo on pin 9 to the servo object              
                                    myservo3.attach(6);  // attaches the servo on pin 9 to the servo object              
                                                myservo4.attach(10);  // attaches the servo on pin 9 to the servo object              
                                                            myservo5.attach(11);  // attaches the servo on pin 9 to the servo object              
              
}
char omar [6];
char p1 [8][6]={{'6','3','D','6','3','U'},{'6','0','D','6','0','U'},{'1','E','D','1','E','U'},{'6','4','D','6','4','U'},{'1','3','D','1','3','U'},{'1','5','D','1','5','U'},{'1','4','D','1','4','U'},{'1','6','D','1','6','U'}};
char omar1 [8]={0,0,0,0,0,0,0,0};
int i=0;

int c = 0 ;
void loop() {
  // read from port 1, send to port 0:
  
  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial.write(inByte); 
        Serial.write(char(inByte)); 
                Serial.print(char(inByte)); 
                Serial.print(inByte); 
                
  omar [i] = char(inByte);
 i++; 
       Serial.write("\n");        
  }


if(i==6)
{
     Serial.write("Omar Was Here\n");          
     int j = 0 ;
for(j=0;j<8;j++)

  {
         Serial.write("start"); 
    for(i=0;i<6;i++)
  {
         
                 Serial.print(i); 
  if(omar[i] == p1[j][i])
  {
    c=1;
    
    
  }
  else 
  {
    c=0;
    break;
  }
  
  
  }
  if(i==6)
    break;
  
  
  
  
  }
  
  if(c==1)
  {
        i=0;
    if(j==0)
    {
      if(omar1[0]==0)
{         Serial.write("LED 0  is On\n");          
myservo.write(0);   
myservo1.write(0);   
    omar1[0]=1;
}
else 
{
          Serial.write("LED 0  is OFF\n");          
myservo.write(92);   
myservo1.write(92);   
omar1[0]=0;

  
}
    
    
    }
     else   if(j==1)
    {

      if(omar1[1]==0)
{         Serial.write("LED 1  is On\n");          
myservo.write(0);   
myservo1.write(180);   

    omar1[1]=1;
}
else 
{
          Serial.write("LED 1  is OFF\n");          
myservo.write(92);   
myservo1.write(92);   

      omar1[1]=0;

  
}
    }
         else   if(j==2)
    {

          if(omar1[2]==0)
{         Serial.write("LED 2  is On\n");          
myservo.write(180);   
myservo1.write(0);   
    omar1[2]=1;
}
else 
{
          Serial.write("LED 2  is OFF\n");          
  myservo.write(92);   
myservo1.write(92);   
      omar1[2]=0;

  
}

    }
         else   if(j==3)
    {

        if(omar1[3]==0)
{         Serial.write("LED 3  is On\n");          
myservo.write(180);   
myservo1.write(180);   
    omar1[3]=1;
}
else 
{
          Serial.write("LED 3  is OFF\n");          
myservo.write(92);   
myservo1.write(92);   
      omar1[3]=0;

  
}

    }
         else   if(j==4)
    {

          if(omar1[4]==0)
{         Serial.write("LED 4  is On\n");          
myservo.write(90);   
    omar1[4]=1;
}
else 
{
          Serial.write("LED 4  is OFF\n");          
myservo.write(92);   
      omar1[4]=0;

  
}

    }
         else   if(j==5)
    {

            if(omar1[5]==0)
{         Serial.write("LED 5  is On\n");          
myservo.write(95);   
    omar1[5]=1;
}
else 
{
          Serial.write("LED 5  is OFF\n");          
myservo.write(92);   
      omar1[5]=0;

  
}

    }
         else   if(j==6)
    {

             if(omar1[6]==0)
{         Serial.write("LED 6  is On\n");          
  myservo.write(80);   
    omar1[6]=1;
}
else 
{
          Serial.write("LED 6  is OFF\n");          
myservo.write(92);   
omar1[6]=0;

  
}

    }
         else   if(j==7)
    {

              if(omar1[7]==0)
{         Serial.write("LED 7 is On\n");          
myservo.write(110);   
omar1[7]=1;
}
else 
{
          Serial.write("LED 7 is OFF\n");          
myservo.write(92);   
omar1[7]=0;

  
}

    }
  }
  else 
  {
    i=0;
  }
  
}
}
