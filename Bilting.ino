#include <Joystick.h>



Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, 4, 0,
  false, false, false, false, false, false,
  false, false, true, true, true);


int speederPin = A0;
int brakePin = A1;
int steerRightPin = A2;
int steerLeftPin = A3;


int speeder = 0;
int brake = 0;
int steerRight = 0;
int steerLeft = 0;
const int pinToButtonMap = 7;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  Joystick.setAcceleratorRange(860, 885);
  Joystick.setBrakeRange(850, 870);
  Joystick.setSteeringRange(-45, 40);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  
  Joystick.begin();
}



void loop() {
  // put your main code here, to run repeatedly:
  speeder = analogRead(speederPin);
  //Serial.println(speeder);
  Joystick.setAccelerator(speeder);

  brake = analogRead(brakePin);
  //Serial.println(brake);
  Joystick.setBrake(brake);

  steerRight = analogRead(steerRightPin);
  steerRight = steerRight-820;
  steerLeft = analogRead(steerLeftPin);
  steerLeft = steerLeft-820;
  int steer = steerRight-steerLeft;
  //Serial.println(steer);
  Joystick.setSteering(steer);
  

  Joystick.sendState();
  delay(50);
}
