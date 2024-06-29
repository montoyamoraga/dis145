```
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // Pin de selección del módulo RFID
#define RST_PIN 9  // Pin de reinicio del módulo RFID

MFRC522 mfrc522(SS_PIN, RST_PIN); // Crear instancia del MFRC522
Servo myservo;  // Crear instancia del servomotor

// UID de la tarjeta autorizada 
byte kart[4] = {0xB9, 0xC0, 0xF7, 0xB8};
boolean card = false;  // Variable para almacenar el estado de la tarjeta

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial a 9600 baudios
  SPI.begin();         
  mfrc522.PCD_Init();  // Iniciar lector MFRC522
  myservo.attach(3);   // Conectar servomotor al pin 3
  myservo.write(100);  // Posición inicial del servo
}

void loop() {
  // Revisar si hay una nueva tarjeta presente
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Seleccionar una tarjeta
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Mostrar UID de la tarjeta en el monitor serial
  Serial.print("Found ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Comparar UID con la tarjeta autorizada
  card = true;  // Asumir que es correcta inicialmente
  for (byte i = 0; i < 4; i++) {  // Comparar solo los 4 bytes relevantes
    if (mfrc522.uid.uidByte[i] != kart[i]) {
      card = false;  // Si algún byte no coincide, no es la tarjeta correcta
      break;
    }
  }

  if (card) {
    Serial.println("Correct Card");
    myservo.write(180);   // Mover servo a la posición de alimentación (180 grados)
    delay(1000);          // Esperar 1 segundo
    myservo.write(100);   // Volver servo a la posición inicial (100 grados)
    delay(1000);          // Esperar 1 segundo entre detecciones
  } else {
    Serial.println("Wrong Card");
  }

  mfrc522.PICC_HaltA();  // Parar comunicación con la tarjeta
}
```
