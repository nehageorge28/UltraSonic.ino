# UltraSonic.ino
Ultrasonic Sensor 
#### Pins
* leftFarSensorTrig
* leftFarSensorEcho
* leftNearSensorEcho
* leftNearSensorTrig
* CenterSensorTrig
* CenterSensorEcho
* rightNearSensorTrig
* rightNearSensorEcho
* rightFarSensorTrig
* rightFarSensorEcho
* leftMotor1
* leftMotor2
* rightMotor1
* rightMotor2
* en1 - enable pin 1
* en2 - enable pin 2

#### Variables
* leftNearReading
* leftFarReading
* CenterReading
* rightFarReading
* leaptime=200
All variables in the code are of the datatype int

### Functions
#### setup() 
- Initialises the echo pins to input and the trig pins to output, using the pinMode() function.
- Initialises the motor pins to output using the pinMode() function.
- Assigns an analog value to the enable pins using the function analogWrite().
- Begins Serial communication

#### readSensors()
- Reads the pulse from each sensor using pulseIn() function
- Converts the duration of each pulse in terms of distance using a user defined function convert().
- The digital logic output from the sensors are used to move the bot either in a straight direction or to follow the left hand side wall.

#### leftHandWall()
- The robot keeps moving along the left side wall depending upon the presence or absence of the wall and calls straight(), turnleft() and turnright() functions depending upon different situations encountered by the robot. 
- Calls the done() function once it successfully escapes from the maze.     

#### done()
- Assigns a LOW value to each motor using digitalWrite() function.

#### turnLeft()
- Assigns a LOW or HIGH value to the required motors in accordance to the values received from the echo pins, using the digitalWrite() function.


#### turnRight()
- Assigns a LOW or HIGH value to the required motors in accordance to the values received from the echo pins, using the digitalWrite() function.

#### straight()
- Assigns a LOW or HIGH value to the required motors in accordance to the values received from the echo pins, using the digitalWrite() function.

#### turnAround()
- Assigns a LOW or HIGH value to the required motors in accordance to the values received from the echo pins, using the digitalWrite() function.

#### convert()
- Converts microseconds in terms of distance using the formula speed=distance/time.

#### endMotion()
- Recursive function which halts the bot at the end of the maze

#### loop()
- The sensor values are read by calling readSensors() function. The digital logic output from the sensors move the robot either in straight direction or to follow left hand side wall.





   
   
