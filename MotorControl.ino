 /*     Simple Stepper Motor Control Exaple Code
  *
  *    by Dejan Nedelkovski, www.HowToMechatronics.com
  *   Modified by Liam Gallagher
  *
  */
 // defines pins numbers
const int stepPin = 3;
const int dirPin = 4;
int default_motor_speed = 500; //500 useconds(micro) between steps.
                       //Need to do more research into the actual number needed to
                       //correlate to the needed speed with my motor choice and thread choice
//Encoder variables
int val;
int encoder0PinA = 5;
int encoder0PinB = 6;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;


//function to move motor up at certain speed
void moveUp(int distance,int speed){
                                        //distance is in mm
                                        //distance is some function of the steps determined by the lead screw
                                        //Looking for equation or quantifier to convert.
int number_of_steps = 0;  //init
//number_of_steps = distance * (some factor I've yet to find
//                              for the lead screw I picked...);
digitalWrite(dirPin,HIGH); //HIGH for UP
    for(int x = 0; x < number_of_steps; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(speed);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(speed);
    }
delay(1000); // One second delay
}
void moveDown(int distance,int speed){
                                        //distance is in mm
                                        //distance is some function of the steps determined by the lead screw
                                        //Looking for equation or quantifier to convert.
int number_of_steps = 0; //init
//number_of_steps = distance * (some factor I've yet to find
//                              for the lead screw I picked...);
digitalWrite(dirPin,LOW); //LOW for UP

    for(int x = 0; x < number_of_steps; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(speed);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(speed);
    }
delay(1000); // One second delay
}
int get_position(){
    n = digitalRead(encoder0PinA);
    if ((encoder0PinALast == LOW) && (n == HIGH)) {
      if (digitalRead(encoder0PinB) == LOW) {
        encoder0Pos--;
      } else {
        encoder0Pos++;
      }
      Serial.print (encoder0Pos);
      Serial.print ("/");
    }
    encoder0PinALast = n;
    return encoder0PinALast;
}

 void setup() {
   // Sets the two pins as Outputs
   pinMode(stepPin,OUTPUT);
   pinMode(dirPin,OUTPUT);
   pinMode (encoder0PinA, INPUT);
   pinMode (encoder0PinB, INPUT);
   Serial.begin (9600);

 }
 void loop() {

   //check for moveUp and moveDown
   //interupts would be best.


 }
