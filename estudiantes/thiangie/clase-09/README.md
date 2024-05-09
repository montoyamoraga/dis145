# clase-09
## Primer intento de hacer elcódigo para sintetizador de emociones
### Utilización de dos códigos (referidos dentro del creado por mi)

```
/* abril, 2024
thiare gonzalez
versión 1
referencia de código: https://www.youtube.com/watch?v=96HVTZa4-PA&ab_channel=AirRoom
revisar el ejemplo frequenncyModulation (proveniente de processing) creado por Damien Di Frede
*/

//bibliotecas necesarias para generar sonido
import ddf.minim.*;
import ddf.minim.ugens.*;

// mensaje transmitido en pantalla
String mensaje = "RAGE";
// crear una lista que ingrese cada carácter individualmente
ArrayList<Caracter> caracteres = new ArrayList<Caracter>();
float kerling = 20;

PFONT = fuente;

//variables que serán utilizadas durante el código
Minim minim;
AudioOutput out;

Oscil fm;

void setup()
{
  // dibujar la pantalla donde se proyectará la visualización de las ondas
  size( 1000, 1000, P3D);
  fuente = loadFont("HelveticaNeue-Bold-200.vlw");
  
  // iniciar los objetos que responden a las variables minim y out
  minim = new Minim( this );
  out = minim.getLineOut();
  
  // crear la onda oscilatoria que se escuchará
  // parámetros/Argumentos: frecuencia, amplitud, forma de la onda
  Oscil rojo = new Oscil( 400, 0.8, Waves.TRIANGLE );
  
  fm = new Oscil( 15, 5, Waves.SINE);
  
  fm.offset.setLastValue( 200 );
  fm.patch( rojo.frequency );
  rojo.patch( out );
  
  // parámetros para el texto
  
  textFont(fuente);
  fill(220);
  textAlign(CENTER, CENTER);
  float x = width/3;
  float y = height/2;
  
  // volver cada caracter en un objeto
  for (int i = 0; 1 < mensaje.length(); i++) {
    char c = mensaje.charAt(i);
    Caracter caracter = new Caracter(c, x, y);
    caracteres.add(caracter);
    x -= kerling;
    x += textWidth(c);
  }
}

class Caracter {
  char valor;
  float x, y;
  float homeX, homeY;
  float velocidad = 0.05;
  
  Caracter(char valor, float x, float y) {
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
    x += random(-10, 10);
    y += random(-10, 10);
  }
  
  void returnHome() {
    x = lerp(x, homeX, velocidad);
    y = lerp(y, homeY, velocidad);
  }
}

void draw()
{
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

void mouseMoved()
{
  float modulateAmount = map( mouseY, 0, height, 220, 1 );
  float modulateFrequency = map( mouseX, 0, width, 0.1, 100 );
  
  fm.setFrequency( modulateFrequency );
  fm.setAmplitude( modulateAmount );
}

```
