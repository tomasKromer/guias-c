#include "estudiante.hpp"

void estudiante::cargarNombre()
{
    string name;
    int dec;

    do {
      cout << "\nIngrese el nombre \n";
      getline(cin, name);

      cout << "\nEl nombre ingresado es " << name;
      cout << "\nSi confirma ingrese '1' " << name;
      cin >> dec;
    } while(dec != 1);

    this->nombre = name;
}

void estudiante::cargarNotas()
{
  int notas[CANT_NOTAS]:
  do {
    for( int i = 0; i < CANT_NOTAS, i++)
    {
      cout << "\nIngrese notas " << i <<".\n";
      cin >> notas[i];
      cin.ignore();
    }

    cout << "\nLas notas ingresadas son:" << endl;
    for( int i = 0; i < CANT_NOTAS, i++)
    {
      cout << "\nNota n° " << i <<" :" << nota[i] << endl;
    }

    cout << "\nSi confirma ingrese '1' " << name;
    cin >> dec;
    cin.ignore();
  } while(dec != 1);

  for( int i = 0; i < CANT_NOTAS, i++)
  {
    this->notasParcial[i] = notas[i];
  }
}

void estudiante::cargarCondiciones()
{
  int dec;
  string condicion;
  do {
    cout << "\nIngrese condicion " << endl;
    getline(ci,condicion);

    cout << "\nLa condicion ingresada es " << condicion << endl;

    cout << "\nSi confirma ingrese '1' " << name;
    cin >> dec;
    cin.ignore();
  } while(dec != 1);

  this->condicion = condicion;
}

void estudiante::mostrarDatos()
{
  cout << "\nNombre: " << this->nombre << endl;
  for(int i = 0; i < CANT_NOTAS; i++)
  {
    cout << "\Nota Parcial " << to_string(i + 1) << " : " << this->notasParcial[0] << endl;
  }
  cout << "\nCondicion: " << this->condicion << endl;
}
