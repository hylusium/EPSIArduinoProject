 /* Pins Reference for : 
  - Motor
  - Button */
 int motor1pin1 = 2;
 int motor1pin2 = 3;

 int motor2pin1 = 4;
 int motor2pin2 = 5;

 const int ButtonM1 = 7;
 const int ButtonM2 = 6;
 const int ResetButton = 8;



 /*State Of the different Button in the project */
int BM1State = 0;
int BM2State = 0;
int ResetButtonState = 0;


void setup() {
  // put your setup code here, to run once:

/* setting up The pin For every component
(Motors and Buttons)*/

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ButtonM1, INPUT);
  pinMode(ButtonM2, INPUT);
  pinMode(ResetButton, INPUT);
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  /* Used For Debugging and printing Info Into the Serial Monitor */

  Serial.begin(9600);


}

void loop() {
  
  /* read the State of the differents Button */

  BM1State = digitalRead(ButtonM1);
  BM2State = digitalRead(ButtonM2);
  ResetButtonState = digitalRead(ResetButton);

/* different condition based on buttons */

  if(BM1State == HIGH )
  {
    StartMotor1();
  }
  if(BM1State == LOW)
  {
    StopMotor1();
  }
  if(BM2State == HIGH)
  {
    StartMotor2();
  }
  if(BM2State == LOW)
  {
    StopMotor2();
  }

  if(ResetButtonState == HIGH)
  {
    ResetMotor();
  }
  
}





void StartMotor1()
{
  /* Start The first motor By entering a value to the pin 9 of the driver*/

  analogWrite(9,200);
  
  /*choose the direction of the motor*/
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

}
void StopMotor1()
{
  /*set the value of the pin 9 to 0 to stop the first motor */
  analogWrite(9,0);

}

void StartMotor2()
{
  analogWrite(10,200);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

}
void StopMotor2()
{
  analogWrite(10,0);


}
void ResetMotor()
{
  /* reset The car position By reducing speed for the motors and invert their rotations*/
  analogWrite(9,90);
  analogWrite(10,90);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

