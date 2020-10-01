int Echo = A4;
int Trig = A5;
int Buzzer = A0;
int ledNum;
int ledArray[] = {2,3,4,5,6,7,8};
int x = 0;

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
  systemsCheck();
}

void turnOnLED(int ledNum){
for (int i = 7; ledNum < i; i--){
     digitalWrite(ledArray[i], HIGH);
     }
for (int i = 1; ledNum > i; i++){
     digitalWrite(ledArray[i], LOW);
     }
}

void testDistance(){
  int totalDistance;
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;
  totalDistance = Fdistance / 5;
  if (totalDistance < 9) {
    ledNum = totalDistance;
  }
  Serial.println(totalDistance);
}

void proximityAlarm(){
  for (int i = 1; i < 3; i++) {
    digitalWrite(Buzzer, HIGH);
    delay(200);
    digitalWrite(Buzzer, LOW);
    delay(200);
  }
  delay(600);
}

void setBuzzerStatus(){
  if (ledNum == 0){
    proximityAlarm();
  }
  else{
    digitalWrite(Buzzer, LOW);
  }
  
}

void systemsCheck(){
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
    testDistance();
    turnOnLED(ledNum);
    setBuzzerStatus();
}
