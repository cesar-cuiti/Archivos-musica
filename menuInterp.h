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
        cout<<"     *************MEN� INT�RPRETES*************"<<endl<<endl;
        cout<<"           1. AGREGAR INT�RPRETE"<<endl;
        cout<<"           2. LISTAR INT�RPRETE POR ID"<<endl;
        cout<<"           3. LISTAR TODOS LOS INT�RPRETES"<<endl;
        cout<<"           4. MODIFICAR TIPO DE M�SICA"<<endl;
        cout<<"           5. ELIMINAR INT�RPRETE"<<endl;
        cout<<"           6. REESTABLECER INT�RPRETE"<<endl;
        cout<<"           0. VOLVER AL MEN� PRINCIPAL"<<endl<<endl;
        cout<<"     *****************************************"<<endl<<endl;

        cout<<" >> OPCI�N: ";
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
                    cout<<"TIPO DE M�SICA MODIFICADO EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 5: if(eliminarInterprete()==true){
                    cout<<"INT�RPRETE ELIMINADO EXITOSAMENTE";}
                    system("pause>null");
                    break;
            case 6: if(altaInterprete()==true){
                    cout<<"INT�RPRETE DADO DE ALTA EXITOSAMENTE";}
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
