

#include "Auto.h"


Auto::Auto() {
  velocidad = 0;
  combustible = 1.0;
}

// esta funcion es para que el auto frene
Auto::frenar() {
  this.velocidad = 0;
}

Auto::acelerar() {
  velocidad++;
  if (velocidad > 50) {
    velocidad = 50;
    }
}
