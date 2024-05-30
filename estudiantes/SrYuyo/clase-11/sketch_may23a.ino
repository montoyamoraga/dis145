//versión para tener una conexión entre arduino y procesing, con tal de encender un led mediante un sketch de procesing, además la conección es
// tanto de arduino hacia processing como de proccesing a arduino
//Codigo origen de Chepecarlos y editado por SrYuyo
//placa arduino uno R3
//versión arduino 2.3.2

int led_1=13;
int boton=8;
bool estadoBoton=false;


Serial.begin(9600);
pinMode(led_1, OUTPUT);
pinMode(boton, INPUT);

}

void loop() {
  if (Serial .available()){
    char letra=Serial.read();
    
    if (letra =='H'){
      digitalWrite(led_1, 1);
    }

    else if (letra == 'L') {
      digitalWrite(led_1, 0); 
    }
  }

  if (digitalRead(boton) == 1 && estadoBoton == false){
    Serial.println('H')
  }
  else if (digitalRead(boton)==0 && estadoBoton == true){
    Serial.println('L');
    estadoBoton=false;
  }
  delay(100);
}
