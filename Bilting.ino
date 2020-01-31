#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,                //Creating a joystick with only speeder, brake and steering
  JOYSTICK_TYPE_MULTI_AXIS, 4, 0,
  false, false, false, false, false, false,
  false, false, true, true, true);

int speederPin = A0;            //Assigning pins
int brakePin = A1;
int steerRightPin = A2;
int steerLeftPin = A3;

int speeder = 0;                //Creating variables for the thingys
int brake = 0;
int steerRight = 0;
int steerLeft = 0;

void setup() {
  Serial.begin(9600);
  
  Joystick.setAcceleratorRange(860, 885);       //Creating deadzones
  Joystick.setBrakeRange(850, 870);
  Joystick.setSteeringRange(-45, 40);

  pinMode(A0, INPUT_PULLUP);                    //Doing the input thingy
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  
  Joystick.begin();                             //Beginning the joystick?
}

void loop() {
  speeder = analogRead(speederPin);             //Speed is key
  Joystick.setAccelerator(speeder);

  brake = analogRead(brakePin);                 //Braking the game
  Joystick.setBrake(brake);

  steerRight = analogRead(steerRightPin);       //Steering it into a wall
  steerRight = steerRight-820;
  steerLeft = analogRead(steerLeftPin);
  steerLeft = steerLeft-820;
  int steer = steerRight-steerLeft;
  Joystick.setSteering(steer);
  

  Joystick.sendState();                         //Sending it
  delay(50);
}
