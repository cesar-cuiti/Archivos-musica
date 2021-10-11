#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void menuReportes();
void cargarCadena(char *pal, int tam);
int cancionesPorAutor(const char *);


///DESAROLLO DE FUNCIONES
void menuReportes(){
    int opc;
    char aut[30];

    while(true){
             system("cls");
        cout<<endl;
        cout<<"      *************MEN� REPORTES*************"<<endl<<endl;
        cout<<"      1. MOSTRAR POR INT�RPRETE LA CANT. DE CANCIONES"<<endl;
        cout<<"      2. A�O CON M�S ESTRENOS DE CANCIONES DEL SIGLO"<<endl;
        cout<<"      3. LISTAR CANCIONES DE INT�RPRETE"<<endl;
        cout<<"      4. GENERAR ARCHIVO DE M�SICA CL�SICA"<<endl;
        cout<<"      5. ESTRENOS ANTERIORES AL 2010 "<<endl;
        cout<<"      0. VOLVER AL MEN� PRINCIPAL"<<endl<<endl;
        cout<<"      ***************************************"<<endl;

        cout<<" >> OPCI�N: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:MostrarCantCancInt();
                    break;
            case 2:AnioMasCanciones();
                    break;
            case 3:MostrarCancionesDeInterprete();
                    break;
            case 4:CrearArchivoClasico();
                    break;
            case 5:
                    break;
            case 0:return;
            default: cout<<"OPCION INCORRECTA"<<endl;
                system("pause>null");
                    break;
        }
        system("pause>nul");

    }
    }


#endif // REPORTES_H_INCLUDED
