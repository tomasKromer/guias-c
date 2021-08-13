#include <string>

using namespace std;

#define CANT_NOTAS  3

class estudiante
{
  private:
    string nombre;
    int notasParcial[CANT_NOTAS];
    string condicion;
  public:
    void cargarNombre();
    void cargarNotas();
    void cargarCondiciones();
    void mostrarDatos();
};
