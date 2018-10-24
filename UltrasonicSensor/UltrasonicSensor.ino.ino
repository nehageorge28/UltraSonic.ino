#define leftFarSensorTrig 15
#define leftFarSensorEcho 14
#define leftNearSensorTrig 13  
#define leftNearSensorEcho 12
#define CenterSensorTrig   11
#define CenterSensorEcho   10
#define rightNearSensorTrig 9
#define rightNearSensorEcho 8
#define rightFarSensorTrig 7
#define rightFarSensorEcho 6
int leftNearReading;

int leftFarReading;

int CenterReading;

int rightNearReading;

int rightFarReading;



#define leapTime 200

#define leftMotor1  2

#define leftMotor2  3

#define rightMotor1 4

#define rightMotor2 5

#define en1 16

#define en2 17



void setup()

{

  pinMode(leftNearSensorEcho, INPUT);

  pinMode(leftFarSensorEcho, INPUT);

  pinMode(CenterSensorEcho, INPUT);

  pinMode(rightNearSensorEcho, INPUT);

  pinMode(rightFarSensorEcho, INPUT);

   pinMode(leftNearSensorTrig, OUTPUT);

  pinMode(leftFarSensorTrig, OUTPUT);

  pinMode(CenterSensorTrig, OUTPUT);

  pinMode(rightNearSensorTrig, OUTPUT);

  pinMode(rightFarSensorTrig, OUTPUT);

   

   

  pinMode(leftMotor1, OUTPUT);

  pinMode(leftMotor2, OUTPUT);

  pinMode(rightMotor1, OUTPUT);

  pinMode(rightMotor2, OUTPUT);

  pinMode(en1, OUTPUT);

  pinMode(en2, OUTPUT);

  analogWrite(en1, 160);

  analogWrite(en2, 160);


  Serial.begin(115200);


  delay(1000);

}

void loop()

{ 

 readSensors();                                                                                     

 if(leftFarReading == LOW && rightFarReading == LOW && 

   (CenterReading == HIGH || leftNearReading == HIGH) )

   { 

    straight();                                                                                      

  }

  else

  {                                                                                              

    leftHandWall();                                                                                   

  }

}

void readSensors()

{
 int durationLeftNear=pulseIn(leftNearSensorEcho,HIGH);
 int durationLeftFar=pulseIn(leftFarSensorEcho,HIGH);
 int durationRightNear=pulseIn(rightNearSensorEcho,HIGH);
  int durationRightFar=pulseIn(rightFarSensorEcho,HIGH);
  int durationCenter=pulseIn(CenterSensorEcho,HIGH);

  
  leftNearReading    = convert(durationLeftNear);

  leftFarReading     = convert(durationLeftFar);

  CenterReading      = convert( durationCenter);

  rightNearReading   = convert(durationRightNear);

  rightFarReading    = convert(durationRightFar);

}

void leftHandWall()

{ 

  if(leftFarReading == HIGH && rightFarReading == HIGH){

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(300);

    readSensors();

    if(leftFarReading == LOW && rightFarReading == LOW)

    {

       turnLeft();

    }

    else

    { 

       done();

    }

  } 

  if(leftFarReading == HIGH)

  { 

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(300);

    readSensors();

      if(leftFarReading == LOW && rightFarReading == LOW)

      {

        turnLeft();

      }

      else

      {

        done();

      }

  }

  

  if(rightFarReading == HIGH)

  {

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(300);

    readSensors();

   

     if(leftFarReading == HIGH)

     {

     delay(leapTime-30);

     readSensors();

     

      if(rightFarReading == HIGH && leftFarReading == HIGH)

      {

        done();

      }

      else if(rightFarReading == LOW && leftFarReading == LOW && CenterReading == LOW && rightNearReading == LOW)

      {

        turnRight();

      }

      else

      {

        straight();

        return;

      }

   }

    delay(leapTime-30);

    readSensors();

    if(leftFarReading == LOW && CenterReading == LOW &&

      rightFarReading == LOW){

     turnRight();

      return;

    }

   

    straight();

  }

  readSensors();

  if(leftFarReading == LOW && CenterReading == LOW 

    && rightFarReading == LOW && leftNearReading == LOW && rightNearReading == LOW)

    {

    turnAround();

    }

}

void done()

{

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);



 delay(1500);

  

}

void turnLeft()

{

  while(digitalRead(leftNearSensorEcho) == HIGH)

  {

     digitalWrite(leftMotor1,  LOW);

     digitalWrite(leftMotor2,  LOW);

     digitalWrite(rightMotor1, HIGH);

     digitalWrite(rightMotor2, LOW);

     delay(2);

     digitalWrite(leftMotor1,  LOW);

     digitalWrite(leftMotor2,  LOW);

     digitalWrite(rightMotor1, LOW);

     digitalWrite(rightMotor2, LOW);

     delay(1);

  }

     

   while(digitalRead(leftNearSensorEcho) == LOW)

   {

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(2);

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

  }

  while(digitalRead(leftFarSensorEcho) == HIGH && digitalRead(leftNearSensorEcho) == HIGH)

  {

     digitalWrite(leftMotor1,  LOW);

     digitalWrite(leftMotor2,  LOW);

     digitalWrite(rightMotor1, HIGH);

     digitalWrite(rightMotor2, LOW);

     delay(2);

     digitalWrite(leftMotor1,  LOW);

     digitalWrite(leftMotor2,  LOW);

     digitalWrite(rightMotor1, LOW);

     digitalWrite(rightMotor2, LOW);

     delay(1);

  }

}

void turnRight()

{

  while(digitalRead(rightNearSensorEcho) == HIGH){

     digitalWrite(leftMotor1, HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

     digitalWrite(leftMotor1, LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

  }

   while(digitalRead(rightNearSensorEcho) == LOW){

     digitalWrite(leftMotor1, HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

     digitalWrite(leftMotor1, LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

  }

   while(digitalRead(leftNearSensorEcho) == LOW){

     digitalWrite(leftMotor1, HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

  }


}

void straight(){

  if( digitalRead(leftNearSensorEcho) == LOW){

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    return;

  }

 

  if(digitalRead(rightNearSensorEcho) == LOW){

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    return;

  }

 

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(1);

    digitalWrite(leftMotor1,  LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

}

void turnAround(){

    digitalWrite(leftMotor1,  HIGH);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(100);

   while(digitalRead(leftNearSensorEcho) == LOW || digitalRead(CenterSensorEcho) == LOW){

     digitalWrite(leftMotor1, LOW);

    digitalWrite(leftMotor2,  HIGH);

    digitalWrite(rightMotor1, HIGH);

    digitalWrite(rightMotor2, LOW);

    delay(1);

     digitalWrite(leftMotor1, LOW);

    digitalWrite(leftMotor2,  LOW);

    digitalWrite(rightMotor1, LOW);

    digitalWrite(rightMotor2, LOW);

    delay(1);

  }

  }

int convert(int microseconds) {
   return microseconds / 74 / 2;



}
   

 

 



void endMotion()

{

  endMotion();

}
