#include <list>
#include <iostream>
#include <string>

using namespace std;

class vistas
{
  public:
    virtual void verDatos(list<float> temp, list<float> hum, list<float> pressure) = 0;
};

class VActual : public vistas
{
public:
  virtual void verDatos(list<float> temp, list<float> hum, list<float> pressure);
};

void VActual::verDatos(list<float> temp, list<float> hum, list<float> pressure)
{
    cout << "Datos Actuales:  \nTemp" << to_string(temp.back()) << "° . Humedad " << to_string(hum.back()) << "%. Presion: " << to_string(pressure.back()) << ".\n";
}

class VProm : public vistas
{
public:
  virtual void verDatos(list<float> temp, list<float> hum, list<float> pressure);
};

void VProm::verDatos(list<float> temp, list<float> hum, list<float> pressure)
{
  float prom;
  float min;
  float max;
  int i;

  prom = 0;
  i=0;
  for (std::list<float>::iterator it=temp.begin(); it != temp.end(); ++it)
  {
    if(i==0)
    {
      min = *it;
      max = *it;
      i++;
    }
    else
    {
      if(min > *it)
      {
        min = *it;
      }

      if(max < *it)
      {
        max = *it;
      }
    }
    prom += *it;
  }

  prom = prom / temp.size();

  cout << "Avg/min/max Temp " << to_string(prom) << "° . " << to_string(min) << "°. " << to_string(max) << "°.\n";

}

class VSimple : public vistas
{
public:
  virtual void verDatos(list<float> temp, list<float> hum, list<float> pressure);
};

void VSimple::verDatos(list<float> temp, list<float> hum, list<float> pressure)
{
  if(temp.back()>25)
  {
    cout << "Que calor !!!\n";
  }
  else if(temp.back()>15)
  {
    cout << "Agradable\n";
  }
  else
  {
    cout << "Que frio!!!!\n";
  }
}

int main()
{
    list<float> temp;
    list<float> hum;
    list<float> pressure;
    int aux;
    vistas * vista1 = new VActual;
    vistas * vista2 = new VProm;
    vistas * vista3 = new VSimple;

    while(1)
    {
      cout << "Ingrese datos de temp, humedad y presion \n";
      cout << "Ingrese dato de temp.\n";
      cin >> aux;
      cin.ignore();
      temp.push_back(aux);

      cout << "Ingrese dato de Humedad.\n";
      cin >> aux;
      cin.ignore();
      hum.push_back(aux);

      cout << "Ingrese dato de Presion.\n";
      cin >> aux;
      cin.ignore();
      pressure.push_back(aux);

      vista1->verDatos(temp,hum,pressure);
      vista2->verDatos(temp,hum,pressure);
      vista3->verDatos(temp,hum,pressure);

      cout << "Si desea repetir ingrese '1' \n";
      cin >> aux;
      cin.ignore();

      if(aux!=1)
      {
        cout << "Gracias por usar este magnifico programa' \n";
        break;
      }
    }
  
  return 0;
}
