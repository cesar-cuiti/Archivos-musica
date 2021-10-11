#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale.h>
#include <time.h>

using namespace std;

#include "objetos.h"
#include "menuCancion.h"
#include "menuInterp.h"
#include "funciones.h"
#include "reportes.h"
#include "configuraciones.h"
#include "Parcial_Cuitiño.h"

int main()
{

     setlocale(LC_ALL,"Spanish");
    int opc;
    while(true){
         system("cls");
           cout<<endl;
           cout<<"     *************MENÚ PRINCIPAL*************"<<endl<<endl;
           cout<<"           1. MENÚ CANCIONES"<<endl;
           cout<<"           2. MENÚ INTÉRPRETES"<<endl;
           cout<<"           3. REPORTES"<<endl;
           cout<<"           4. CONFIGURACIONES"<<endl;
           cout<<"           0. FIN DEL PROGRAMA"<<endl<<endl;
           cout<<"     ***************************************"<<endl;
           cout<<"  >> OPCIÓN: ";
           cin>>opc;
        system("cls");
        switch(opc){
            case 1:menuCanciones();
                    break;
            case 2:menuInterpretes();
                    break;
            case 3:menuReportes();
                    break;
            case 4:menuConfiguracion();
                    break;
            case 0: cout<<"GRACIAS POR UTILIZAR NUESTRO PROGRAMA!";
                system("cls");
                return 0;
                    break;

            default:cout<<"OPCION INCORRECTA"<<endl;
                system("pause>null");
                    break;

        }

    }

}

