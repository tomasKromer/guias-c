#include "punto.hpp"
#include <cmath>

void punto::punto()
{
  this->coordenaX = 0;
  this->coordenaY = 0;
}

void punto::punto(int x, int y)
{
  this->coordenaX = x;
  this->coordenaY = y;
}

void punto::ingresarCoordenadas()
{
  int auxX;
  int auxY;
  int confirmar;

  do{
    cout << "\nIngresar coordenada X\n";
    cin >> auxX;
    cin.ignore();
    cout << "\nIngresar coordenada Y\n";
    cin >> auxY;
    cin.ignore();

    cout << "\nCoordenada X ingresada " << auxX << endl;
    cout << "\nCoordenada Y ingresada " << auxY << endl;

    cout << "\nLos datos son correctos '1' para confirmar\n";
    cin >> confirmar;
    cin.ignore();
  }while(confirmar != 1);

  this->coordenaX = auxX;
  this->coordenaY = auxY;
}

void empleado::mostrarDatos()
{
  cout << "\nCoordenadas: (" << this->coordenaX << ", " << this->coordenaY <<")" endl;
}

void empleado::distanciaAlOrigen()
{
  int distancia;

  distancia = sqrt(pow(coordenaX,2)+pow(coordenaY,2));
  cout << "\nLa distancia al origen es " << distancia << endl;
}
