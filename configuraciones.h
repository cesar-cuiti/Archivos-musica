#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED

void menuConfiguracion();


///DESAROLLO DE FUNCIONES
void menuConfiguracion(){
    int opc;

    while(true){
    system("cls");
        cout<<endl;
        cout<<"      *************MEN� CONFIGURACI�N*************"<<endl<<endl;
        cout<<"      1. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES"<<endl;
        cout<<"      2. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE INT�RPRETES"<<endl;
        cout<<"      3. RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
        cout<<"      4. RESTAURAR EL ARCHIVO DE INT�RPRETES"<<endl;
        cout<<"      5. ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"      0. VOLVER AL MEN� PRINCIPAL"<<endl<<endl;
        cout<<"      ********************************************"<<endl;
        cout<<" >> OPCI�N: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(BackUpCanciones()==true){cout<<"BACKUP DE CANCIONES EXITOSO";}
                    break;
            case 2: if(BackUpInterpretes()==true){cout<<"BACKUP DE INT�RPRETES EXITOSO";}
                    break;
            case 3: if(RestaurarCanciones()==true){cout<<"RESTAURACI�N EXITOSA DE CANCIONES";}
                    break;
            case 4: if(RestaurarInterpretes()==true){cout<<"RESTAURACI�N EXITOSA DE INT�PRETES";}
                    break;
            case 5: if(EstablecerInicio()==true){cout<<"DATOS DE INICIO CARGADOS EXITOSAMENTE";}
                    break;
            case 0:return;
            default: cout<<"OPCION INCORRECTA"<<endl;
                system("pause>null");
                    break;
        }
        system("pause>nul");

    }
    }

#endif // CONFIGURACIONES_H_INCLUDED
