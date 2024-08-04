#include<iostream>
#include<cstring>
using namespace std;



class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

Astronautas leerRegistro(int pos){
        Astronautas reg;
        reg.setestado(0);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool grabarRegistro(Astronautas reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Astronautas);
    }


bool listarArchivo(){
        Partidos reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }


bool remplazarReg(Partidos reg, int pos){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){return false;}
    fseek(p, pos * sizeof(Partidos), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Partidos), 1, p);
    fclose(p);
    return pudoEscribir;
}

void bajaLogica(){

    ArchivoPartidos archPartido("Partidos.dat");
    int cantPartidos = archPartido.contarRegistros();
    Partidos reg;

    int CodPartido;

    cout << "INGRESE ID EQUIPO A DAR DE BAJA: ";
    cin >> CodPartido;


    for(int i=0;i<cantPartidos;i++){
        reg = archPartido.leerRegistro(i);

        if(reg.getCodPartido() == CodPartido ){
            reg.setEstado(true);
            archPartido.remplazarReg(reg,i);
        }
    }
}


void cargarEquipo(){
    ArchivoPartidos archPartido("Partidos.dat");
    Partidos reg;

    reg.cargar();
    archPartido.grabarRegistro(reg);
}

void asignacionDinamica(){
    Partidos *vec = nullptr;
    vec = new Partidos[tam];
    if(vec==nullptr) return;

        // asignar en el vector dinamico
        for(int i=0;i<cantPartidos;i++){
            reg = archPartido.leerRegistro(i);
                vec[i] = reg;
        }

        /// lista vector dinamico
    for(int k=0;k<tam;k++){
        vec[k].mostrar();
    }

}

void menu(){
      int opc=1;

    while(opc!=0){
        system("cls");
        cout<<"MENU  "<<endl;
        cout<<"********************** "<<endl;
        cout<<"1. DAR DE ALTA  "<<endl;
        cout<<"2. BAJA LOGICA "<<endl;
        cout<<"3. LISTADO           "<<endl;
        cout<<"0. SALIR DEL PROGRAMA"<<endl;
        cout<<"******************** "<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;

        system("cls");
        switch(opc){
            case 1:// cargarEquipo();
                break;
            case 2: //bajaLogica();
                break;
            case 3: //listar();
                break;

            case 0:  cout << "saliendo..." <<endl;
                break;

            default : cout << "OPCION INCORRECTA" <<endl;

        }
        system("pause");
    }
}


class archivoPunto1{
private:
    char nombre[30];
public:

     archivoPunto1(const char *n){
        strcpy(nombre,n);
    }

     Punto1 leerRegistro(int pos){
        Punto1 reg;
        reg.setestado(0); ///-puede ser que no tenga estado la clase  !!!ATENCION!!!
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

     ///metodos
    bool grabarRegistro(Punto1 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    ///


    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }


    bool listarArchivo(){
        Punto1 reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }


    bool remplazarReg(Punto1 reg, int pos){
        FILE *p = fopen(nombre, "rb+");
        if (p == NULL){return false;}
        fseek(p, pos * sizeof(Punto1), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
        fclose(p);
        return pudoEscribir;
    }

    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }




};


class Punto1{
private:
    int _dni;
public:
    // constructor
    Punto1(){

    }

    //set
    void setDni(int dni){_dni=dni;}

    // get
    void getDni(){return _dni;}


    void mostrar(){
        cout << " DNI: " << _dni <<endl;
        cout << ": " <<  <<endl;
        cout << ": " <<  <<endl;
    }

    void cargar(){
        cout << " DNI: ";
        cin >> _dni;
    }

};



