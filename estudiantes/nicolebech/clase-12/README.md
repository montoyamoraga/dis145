# clase-12
Fecha: 06/06/2024


# Misión 01) 
- Hacer funcionar el lector comprado
- Estado = Logrado✅

Para comenzar a trabajar con el proyecto, se hizo pruebas del Lector RFID. Para esto se utilizó el lector con la tarjeta que trae y se probó directamente desde los ejemplos de arduino. En el vídeo se observa que el lector sirve y que efectivamente se detecta cuando la tarjeta se acerca al lector. Esto se observa en la consola que comienza a mostrar información al acercar la tarjeta. 




https://github.com/nicolebech/dis145/assets/164402586/02a4d33e-dac5-46bf-b56d-465302aa8810

Sensor utilizado: Módulo de RFID-RC522
<img width="855" alt="Captura de pantalla 2024-06-06 a la(s) 18 17 59" src="https://github.com/nicolebech/dis145/assets/164402586/5b1cae81-15b7-4f4b-a4ba-4da21042d45d">


```
#include <SPI.h>          // Incluye la biblioteca SPI para comunicación SPI
#include <MFRC522.h>      // Incluye la biblioteca MFRC522 para el lector RFID

#define RST_PIN 9         // Pin de reset, configurable según el layout típico de pines
#define SS_PIN 10         // Pin de selección de esclavo (SS), configurable según el layout típico de pines

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Crea una instancia del lector MFRC522

```
```
void setup() {
    Serial.begin(9600);  // Inicializa la comunicación serial con el PC a 9600 baudios
    while (!Serial);     // Espera hasta que se abra el puerto serial (añadido para Arduinos basados en ATMEGA32U4)
    SPI.begin();         // Inicializa el bus SPI
    mfrc522.PCD_Init();  // Inicializa el lector MFRC522
    delay(4);            // Retraso opcional. Algunas placas necesitan más tiempo después de la inicialización para estar listas
    mfrc522.PCD_DumpVersionToSerial();  // Muestra detalles del lector MFRC522
    Serial.println(F("Escanea una tarjeta para ver UID, SAK, tipo y bloques de datos..."));
}
```
```
void loop() {
    // Reinicia el bucle si no hay una nueva tarjeta presente en el sensor/lector.
    // Esto ahorra todo el proceso cuando está inactivo.
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Selecciona una de las tarjetas
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Muestra información de depuración sobre la tarjeta; PICC_HaltA() se llama automáticamente
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
```

