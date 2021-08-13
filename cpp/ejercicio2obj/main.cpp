#include "punto.hpp"

int main();

int main()
{
  punto punto1(-1,5);
  punto punto2();
  cout << "\nBienvenido \n";

  punto1.mostrarDatos();
  punto1.distanciaAlOrigen();

  punto2.ingresarCoordenadas();
  punto2.mostrarDatos();
  punto2.distanciaAlOrigen();

  punto1.ingresarCoordenadas();
  punto1.mostrarDatos();
  punto1.distanciaAlOrigen();
}
