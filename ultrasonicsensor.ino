int Echo = A4;
int Trig = A5;
int Buzzer = A0;
int ledState;
int ledArray[] = {2,3,4,5,6,7,8};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  for (int i = 0; i < 7; i++){
    pinMode(ledArray[i], OUTPUT);
  }
  systems_check();
}

void arrayOutput(int ledState){
  for (int i = 0; i < 7; i++){
    digitalWrite(ledArray[i], LOW);
  }
  for (int i = 0; i < ledState; i++){
    digitalWrite(ledArray[i], HIGH);
  }
}

int Distance_test(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;
  return (int)Fdistance;
}

void proximity_alarm(){
  for (int i = 1; i < 3; i++) {
    digitalWrite(Buzzer, HIGH);
    delay(200);
    digitalWrite(Buzzer, LOW);
    delay(200);
  }
  delay(600);
}

void systems_check(){
  for (int i = 2; i < 9; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for (int i = 8; i > 2; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  digitalWrite(2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    int distanceCM;
    distanceCM = Distance_test();
    Serial.println(distanceCM);
    int range = 0;
    range = Serial.read();
    if (distanceCM >= 35 && distanceCM <=50){
        arrayOutput(2);
    } else if (distanceCM >= 25 && distanceCM <=50){
        arrayOutput(3);
    } else if (distanceCM >= 20 && distanceCM <=50){
        arrayOutput(4);
    } else if (distanceCM >= 15 && distanceCM <=50){
        arrayOutput(5);
    } else if (distanceCM >= 10 && distanceCM <=50){
        arrayOutput(6);
    } else if (distanceCM >= 1 && distanceCM <10){
        arrayOutput(7);
        delay(1);
        proximity_alarm();
    } else {
        digitalWrite(Buzzer, LOW);
  }
}
