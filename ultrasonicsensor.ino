int Echo = A4;
int Trig = A5;
int Buzzer = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  systems_check();
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

void systems_check(){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
    int distanceCM;
    distanceCM = Distance_test();
    Serial.println(distanceCM);
    int range = 0;
    range = Serial.read();
    if (distanceCM >=40 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 35 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 25 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 20 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 15 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 10 && distanceCM <=50){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(3, LOW);
    } else if (distanceCM >= 1 && distanceCM <10){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        delay(1);
        digitalWrite(Buzzer, HIGH);
    } else {
        digitalWrite(Buzzer, LOW);
  }
}
