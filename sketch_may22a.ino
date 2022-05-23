#include <SoftwareSerial.h>

int pinHC05_Rx = 12;  //yellow wire for grove
int pinHC05_Tx = 13;  //white wire for grove
SoftwareSerial BTSerial(pinHC05_Tx, pinHC05_Rx);  //bibliothèque bluetooth pour hc05


const int A1A = 2;//define pin 2 for A1A
const int A1B = 3;//define pin 3 for A1B

const int B1A = 8;//define pin 8 for B1A
const int B1B = 9;//define pin 9 for B1B



void setup() {
  pinMode(B1A, OUTPUT); // define pin as output
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);

  delay(3000);
  pinMode(pinHC05_Tx, INPUT);
  pinMode(pinHC05_Rx, OUTPUT);
  BTSerial.begin(9600);// 9600 ou 38400 selon le composant
  Serial.begin(9600);  //initialisation Serial Monitor (ordinateur)

}

void loop() {
  if (BTSerial.available()) { // detection of a signal
    char caractereASCII = BTSerial.read();  //caractère ASCII envoyé
    Serial.print(caractereASCII);
    Serial.print("   ");
    switch (caractereASCII) {
      case 'F': // code ASCII 82==R
        Serial.println("Forward"); 
        motorB('R');
        motorB('L');
        break;
      case 'B':
        Serial.println("Back");
        motorB('L');
        motorB('R');
        break;
      case 'L':
        Serial.println("Left");
        motorB('R');
        motorB('O');
        break;
      case 'R':
        Serial.println("Right");
        motorB('O');
        motorB('R');
        break;
    }  //fin switch case
  }  //fin if
}  //fin loop

/*
   @motorA
   activation rotation of motor A
   d is the direction
   R = Right
   L = Left
*/
void motorA(char d)
{
  if (d == 'R') {
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, HIGH);
    Serial.println("ok");
  } else if (d == 'L') {
    digitalWrite(A1A, HIGH);
    digitalWrite(A1B, LOW);
    Serial.println("ok");
  } else {
    
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, LOW);
    Serial.println("ok");
  }
}// motorA end


/*
   @motorB
   activation rotation of motor B
   d is the direction
   R = Right
   L = Left
*/
void motorB(char d)
{

  if (d == 'R') {
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, HIGH);
    Serial.println("ok");
  } else if (d == 'L') {
    digitalWrite(B1A, HIGH);
    digitalWrite(B1B, LOW);
    Serial.println("ok");
  } else {
    
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, LOW);
    Serial.println("ok");
  }

}// motorB end
