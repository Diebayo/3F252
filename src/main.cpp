#include <iostream>
#include <Foco.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"hola mundo"<<endl; 
     Foco foco;
     foco.Encender();
     cout<< foco.LeerEstado() << endl;
    
     return 0;
}

