#ifndef MENUINTERP_H_INCLUDED
#define MENUINTERP_H_INCLUDED

///PROTOTIPOS
void menuInterpretes(Interprete obj);
void cargarInterprete();
void mostrarInterpretePorID();
void mostrarInterpretes();
bool modificarTipoDeMusica();
bool eliminarInterprete();
bool altaInterprete();




///DESAROLLO DE FUNCIONES
void menuInterpretes(){
    int opc;

    while(true){
             system("cls");
             cout<<endl;
        cout<<"     *************MENÚ INTÉRPRETES*************"<<endl<<endl;
        cout<<"           1. AGREGAR INTÉRPRETE"<<endl;
        cout<<"           2. LISTAR INTÉRPRETE POR ID"<<endl;
        cout<<"           3. LISTAR TODOS LOS INTÉRPRETES"<<endl;
        cout<<"           4. MODIFICAR TIPO DE MÚSICA"<<endl;
        cout<<"           5. ELIMINAR INTÉRPRETE"<<endl;
        cout<<"           6. REESTABLECER INTÉRPRETE"<<endl;
        cout<<"           0. VOLVER AL MENÚ PRINCIPAL"<<endl<<endl;
        cout<<"     *****************************************"<<endl<<endl;

        cout<<" >> OPCIÓN: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:cargarInterprete();
                    break;
            case 2:mostrarInterpretePorID();
                    break;
            case 3:mostrarInterpretes();
                    break;
            case 4: if(modificarTipoDeMusica()==true){
                    cout<<"TIPO DE MÚSICA MODIFICADO EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 5: if(eliminarInterprete()==true){
                    cout<<"INTÉRPRETE ELIMINADO EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 6: if(altaInterprete()==true){
                    cout<<"INTÉRPRETE DADO DE ALTA EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 0:return;
            default: cout<<"OPCION INCORRECTA"<<endl;
                     system("pause>null");
                    break;

        }


    }
    }




#endif // MENUINTERP_H_INCLUDED
