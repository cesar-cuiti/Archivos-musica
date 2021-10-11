#ifndef OBJETOS_H_INCLUDED
#define OBJETOS_H_INCLUDED

int buscarInterprete(int i);
bool estadoInt(int id);
void cargarCadena(char *pal, int tam);

class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0){
        if((d+m+a)==0){
            time_t tiempo;
            struct tm *tmPtr;
            tiempo = time(NULL);
            tmPtr = localtime(&tiempo);
            dia=tmPtr->tm_mday;
            mes=tmPtr->tm_mon+1;
            anio=1900+tmPtr->tm_year;
        }
        else{
            dia=d;
            mes=m;
            anio=a;
        }
    }
    bool setDia(int d){
        if(d>0 && d<=31){
            dia=d;
            return true;
        }
        return false;

    }

    bool setMes(int d){
        if(d>0 && d<=12){
            mes=d;
            return true;
        }
        return false;
    }

    bool setAnio(int d){
        if(d>0 && d<=2021){
          anio=d;
          return true;
        }
        return false;
    }
    bool validarFecha(){
        int diasPorMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(dia>diasPorMes[mes-1]){
        if(getAnio()%4==0) {
            if (getAnio()%100==0) {
                if (getAnio()%400==0) {diasPorMes[1]=29;return true;} else {cout<<"FECHA INVÁLIDA "<<endl;return false;}}
                else {diasPorMes[1]=29;return true;}}
                else {cout<<"FECHA INVÁLIDA                     ";return false;} cout<<"FECHA INVÁLIDA ";return false;}
        return true;
    }

            int getDia(){return dia;}
            int getMes(){return mes;}
            int getAnio(){return anio;}

    bool Cargar(){
        int d,m,a;
        cout<<"DÍA: ";
        cin>>d;
        if(!setDia(d)){
                cout<<"EL DÍA NO ES VÁLIDO"<<endl;
                return false;
        }
        cout<<"MES: ";
        cin>>m;
        if(setMes(m)==false){
                cout<<"EL MES NO ES VÁLIDO"<<endl;
                return false;
        }
        cout<<"AÑO: ";
        cin>>a;
        if(!setAnio(a)){
                cout<<"EL AÑO NO ES VÁLIDO"<<endl;
                return false;
        }
        return validarFecha();
    }

    void Mostrar(){
        char meses[12][11]={"ENERO", "FEBRERO","MARZO","ABRIL","MAYO", "JUNIO","JULIO", "AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
      cout<<dia<<" DE "<<meses[mes-1]<<" DE "<<anio<<endl;
    }

};


class Interprete{
    private:
        int idInt;
        char nombre[40];
        char nacAutor[20];
        int tipoInt;
        int tipoMus;
        bool estado;


    public:
        int getIDInt(){return idInt;}
        const char *getNombre(){return nombre;}
        const char *getNacAutor(){return nacAutor;}
        int getTipoInt(){return tipoInt;}
        int getTipoMus(){return tipoMus;}
        bool getEstado(){return estado;}

        void setIdInt(int Id){idInt=Id;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setNacAutor(const char *nA){strcpy(nacAutor, nA);}
        bool setTipoInt(int tI){
            if(tI>0&&tI<=5){
                    tipoInt=tI;
                    return true;}
            else{cout<<"EL TIPO DE INTÉRPRETE ES INVÁLIDO";
            return false;}
        }
        bool setTipoMus(int tM){
            if(tM>0&&tM<=10){
            tipoMus=tM;
            return true;}
            else { cout<<"EL TIPO DE MÚSICA ES INVÁLIDO";
            return false;}
            }
        void setEstado(bool e){estado=e;}


        bool Cargar();
        int InterpretesAuto();
        void Mostrar();

        bool grabarEnDisco(){
        FILE *p;
        p=fopen("interpretes.dat","ab");
        if(p==NULL){
        system("cls");
            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
            system("pause>null");
            return false;
        }
        bool escribio=fwrite(this,sizeof *this, 1, p);
        fclose(p);
        return escribio;
    }

        bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("interpretes.dat","rb");
        if(p==NULL){

    system("cls");

            cout<<"NO SE PUDO ABRIR EL ARCHIVO                            "<<endl;
            system("pause>null");
            return false;
        }
        fseek(p,sizeof *this*pos,0);
        bool leyo=fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
    }

    bool modificarenDisco(int pos){
    FILE *pCan;
    bool modifico;
    pCan=fopen("interpretes.dat", "rb+");
    if(pCan==NULL){
    return false;
    }
    fseek(pCan, pos * sizeof *this, 0);
    modifico=fwrite(this,sizeof *this,1,pCan);
    fclose(pCan);
    return modifico;

}

};

bool Interprete::Cargar(){

    system("cls");
    int ti,tm; bool Val=true;

    idInt=InterpretesAuto()+1;
    cout<<"ID DE INTÉRPRETE: "<<idInt<<endl;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 40);
    cout<<"NACIONALIDAD: ";
    cargarCadena(nacAutor, 20);
    cout<<"TIPO DE INTÉRPRETE (DEL 1 AL 5): ";
    cin>>ti;
    if(setTipoInt(ti)==false){Val=false;}
    cout<<"TIPO DE MÚSICA (DEL 1 Al 10): ";
    cin>>tm;
    if(setTipoMus(tm)==false){Val=false;}
    cout<<"ESTADO: ";
    estado=true;
    return Val;
}

