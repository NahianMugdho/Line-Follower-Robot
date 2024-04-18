// IR Sensor Pins
int sensor1 = 2;      // Leftmost sensor
int sensor2 = 3;
int sensor3 = 4;
int sensor4 = 5;      // Rightmost sensor

// Motor Pins
int ENA = 6;
int motorInput1 = 7;
int motorInput2 = 8;
int motorInput3 = 9;
int motorInput4 = 10;
int ENB = 11;

// Sensor Values
int sensor[4] = {0, 0, 0, 0};

// Motor Speeds
int motorSpeed = 50;  // Adjust this value for desired speed

void setup() {
  // Serial communication for debugging
  Serial.begin(9600);

  // Sensor pins setup
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  // Motor pins setup
  pinMode(ENA, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Read sensor values
  sensor[0] = digitalRead(sensor1);
  sensor[1] = digitalRead(sensor2);
  sensor[2] = digitalRead(sensor3);
  sensor[3] = digitalRead(sensor4);

  // Debugging: print sensor values
  Serial.print("Sensor Values: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor[i]);
    Serial.print(" ");
  }
  Serial.println();

  
}

// Function to move forward
void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}

// Function to turn left
void turnLeft() {
  analogWrite(ENA, motorSpeed / 2);
  analogWrite(ENB, motorSpeed);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}

// Function to slightly turn left
void slightLeft() {
  analogWrite(ENA, motorSpeed * 0.75);
  analogWrite(ENB, motorSpeed);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}

// Function to turn right
void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed / 2);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

// Function to stop motors
void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
