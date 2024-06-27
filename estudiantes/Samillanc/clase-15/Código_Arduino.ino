#include <Stepper.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del motor paso a paso
#define STEPS 2048
Stepper stepper(STEPS, 8, 10, 9, 11);

// Configuración del servo
Servo myservo;
int servoPin = 3;

// Configuración de la pantalla LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Configuración del joystick
int joySW = 2;
int joyX = A0;
int joyY = A1;

// Variables de control
long lastTime = 0;
bool fastChangeMode = false;
int motorSpeed = 10; // Velocidad del motor por defecto

// Funciones del escáner
enum Mode {IDLE, PHOTOGRAMMETRY, VIDEOGRAMMETRY, CINEMATIC, STOPMOTION};
Mode currentMode = IDLE;

void setup() {
  // Inicialización del motor paso a paso
  stepper.setSpeed(motorSpeed); // Velocidad en RPM

  // Inicialización del servo
  myservo.attach(servoPin);

  // Inicialización de la pantalla LCD
  lcd.init();
  lcd.backlight();

  // Configuración de los pines del joystick
  pinMode(joySW, INPUT);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);

  // Mensaje inicial en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("3D Scanner");
  lcd.setCursor(0, 1);
  lcd.print("Ready");
}

void loop() {
  // Leer el estado del joystick
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);
  int buttonState = digitalRead(joySW);

  // Controlar el cambio rápido del motor
  if (millis() - lastTime > 1000) {
    fastChangeMode = true;
  }

  // Controlar el cambio rápido del motor
  if (fastChangeMode) {
    if (xVal < 400) {
      motorSpeed -= 1;
      if (motorSpeed < 1) motorSpeed = 1;
    } else if (xVal > 600) {
      motorSpeed += 1;
      if (motorSpeed > 17) motorSpeed = 17; // Suponiendo 17 valores posibles
    }
    stepper.setSpeed(motorSpeed);
    lcd.setCursor(0, 1);
    lcd.print("Speed: ");
    lcd.print(motorSpeed);
    fastChangeMode = false;
  }

  // Resetear el modo rápido de cambio
  if (xVal > 400 && xVal < 600) {
    lastTime = millis();
    fastChangeMode = false;
  }

  // Cambiar de modo
  if (buttonState == LOW) {
    if (millis() - lastTime > 2000) {
      switch (currentMode) {
        case IDLE:
          currentMode = PHOTOGRAMMETRY;
          lcd.setCursor(0, 0);
          lcd.print("Photogrammetry");
          break;
        case PHOTOGRAMMETRY:
          currentMode = VIDEOGRAMMETRY;
          lcd.setCursor(0, 0);
          lcd.print("Videogrammetry");
          break;
        case VIDEOGRAMMETRY:
          currentMode = CINEMATIC;
          lcd.setCursor(0, 0);
          lcd.print("Cinematic");
          break;
        case CINEMATIC:
          currentMode = STOPMOTION;
          lcd.setCursor(0, 0);
          lcd.print("Stop Motion");
          break;
        case STOPMOTION:
          currentMode = IDLE;
          lcd.setCursor(0, 0);
          lcd.print("Idle");
          break;
      }
      delay(500); // Añadir un pequeño retraso para evitar cambios rápidos
      lastTime = millis();
    }
  }

  // Ejecutar funciones según el modo
  switch (currentMode) {
    case PHOTOGRAMMETRY:
      // Configuración para fotogrametría
      motorSpeed = 5;
      stepper.setSpeed(motorSpeed);
      photogrammetry();
      break;
    case VIDEOGRAMMETRY:
      // Configuración para videogrametría
      motorSpeed = 2;
      stepper.setSpeed(motorSpeed);
      videogrammetry(buttonState);
      break;
    case CINEMATIC:
      // Configuración para cinematografía
      motorSpeed = 10;
      stepper.setSpeed(motorSpeed);
      cinematic();
      break;
    case STOPMOTION:
      // Configuración para stop motion
      motorSpeed = 1;
      stepper.setSpeed(motorSpeed);
      stopMotion();
      break;
    case IDLE:
      // Modo inactivo
      motorSpeed = 0;
      stepper.setSpeed(motorSpeed);
      break;
  }
}

void photogrammetry() {
  // Lógica para capturar imágenes
  // Mueve el servo para presionar el botón de disparo de la cámara
  myservo.write(90); // Ajusta este valor según la posición del botón de disparo
  delay(1000); // Espera a que se tome la foto
  myservo.write(0); // Vuelve el servo a la posición inicial
  delay(1000); // Espera antes de la siguiente captura
}

void videogrammetry(int buttonState) {
  // Lógica para captura continua de video
  if (buttonState == LOW) {
    myservo.write(90); // Mantiene presionado el botón de disparo
  } else {
    myservo.write(0); // Suelta el botón de disparo
  }
}

void cinematic() {
  // Lógica para giros suaves y controlados
  stepper.step(STEPS / 100); // Mueve el motor en pasos suaves
  delay(100); // Ajusta el tiempo según el movimiento deseado
}

void stopMotion() {
  // Lógica para capturas de cuadros individuales
  stepper.step(STEPS / 100); // Mueve el motor un paso pequeño
  delay(1000); // Espera antes de la siguiente captura
  myservo.write(90); // Presiona el botón de disparo
  delay(1000); // Espera a que se tome la foto
  myservo.write(0); // Vuelve el servo a la posición inicial
}
