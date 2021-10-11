#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS

void cargarCadena(char *pal, int tam);
void cargarInterprete();
void mostrarInterpretePorID();
int buscarInterprete(int i);
void mostrarInterprete();
bool modificarTipoDeMusica();
bool eliminarInterprete();
bool altaInterprete();

void cargarCancion();
void mostrarCancionPorID();
int buscarCancion(int c);
void mostrarCancion();
bool modificarFechaEstreno();
bool eliminarCancion();
bool altaCancion();



void AnioMasCanciones();
int buscarMaximo(int *, int);
void MostrarCancionesDeInteprete();
int buscarIDInterprete(const char *);
void CrearArchivoClasico();
bool crearArchivoNuevo();


bool BackUpCanciones();
bool BackUpInterpretes();
bool RestaurarCanciones();
bool RestaurarInterpretes();
bool EstablecerInicio();

bool estadoInt(int id);


///DESAROLLO DE FUNCIONES

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


void cargarInterprete(){
    Interprete reg;

    if(reg.Cargar()==true){reg.grabarEnDisco();cout<<"INTÉRPRETE AGREGADO"<<endl;}
    else{
        cout<<"NO SE PUDO AGREGAR EL INTÉRPRETE"<<endl;
    }
    cout<<endl;
    system("pause>null");
}

void mostrarInterpretePorID(){
    Interprete reg;
    int pos, id;

    cout<<"INGRESE EL ID DEL INTÉPRETE A BUSCAR: ";
    cin>>id;
    pos=buscarInterprete(id);
    if(pos!=-1){
    reg.leerDeDisco(pos);
    reg.Mostrar();}
    else{cout<<"EL ID NO EXISTE";}
    system("pause>null");
}

int buscarInterprete(int i){
    Interprete reg;
    int pos=0;

    while(reg.leerDeDisco(pos)==true){
        if(reg.getIDInt()==i){return pos;}
        pos++;
    }
    return -1;
}

void mostrarInterpretes(){
    Interprete reg;
    int pos=0;

    while(reg.leerDeDisco(pos)==true){
    if(reg.getEstado()==true){reg.Mostrar();}
        system("pause>null");
        system("cls");
        pos++;
    }

}

