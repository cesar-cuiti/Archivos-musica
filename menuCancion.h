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
        cout<<"     *************MENÚ CANCIONES*************"<<endl<<endl;
        cout<<"          1. AGREGAR CANCIÓN"<<endl;
        cout<<"          2. LISTAR CANCIÓN POR ID"<<endl;
        cout<<"          3. LISTAR TODAS LAS CANCIONES"<<endl;
        cout<<"          4. MODIFICAR FECHA DE ESTRENO"<<endl;
        cout<<"          5. ELIMINAR CANCIÓN"<<endl;
        cout<<"          6. REESTABLECER CANCIÓN"<<endl;
        cout<<"          0. VOLVER AL MENÚ PRINCIPAL"<<endl<<endl;
        cout<<"     ****************************************"<<endl;
        cout<<" >> OPCIÓN: ";
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
                    cout<<"CANCIÓN ELIMINADA EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 6: if(altaCancion()==true){
                    cout<<"CANCIÓN DADA DE ALTA EXITOSAMENTE";}
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
