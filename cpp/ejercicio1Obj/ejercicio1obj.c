#include <iostream>
#include "empleado.hpp"

#define EMPLEADOS_CANT 5

int main();

int main()
{
  empleado empleadosInst[EMPLEADOS_CANT];

  cout << "\nIngrese datos del empleado\n";
  for(int i = 0;i < EMPLEADOS_CANT;i++)
  {
      empleadosInst.ingresarDatos();
  }

  cout << "\nLos datos ingresados del empleado\n";
  for(int i = 0;i < EMPLEADOS_CANT;i++)
  {
      empleadosInst.mostrarDatos();
  }

}
