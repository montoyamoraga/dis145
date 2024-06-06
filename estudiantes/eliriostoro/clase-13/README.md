# clase 13
solucionado el tema de arduino :) . se solda el sensor de sonido
![image](https://github.com/eliriostoro/dis145/assets/95258783/40c1996f-d422-4b6b-8ec4-9761a938e342)
 y se intenta hacer el circuito
 ![image](https://github.com/eliriostoro/dis145/assets/95258783/ecf7a9f0-3b22-4759-8bba-b66759807de3)
 lamentablemente me doi cuenta que necesito cables macho hembra.

 ----> los compre, llegan mañana 07/06/2024

 ### funcionamiento de sensor de sonido

 ![image](https://github.com/eliriostoro/dis145/assets/95258783/95238a3c-ed59-4e22-847b-eba5eecab580)
 
### funcionamiento de diodo
![image](https://github.com/eliriostoro/dis145/assets/95258783/43916f92-08e0-4904-87a9-5c4734ef9073)

----> nace el problema del color amarillo, asi que debere cambiar el codigo por un color azul

#### codigo

```
const int microfono = A0; // Pin del sensor de micrófono
const int rojo = 9;  // Pin rojo
const int verde = 10; // Pin verde
const int azul = 11;  // Pin azul

void setup() {
  pinMode(microfono, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(microfono);

//los micValue estan en veremos cuando sean probados en la vida real

  if (micValue < 200) {
    setColor(0, 0, 255); // azul ruido bajo
  } else if (micValue < 400) {
    setColorsetColor(0, 255, 0); // verde ruido medio
  } else {
    setColor(255, 0, 0); // Rojo ruido alto
  }
  
  Serial.println(micValue);
  delay(100); 
}

void setColor(int red, int green, int blue) {
  analogWrite(rojo, red);
  analogWrite(verde, green);
  analogWrite(azul, blue);
}

```

### cosas que podría necesitar:


```

  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);


```



