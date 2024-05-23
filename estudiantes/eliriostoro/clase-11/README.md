# clase-11 ACELERADOR
Ateriizacion del proyecto:
Lentes
Detectar amplitud de sonido
apartir de la amplitud de sonido jugar con luces

Compra de materiales:

sensor de sonido ANALOGO
https://articulo.mercadolibre.cl/MLC-492489125-max4466-amplificador-microfono-electret-arduino-raspberry-_JM

Arduino uno R4 WIFI
https://arduino.cl/producto/arduino-uno-r4-wifi/

Diodo Led RGB 5mm
https://articulo.mercadolibre.cl/MLC-1729399308-diodo-led-rgb-5mm-catodo-comun-superbrillantes-25-unidades-_JM?variation=179329896027

## proceso:
se intento modelar por tinkercad y wokwik pero no tenian este sensor. se busco mas info respecto al sensor 
max9814 (ANALOGO) probablemente tenga que soldarlo.

ejemplos de codigo con el sensor:

´´´

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;


void setup() 
{
 
   Serial.begin(9600);
   analogReference(EXTERNAL);
   pinMode (7, OUTPUT);
   digitalWrite (7,0);

}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
        sample = analogRead(0);
        if (sample < 1024)  // toss out spurious readings
        {
           if (sample > signalMax)
           {
              signalMax = sample;  // save just the max levels
           }
           else if (sample < signalMin)
           {
              signalMin = sample;  // save just the min levels
           }
        }
     }
     peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
     double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
  
    if (volts > 0.03)
     {
     digitalWrite (7,1);
     }
  
    else
    {
      digitalWrite (7,0);
    }
  
     
     Serial.println(volts);

  
  }
  
  ´´´
  

