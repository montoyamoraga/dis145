
// que es sumar tres numeros
int sumar3(int x0, int x1, int x2) {
  int suma = x0 + x1 + x2;
  return suma;
}

int restar4(int x0, int x1, int x2, int x3) {
  int resta = x0 - x1 - x2 - x3;
  return resta;
}

float absolutoFloat(float x0) {
  if (x0 < 0) {
    return -x0;
  } else {
    return x0;
  }   
}

int absolutoInt(int x0) {
  if (x0 < 0) {
    return -x0;
  } else {
    return x0;
  }   
}
