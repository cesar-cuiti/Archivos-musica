#ifndef MENUCANCION_H_INCLUDED
#define MENUCANCION_H_INCLUDED

///PROTOTIPOS
void menuCanciones(Cancion obj);
void cargarCancion();
void mostrarCancionPorID();
void mostrarCanciones();
bool modificarFechaEstreno();
bool eliminarCancion();
bool altaCancion();

///DESAROLLO DE FUNCIONES
void menuCanciones(){
    int opc;
       while(true){
    system("cls");
        cout<<endl;
        cout<<"     *************MEN� CANCIONES*************"<<endl<<endl;
        cout<<"          1. AGREGAR CANCI�N"<<endl;
        cout<<"          2. LISTAR CANCI�N POR ID"<<endl;
        cout<<"          3. LISTAR TODAS LAS CANCIONES"<<endl;
        cout<<"          4. MODIFICAR FECHA DE ESTRENO"<<endl;
        cout<<"          5. ELIMINAR CANCI�N"<<endl;
        cout<<"          6. REESTABLECER CANCI�N"<<endl;
        cout<<"          0. VOLVER AL MEN� PRINCIPAL"<<endl<<endl;
        cout<<"     ****************************************"<<endl;
        cout<<" >> OPCI�N: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:cargarCancion();
                    break;
            case 2:mostrarCancionPorID();
                    break;
            case 3:mostrarCanciones();
                    break;
            case 4: if(modificarFechaEstreno()==true){
                    cout<<"FECHA MODIFICADA EXITOSAMENTE"<<endl;}
                    system("pause>null");
                    break;
            case 5: if(eliminarCancion()==true){
                    cout<<"CANCI�N ELIMINADA EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 6: if(altaCancion()==true){
                    cout<<"CANCI�N DADA DE ALTA EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 0:return;
            default:cout<<"OPCION INCORRECTA"<<endl;
                    system("pause>null");
                    break;

        }

    }
    }


#endif // MENUCANCION_H_INCLUDED
