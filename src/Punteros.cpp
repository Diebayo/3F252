#include<iostream>
#include<string>
#include<list>
using namespace std;

class Humano{
private:
   string nombre;
   int edad;
public:
  string LeerNombre();
  int LeerEdad();
  
};

class Alumno: public Humano{
   private:
    int registro;
public: 
 int LeerRegisro();

};

class Empleado : public Humano{
private: 
 long noEmpleado;
public:
 long LeerNumeroEmpleado();
};

int main(int argc, char const *argv[])
{
    Humano* humano = NULL;
    Alumno* alumno = new Alumno ();
    Empleado* empleado = new Empleado ();

  humano = alumno;
  humano->LeerEdad();

  humano = empleado;
  humano->LeerEdad();

  list<Humano*>listahumanos;
  listahumanos.emplace_back(new Alumno()); 
  listahumanos.emplace_back(new Alumno()); 
  listahumanos.emplace_back(new Alumno()); 
  listahumanos.emplace_back(new Alumno()); 
  listahumanos.emplace_back(new Empleado()); 
  listahumanos.emplace_back(new Empleado());
  listahumanos.emplace_back(new Empleado());
  listahumanos.emplace_back(new Empleado());
   

  for (auto &&humano : listahumanos)
  {
    cout <<humano->LeerNombre() << endl;
  }


    return 0;
}
