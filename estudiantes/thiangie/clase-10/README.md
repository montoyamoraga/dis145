# clase-10
## Códigos individuales de cada cosa
### Emisión de sonido onda color rojo
Esta onda se manipula por medio del movimiento del mouse, lo cual se espera que se pueda reproducir con un potenciómetro para poder emular el "caos" de la emoción, que, en este caso, es la rabia.

```
// mayo 16, 2024
// thiare gonzalez
// version 1.5
// cambiar minim por sound
// se realizaran ondas que simulen los colores de arcoiris que permitan demostrar emociones controlando el computador
// color rojo

// importar bibliotecas de sonido
import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
Oscil fm;

void setup() {
  // dibujar pantalla que proyecta la visualizacion de los elementos
  size(750, 500, P3D);
  
  // iniciar los objetos que responden a las variables minim y out
  minim = new Minim(this);
  out = minim.getLineOut();
  
  // crear la onda que se escuchara
  // parametros para la onda: frecuencia, amplitud y forma de la onda
  Oscil rojo = new Oscil(400, 0.8, Waves.TRIANGLE);
  
  // onda 2
  fm = new Oscil(15, 5, Waves.SINE);
  fm.offset.setLastValue(200);
  fm.patch(rojo.frequency);
  rojo.patch(out);
}

void draw() {
  background( 255, 0, 0 );
  stroke( 0 );
  for (int i = 0; i < out.bufferSize() - 1; i++)
  {
    float x1 = map( i, 0, out.bufferSize(), 0, width);
    float x2 = map(i+1, 0, out.bufferSize(), 0, width);

    line( x1, 50 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
    line( x2, 150 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
  }
  text( "Modulation frequency: " + fm.frequency.getLastValue(), 5, 15 );
  text( "Modulation amplitude: " + fm.amplitude.getLastValue(), 5, 30 );
}

void mouseMoved() {
  float modulateAmount = map( mouseY, 0, height, 220, 1 );
  float modulateFrequency = map( mouseX, 0, width, 0.1, 100 );

  fm.setFrequency( modulateFrequency );
  fm.setAmplitude( modulateAmount );
}
```
### Código de la palabra
En este caso se hace que la palabra "RABIA" se distorsione al apretar el mouse, lo que también se espera que se pueda hacer con el potenciométro en el modelo físico del producto.
*Subir el código está en los pendientes*

## Código unido
Se esperó que se mezclaran, pero un *happy accidente* que logró que se realizara una gráfica totalmente distinta a la esperada, pero que proyecta de una manera más caótica la esencia de la emoción.

### Código

```
import ddf.minim.*;
import ddf.minim.ugens.*;

String mensaje = "R A B I   A";

ArrayList<Caracter> caracteres = new ArrayList<Caracter>();
float kerling = 20;

Minim minim;
AudioOutput out;
Oscil fm;

void setup() {
  // dibujar pantalla que proyecta la visualizacion de los elementos
  size(750, 500, P3D);
  background(255, 0, 0);
  
  // iniciar los objetos que responden a las variables minim y out
  minim = new Minim(this);
  out = minim.getLineOut();
  Oscil rojo = new Oscil(400, 0.8, Waves.TRIANGLE);
  
  // onda 2
  fm = new Oscil(15, 5, Waves.SINE);
  fm.offset.setLastValue(200);
  fm.patch(rojo.frequency);
  rojo.patch(out);
  
  PFont fuente;
  fuente = loadFont("HelveticaNeue-Bold-48.vlw");
  textFont(fuente, 150);
  fill(255, 0, 0);
  textAlign(CENTER, CENTER);
  float x = width/3;  
  float y = height/2;
  
  for (int i = 0; i < mensaje.length(); i++) {
    char c = mensaje.charAt(i);
    Caracter caracter = new Caracter(c, x, y);
    caracteres.add(caracter);
    x -= kerling;
    x += textWidth(c);
  }
  
}

void draw() {
  background(0);
  stroke( 0 );
  for (int i = 0; i < out.bufferSize() - 1; i++)
  {
    float x1 = map( i, 0, out.bufferSize(), 0, width);
    float x2 = map(i+1, 0, out.bufferSize(), 0, width);

    line( x1, 50 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
    line( x2, 150 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
  }
  text( "Modulation frequency: " + fm.frequency.getLastValue(), 5, 15 );
  text( "Modulation amplitude: " + fm.amplitude.getLastValue(), 5, 30 );
}

void mouseMoved() {
  float modulateAmount = map( mouseY, 0, height, 220, 1 );
  float modulateFrequency = map( mouseX, 0, width, 0.1, 100 );

  fm.setFrequency( modulateFrequency );
  fm.setAmplitude( modulateAmount );
  
  for (Caracter c : caracteres) {
    c.display();
    
    if (mousePressed) {
      c.shake();
      fill(180, 0, 0);
      
    } else {
      c.returnHome();
      fill(255, 0, 0);
    }
  }
}
```

### Clase utilizada
```
class Caracter {
  char valor;
  float x, y;
  
  // hogar en x e y para el string, estado "normal"
  float homeX, homeY;
  float velocidad = 0.05;

  Caracter(char valor, float x, float y) {
    // posiciones de cada caracter
    this.valor = valor;
    this.x = x;
    this.y = y;
    this.homeX = x;
    this.homeY = y;
  }

  void display() {
    text(valor, x, y);
  }

  void shake() {
    // determina cuánto se va a mover
    x += random(-10, 10);
    y += random(-10, 10);
  }

  void returnHome() {
    
    // el lerp suaviza la llegada al hogar
    // x indica en dónde está y homeX a donde quiere llegar
    x = lerp(x, homeX, velocidad);
    y = lerp(y, homeY, velocidad);
  }
}
```
### Resultado visual

https://github.com/thiangie/dis145/assets/100184098/9f90d314-0ce1-4aac-ba13-41356fedb5ea


