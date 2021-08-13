#include "empleado.hpp"

void empleado::ingresarDatos()
{
  string auxName;
  int auxId;
  int confirmar;

  confirmar = 0;

  do{
    cout << "\nIngresar nombre del empleado\n";
    getline(cin, auxName);
    cout << "\nIngresar id del empleado\n";
    cin >> auxId;
    cin.ignore();

    cout << "\nEl nombre ingresado " << auxName << endl;
    cout << "\nEl id ingresado " << auxId << endl;

    cout << "\nLos datos son correctos '1' para confirmar\n";
    cin >> confirmar;
  }while(confirmar != 1);

  this->nombre = auxName;
  this->id = auxId;
}

void empleado::mostrarDatos()
{
  cout << "\nNombre de empleado: " << this->nombre << endl;
  cout << "\nID de empleado: " << this->id << endl;
}
