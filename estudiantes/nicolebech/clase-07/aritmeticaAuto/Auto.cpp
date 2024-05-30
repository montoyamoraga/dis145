// Crear clases para despues hacer logica


#include "Auto.h"           // copia todo lo que esta en el archivo .h y lo pega en este

Auto::Auto()         {      // dentro de la clase Auto la funcion Auto, indica las condiciones inciales del constructor
  velocidad = 0;           // el auto parte estacionado
  combustible = 1.0;       // el auto parte con combustible lleno


}

Auto::frenar()       {
velocidad = 0;              // cada vez que frene, este frenara en seco
}

Auto::acelerar() {
  velocidad++;
  if(velocidad > 50) {
    velocidad + 50:
  }

}