bool modificarTipoDeMusica(){
    bool modifico;
    Interprete obj;
    int id, pos, tip;


    cout<<"INGRESE EL ID DEL INTÉRPRETE A MODIFICAR: ";
    cin>>id;
    pos=buscarInterprete(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";return false;}
    obj.leerDeDisco(pos);
    if(obj.getEstado()==true){
        obj.Mostrar();
        cout<<endl;
        system("pause>null");

    cout<<"INGRESE EL NUEVO TIPO DE MÚSICA: ";
    cin>>tip;
    obj.setTipoMus(tip);
    modifico=obj.modificarenDisco(pos);
        return modifico;
}
else{ cout<<"INTERPRETE DADO DE BAJA. NO SE PUDO MODIFICAR";return false;}
}

bool eliminarInterprete(){
int id,pos;
    bool elimino;
    Interprete obj;


    cout<<"INGRESE EL ID DEL INTÉRPRETE A BORRAR: ";
    cin>>id;
    pos=buscarInterprete(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";return false;}
    obj.leerDeDisco(pos);
    obj.setEstado(false);
    elimino=obj.modificarenDisco(pos);
    return elimino;
}

bool altaInterprete(){
int id,pos;
    bool alta;
    Interprete obj;


    cout<<"INGRESE EL ID DEL INTÉRPRETE A DAR DE ALTA: ";
    cin>>id;
    pos=buscarInterprete(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";return false;}
    obj.leerDeDisco(pos);
    obj.setEstado(true);
    alta=obj.modificarenDisco(pos);
    return alta;
}

void cargarCancion(){
    Cancion reg;

    if(reg.Cargar()==true){reg.grabarEnDisco();cout<<"CANCIÓN AGREGADA";}
    else{
        cout<<"NO SE PUDO AGREGAR LA CANCIÓN";
    }
    cout<<endl;
    system("pause>null");
}

void mostrarCancionPorID(){
    Cancion reg;
    int pos, id;


    cout<<"INGRESE EL ID DE LA CANCIÓN A BUSCAR: ";
    cin>>id;
    pos=buscarCancion(id);
    if(pos!=-1){
    reg.leerDeDisco(pos);
    reg.Mostrar();}
    else {cout<<"EL ID NO EXISTE";}
    system("pause>null");
}

int buscarCancion(int c){
    Cancion reg;
    int pos=0;

    while(reg.leerDeDisco(pos)==true){
        if(reg.getIDCanc()==c){return pos;}
        pos++;
    }
    return -1;
}

void mostrarCanciones(){
    Cancion reg;
    int pos=0;

    while(reg.leerDeDisco(pos)==true){
        if(reg.getEstado()==true){reg.Mostrar();}
        system("pause>null");
        system("cls");
        pos++;
    }
}

bool modificarFechaEstreno(){
    int id,pos,dia,mes,anio;
    bool modifico;
    Cancion obj;
    Fecha aux;

    cout<<"INGRESE EL ID DE LA CANCIÓN A MODIFICAR: ";
    cin>>id;
    pos=buscarCancion(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";
    system("pause>null");
    return false;}
    obj.leerDeDisco(pos);
    if(obj.getEstado()==true){
        obj.Mostrar();
        cout<<endl;
        system("pause>null");

    cout<<"INGRESE LA NUEVA FECHA: "<<endl;
    cout<<"DÍA: ";
    cin>>dia;
    aux.setDia(dia);

    cout<<"MES: ";
    cin>>mes;
    aux.setMes(mes);

    cout<<"AÑO: ";
    cin>>anio;
    aux.setAnio(anio);
    obj.setFechaEst(aux);
        modifico=obj.modificarenDisco(pos);
        return modifico;
}
else{ cout<<"CANCIÓN INACTIVA. NO SE PUEDE MODIFICAR";return false;}
}

bool eliminarCancion(){
    int id,pos;
    bool elimino;
    Cancion obj;


    cout<<"INGRESE EL ID DE LA CANCIÓN A BORRAR: ";
    cin>>id;
    pos=buscarCancion(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";
    system("pause>null");
    return false;}
    obj.leerDeDisco(pos);
    obj.setEstado(false);
    elimino=obj.modificarenDisco(pos);
    return elimino;
}

bool altaCancion(){
    int id,pos;
    bool alta;
    Cancion obj;


    cout<<"INGRESE EL ID DE LA CANCIÓN A DAR DE ALTA: ";
    cin>>id;
    pos=buscarCancion(id);
    if(pos==-1){cout<<"EL ID NO EXISTE";
    system("pause>null");
    return false;}
    obj.leerDeDisco(pos);
    obj.setEstado(true);
    alta=obj.modificarenDisco(pos);
    return alta;
}

void MostrarCantCancInt(){
   int CancionInt=0;
   FILE *pInt,*pCanc;
   Cancion obj;
   Interprete aux;
   pInt=fopen("interpretes.dat","rb");
   if(pInt==NULL){
   cout<<"NO SE PUDO ABRIR EL ARCHIVO";return;}
   while(fread(&aux, sizeof(Interprete),1,pInt)!=0){
        if(aux.getEstado()==true){

    cout<<endl<<"INTÉRPRETE "<<aux.getIDInt()<<": "<<aux.getNombre()<<endl;}
    pCanc=fopen("canciones.dat","rb");
    if(pCanc==NULL){
    fclose(pInt);
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";return;}
    while(fread(&obj, sizeof(Cancion),1,pCanc)!=0){
        if(obj.getEstado()==true){
            if(aux.getIDInt()==obj.getIDInt()){
           CancionInt++;
            }
            }
            }
    cout<<"CANTIDAD DE  CANCIONES: "<<CancionInt<<endl;
    system("pause>null");
    system("cls");
    CancionInt=0;
   }  fclose(pInt); fclose(pCanc);
}


void AnioMasCanciones(){
    Cancion reg;
    int pos=0;
    int vAnios[22]={0}, anio;
    while(reg.leerDeDisco(pos++)){
            if(reg.getEstado()==true){
        if (reg.getFechaEst().getAnio()>=2000)
            vAnios[reg.getFechaEst().getAnio()-2000]++;
    }}
    anio=buscarMaximo(vAnios, 22)+2000;
    cout<<"EL AÑO CON MÁS ESTRENOS DEL SIGLO ES: "<<anio<<endl;

}

int buscarMaximo(int *v, int tam){
    int pos=0, i, Max=v[0];
    for(i=1;i<tam;i++){
       if(Max<v[i]){Max=v[i];
       pos=i;
       }
    }
    return pos;
}

void MostrarCancionesDeInterprete(){
    Cancion reg;
    int pos=0, idInterprete, encontro=0;
    char nombre[30];

    cout<<"INGRESE NOMBRE DEL INTÉRPRETE: ";
    cargarCadena(nombre,29);
    idInterprete=buscarIDInterprete(nombre);
    if(idInterprete==-1){
        cout<<"NO EXISTE UN INTÉRPRETE CON ESE NOMBRE"<<endl;
        return;
    }
    while(reg.leerDeDisco(pos++)){
        if(reg.getIDInt()==idInterprete){
            if(reg.getEstado()==true){
            reg.Mostrar();
            encontro++;
            system("pause>null");
            }
        }
        }
    if(encontro==0){ cout<<"EL INTÉRPRETE NO TIENE CANCIONES CARGADAS";}

}

int buscarIDInterprete(const char *i){
   Interprete aux;
   int pos=0;
   while(aux.leerDeDisco(pos++)){
    if(strcmp(aux.getNombre(),i)==0){return pos;}
   }
   return -1;
}

void CrearArchivoClasico(){
    if(crearArchivoNuevo()==false){
     cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
     return;
    }
    Cancion reg;
    int pos=0, posInterprete, grabo=0;
    Clasico aux;
    Interprete obj;
    while(reg.leerDeDisco(pos++)){
        posInterprete=buscarInterprete(reg.getIDInt());
        if(posInterprete==-1){
        cout<<"NO EXISTE EL ID INTERPRETE"<<endl;
                return;
        }
        obj.leerDeDisco(posInterprete);
        if(obj.getTipoMus()==2){
            aux.setIdCancion(reg.getIDCanc());
            aux.setNombreCancion(reg.getTitulo());
            aux.setNombreInterprete(obj.getNombre());
            aux.grabarEnDisco();
            grabo++;
        }
        }
    if(grabo==0){ cout<<"ARCHIVO GRABADO EN BLANCO"<<endl;}
    else{ cout<<"ARCHIVO GRABADO EXITOSAMENTE"<<endl;
}
}

bool crearArchivoNuevo(){
FILE *p;
p=fopen("clasicos.dat","wb");
if(p==NULL){
    return false;
}
fclose(p);
return true;
}


bool BackUpCanciones(){
    FILE *p;
    int tam;
    p=fopen("canciones.bak", "wb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    FILE *pCan;
    Cancion reg;
    pCan=fopen("canciones.dat", "rb");
    if(pCan==NULL){
        fclose(p);
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pCan,0,2);
    tam=ftell(pCan)/sizeof (Cancion);
    fseek(pCan,0,0);
    for(int i=0;i<tam;i++){
        fread(&reg, sizeof reg, 1, pCan);
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(pCan);
    fclose(p);
    return true;
}



bool RestaurarCanciones(){
    FILE *pCan;
    Cancion reg;
    int tam;

    pCan=fopen("canciones.dat", "wb");

    if(pCan==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    FILE *p;
    p=fopen("canciones.bak", "rb");
    if(p==NULL){
        fclose(pCan);
        cout<<"ERROR DE ARCHIVO";
        return false;
    }
    fseek(p,0,2);
    tam=ftell(p)/sizeof (Cancion);
    fseek(p,0,0);
    for(int i=0;i<tam;i++){
        fread(&reg, sizeof reg, 1, p);
        fwrite(&reg, sizeof reg, 1, pCan);
    }
    fclose(pCan);
    fclose(p);
    return true;
}

bool BackUpInterpretes(){
    FILE *p;
    int tam;
    p=fopen("interpretes.bak", "wb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    FILE *pInt;
    Interprete reg;
    pInt=fopen("interpretes.dat", "rb");
    if(pInt==NULL){
        fclose(p);
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pInt,0,2);
    tam=ftell(pInt)/sizeof (Interprete);
    fseek(pInt,0,0);
    for(int i=0;i<tam;i++){
        fread(&reg, sizeof reg, 1, pInt);
        fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(pInt);
    fclose(p);
    return true;
}

bool RestaurarInterpretes(){
FILE *pInt;
    Interprete reg;
    int tam;

    pInt=fopen("interpretes.dat", "wb");

    if(pInt==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    FILE *p;
    p=fopen("interpretes.bak", "rb");
    if(p==NULL){
        fclose(pInt);
        cout<<"ERROR DE ARCHIVO";
        return false;
    }
    fseek(p,0,2);
    tam=ftell(p)/sizeof (Interprete);
    fseek(p,0,0);
    for(int i=0;i<tam;i++){
        fread(&reg, sizeof reg, 1, p);
        fwrite(&reg, sizeof reg, 1, pInt);
    }
    fclose(pInt);
    fclose(p);
    return true;
}

bool EstablecerInicio(){
FILE *pInt;
    Interprete reg;
    int tamInt;

    pInt=fopen("interpretes.dat", "wb");

    if(pInt==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    FILE *p;
    p=fopen("iniciointerpretes.bak", "rb");
    if(p==NULL){
        fclose(pInt);
        cout<<"ERROR DE ARCHIVO";
        return false;
    }
    fseek(p,0,2);
    tamInt=ftell(p)/sizeof (Interprete);
    fseek(p,0,0);
    for(int i=0;i<tamInt;i++){
        fread(&reg, sizeof reg, 1, p);
        fwrite(&reg, sizeof reg, 1, pInt);
    }
    fclose(pInt);
    fclose(p);

    FILE *pCan;
    Cancion aux;
    int tamCan;

    pCan=fopen("canciones.dat", "wb");

    if(pCan==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    FILE *p1;
    p1=fopen("iniciocanciones.bak", "rb");
    if(p1==NULL){
        fclose(pCan);
        cout<<"ERROR DE ARCHIVO";
        return false;
    }
    fseek(p1,0,2);
    tamCan=ftell(p1)/sizeof (Cancion);
    fseek(p1,0,0);
    for(int i=0;i<tamCan;i++){
        fread(&aux, sizeof aux, 1, p1);
        fwrite(&aux, sizeof aux, 1, pCan);
    }
    fclose(pCan);
    fclose(p1);
    return true;
}

bool estadoInt(int id){
 Interprete aux;
 int pos=0;
 bool estado;

 while(aux.leerDeDisco(pos++)){
    if(aux.getIDInt()==id){
        if(aux.getEstado()==true){estado=true;} else{estado=false;}
    }
 }
return estado;
}


#endif // FUNCIONES_H_INCLUDED
