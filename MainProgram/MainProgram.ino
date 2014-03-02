#define GREEN 5
#define BLUE 3
#define RED 6
#define delayTime 20

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  initializationSwag();
  randomExplosion();
}

int redVal;
int blueVal;
int greenVal;

void initializationSwag() {
  int offset = 30;
  for (int delayMagic = 1000; delayMagic >= 0; delayMagic -=offset) {
    digitalWrite(RED,HIGH);
    delay(delayMagic);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    delay(delayMagic);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE, HIGH);
    delay(delayMagic);
    digitalWrite(BLUE, LOW);
    offset*=1.3;
  }
}
void randomExplosion() {
  for (int i = 0; i < 10; i++) {
    randCol();
    delay(100);
  }
}
int loopOffset;
void loop() {
    redVal = 1;
    blueVal = 1;
    greenVal = 1;
    loopOffset = 1;
    
    for(int i = 1; i <= 254; i += loopOffset) {
      greenVal++;
      redVal--;;
      analogWrite(GREEN, 255 - greenVal);
      analogWrite(RED, 255 - redVal);
      delay(delayTime);
      }
    
    for(int i = 1; i <= 254; i += loopOffset) {
      blueVal++;
      greenVal--;
      analogWrite(BLUE, 255 - blueVal);
      analogWrite(RED, 255 - redVal);
      delay(delayTime);
    }  

    for(int i = 1; i <= 254; i += loopOffset) {
      redVal++;
      blueVal--;
      
      analogWrite(GREEN, 255 - greenVal);
      analogWrite(BLUE, 255 - blueVal);
      delay(delayTime);
    }    
  }

void randCol() {
  analogWrite(GREEN, random(0,255));
  analogWrite(BLUE, random(0,255));
  analogWrite(RED, random(0,255));
}
