#include <SoftwareSerial.h> 
char t;
   
#define INT1 2
#define INT2 3
#define INT3 4
#define INT4 5

SoftwareSerial serialdobluetooth(6, 7);

int valordobluetooth;
 
void setup() {
  pinMode(INT1, OUTPUT);   // left motors forward
  pinMode(INT2, OUTPUT);   // left motors reverse
  pinMode(INT3, OUTPUT);   // right motors forward
  pinMode(INT4, OUTPUT);   // right motors reverse
 
  Serial.begin(9600);
  serialdobluetooth.begin(9600);
  Serial.println("Serial communication initialized. Ready to receive commands.");
}
 
void loop() {
  if (serialdobluetooth.available()) { // Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
    valordobluetooth = serialdobluetooth.read();
    Serial.println("Received command from Bluetooth: " + String(valordobluetooth));
  }

  if (Serial.available()) {
    t = Serial.read();
    Serial.println("Received command from Serial: " + String(t));
  }
 
  if (valordobluetooth == '1') {            // move forward(all motors rotate in forward direction)
    digitalWrite(INT1, HIGH);
    digitalWrite(INT2, LOW);
    digitalWrite(INT3, HIGH);
    digitalWrite(INT4, LOW);
    Serial.println("Moving forward.");
  } 
  else if (valordobluetooth == '2') {      // move reverse (all motors rotate in reverse direction)
    digitalWrite(INT1, LOW);
    digitalWrite(INT2, HIGH);
    digitalWrite(INT3, LOW);
    digitalWrite(INT4, HIGH);
    Serial.println("Moving reverse.");
  } 
  else if (valordobluetooth == '3') {      // turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(INT1, HIGH);
    digitalWrite(INT2, LOW);
    digitalWrite(INT3, LOW);
    digitalWrite(INT4, LOW); 
    Serial.println("Turning right.");
  } 
  else if (valordobluetooth == '4') {      // turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(INT1, LOW);
    digitalWrite(INT2, LOW);
    digitalWrite(INT3, HIGH);
    digitalWrite(INT4, LOW); 
    Serial.println("Turning left.");
  } 
  else if (valordobluetooth == '5') {      // STOP (all motors stop)
    digitalWrite(INT1, LOW);
    digitalWrite(INT2, LOW);
    digitalWrite(INT3, LOW);
    digitalWrite(INT4, LOW);
    Serial.println("Stopping all motors.");
  }
  delay(100);
}
