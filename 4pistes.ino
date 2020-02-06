int ledPin = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;

struct Tuple {
  int x;
  int y;
};

struct Tuple valp1 =  {0, 0};
struct Tuple valp2 =  {0, 0};
struct Tuple valp3 =  {0, 0};
struct Tuple valp4 =  {0, 0};

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, INPUT);
    pinMode(ledPin2, INPUT);
    pinMode(ledPin3, INPUT);
    pinMode(ledPin4, INPUT);
}

/* fonction permettant de ne compter qu'un seul tour par passage de ligne
   - cette fonction evite de compter des tours si la voiture reste sur la ligne de detection */
struct Tuple newLap(struct Tuple value) {
    if (value.x - value.y > 0){
        struct Tuple result = {1, value.x};
        return result;
        }
    struct Tuple result = {0, value.x};
    return result; 
}

void loop() {
    //lecture des input detecter par les phototransistors
    valp1.x = digitalRead(ledPin);
    valp2.x = digitalRead(ledPin2);
    valp3.x = digitalRead(ledPin3);
    valp4.x = digitalRead(ledPin4);
    //détermination si nouveau tour ou non
    valp1 = newLap(valp1);
    valp2 = newLap(valp2);
    valp3 = newLap(valp3);
    valp4 = newLap(valp4);
    //envoie de nouveau tour à pclap si ok
    if (valp1.x==1) {
      Serial.print("[SF01]");
    }
    if (valp2.x==1) {
      Serial.print("[SF02]");
    }
    if (valp3.x==1) {
      Serial.print("[SF03]");
    }
    if (valp4.x==1) {
      Serial.print("[SF04]");
    }
}