void Interprete::Mostrar(){


    cout<<"ID DE INTÉRPRETE: "<<idInt<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"NACIONALIDAD: "<<nacAutor<<endl;
    cout<<"TIPO DE INTÉRPRETE: "<<tipoInt<<endl;
    cout<<"TIPO DE MÚSICA: "<<tipoMus<<endl;

    if(estado==true){cout<<"ACTIVO"<<endl<<endl;} else {cout<<"[INACTIVO]"<<endl<<endl;}

}

int Interprete::InterpretesAuto(){
int Aumento;
FILE *p;
p=fopen("interpretes.dat","rb");
if(p==NULL){
    return false;
}
fseek(p,0,2);
Aumento=ftell(p)/sizeof (Interprete);
fclose(p);
return Aumento;
    }


class Cancion{
    private:
        int idCanc;
        char titulo[30];
        char nombreAutor[30];
        int idInt;
        Fecha fechaEst;
        bool estado;
    public:
        int getIDCanc(){return idCanc;}
        const char *getTitulo(){return titulo;}
        const char *getNombreAutor(){return nombreAutor;}
        int getIDInt(){return idInt;}
        Fecha getFechaEst(){return fechaEst;}
        bool getEstado(){return estado;}

        void setIdCanc(int Id){idCanc=Id;}
        void setTitulo(const char *t){strcpy(titulo, t);}
        void setNombreAutor(const char *a){strcpy(nombreAutor, a);}
        void setIdInt(int IdInt){idInt=IdInt;}
        void setFechaEst(Fecha f){fechaEst=f;}
        void setEstado(bool e){estado=e;}

        bool Cargar();
        int CancionesAuto();
        void Mostrar();

        bool grabarEnDisco(){
        FILE *p;
        p=fopen("canciones.dat","ab");
        if(p==NULL){

    system("cls");

            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
            system("pause>null");
            return false;
        }
        bool escribio=fwrite(this,sizeof *this, 1, p);
        fclose(p);
        return escribio;
    }

        bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("canciones.dat","rb");
        if(p==NULL){

    system("cls");

         cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
         system("pause>null");
            return false;
        }
        fseek(p,sizeof *this*pos,0);
        bool leyo=fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
    }

    bool modificarenDisco(int pos){
    FILE *pCan;
    bool modifico;
    pCan=fopen("canciones.dat", "rb+");
        if(pCan==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return false;
    }
    fseek(pCan, pos * sizeof *this, 0);
    modifico=fwrite(this,sizeof *this,1,pCan);
    fclose(pCan);
    return modifico;

}

};

bool Cancion::Cargar(){


    int id; bool Val=true;

    idCanc=CancionesAuto()+1;
    cout<<"ID DE CANCIÓN: "<<idCanc<<endl;
    cout<<"TÍTULO: ";
    cargarCadena(titulo, 30);
    cout<<"AUTOR: ";
    cargarCadena(nombreAutor, 30);
    cout<<"ID DE INTÉRPRETE: ";
    cin>>id;
    if(estadoInt(id)==true){
    if(buscarInterprete(id)!=-1){idInt=id;} else {cout<<"EL INTÉRPRETE NO EXISTE"; Val=false;}
    }
    else{cout<<"ID INACTIVO. NO PUEDE GRABAR"<<endl;Val=false;}
    cout<<"FECHA DE ESTRENO: ";
    if(fechaEst.Cargar()==false){Val=false;}
    cout<<"ESTADO: ";
    estado=true;
    return Val;    //if(Val==0){return true;} else {return false;}
}

void Cancion::Mostrar(){

    cout<<"ID DE CANCIÓN: "<<idCanc<<endl;
    cout<<"TÍTULO: "<<titulo<<endl;
    cout<<"AUTOR: "<<nombreAutor<<endl;
    cout<<"ID DE INTÉRPRETE: "<<idInt<<endl;
    cout<<"FECHA DE ESTRENO: ";
    fechaEst.Mostrar();cout<<endl;
    if(estado==true){cout<<"ACTIVO"<<endl;} else {cout<<"[INACTIVO]"<<endl;}

}

int Cancion::CancionesAuto(){
int Aumento;
FILE *p;
p=fopen("canciones.dat","rb");
if(p==NULL){
    return false;
}
fseek(p,0,2);
Aumento=ftell(p)/sizeof (Cancion);
fclose(p);
return Aumento;
    }



class Clasico{
private:
    int idCancion;
    char nombreCancion[30], nombreInterprete[40];
public:
    void setIdCancion(int i){idCancion=i;}
    void setNombreCancion(const char *c){strcpy(nombreCancion,c);}
   void setNombreInterprete(const char *i){strcpy(nombreInterprete,i);}

   bool grabarEnDisco(){
   FILE *p;
        p=fopen("clasicos.dat","ab");
        if(p==NULL){
            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        bool escribio=fwrite(this,sizeof *this, 1, p);
        fclose(p);
        return escribio;
   }
};




#endif // OBJETOS_H_INCLUDED
