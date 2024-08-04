#include <iostream>
using namespace std;
#include<cstring>

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


/*1) Desarrollar un programa con un menú para dar el alta, baja lógica y listado del siguiente archivo:
guías.dat: DNI (int), nombre y apellido (char[50]), código de nacionalidad (1 a 50), nivel (1 a 15) y fecha de nacimiento.
(6 puntos)*/


class Guias{
private:
    int _dni;
    char _nombreYapellido[50];
    int _codNacionalidad;
    int _nivel;
    Fecha _fechaNacimiento;

    bool estado;

public:

    /* sobrecarga */
    void operator =(Guias obj){
        _dni = obj.getDni();
    }


    // constructor
    Guias(int dni = 0, const char *NomyAp = "sin nombre", int Codnac = 0, int nivel= 0, int dia=1,int mes=1,int anio=1900, bool Est = 1){
     _dni = dni;
     strcpy(_nombreYapellido, NomyAp);
     _codNacionalidad = Codnac;
     _nivel = nivel;
     _fechaNacimiento.setDia(dia);
     _fechaNacimiento.setMes(mes);
     _fechaNacimiento.setAnio(anio);
     estado = Est;
 }



    // get
    int getDni(){return _dni;}
    char *getnombreYapellido(){return _nombreYapellido;}
    int getCodNacionalidad(){return _codNacionalidad;}
    int getNivel(){return _nivel;}
    Fecha getFechaNacimiento(){return _fechaNacimiento;}

    //set
    void setestado(bool e){estado = e;}

    void mostrar(){
        cout << " DNI: " << _dni <<endl;
        cout << "NOMBRE Y APELLIDO: " << _nombreYapellido  <<endl;
        cout << "CODIGO NACIONALIDAD: " << _codNacionalidad <<endl;
        cout << "NIVEL: " << _nivel <<endl;
        cout << "FECHA NACIMIENTO: ";
        _fechaNacimiento.Mostrar();
        if(estado == true){ cout << " activo " <<endl;}else
        {cout << " inactivo " <<endl;}
    }

    void cargar(){
        cout << " DNI: ";
        cin >> _dni;
        cout << "NOMBRE Y APELLIDO: ";
        cargarCadena(_nombreYapellido,50);
        cout << "CODIGO NACIONALIDAD: ";
        cin >> _codNacionalidad;
        cout << "NIVEL: ";
        cin >> _nivel;
        cout << "FECHA NACIMIENTO: " <<endl;
        _fechaNacimiento.Cargar();
        estado = true;

    }
};

class archivoGuias{
private:
    char nombre[30];
public:

     archivoGuias(const char *n){
        strcpy(nombre,n);
    }

     Guias leerRegistro(int pos){
        Guias reg;
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
    bool grabarRegistro(Guias reg){
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
        return tam/sizeof(Guias);
    }

     bool remplazarReg(Guias reg, int pos){
        FILE *p = fopen(nombre, "rb+");
        if (p == NULL){return false;}
        fseek(p, pos * sizeof(Guias), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Guias), 1, p);
        fclose(p);
        return pudoEscribir;
    }

    bool listarArchivo(){
        Guias reg;
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

};

void Alta(){
    archivoGuias archGuias("guías.dat");
    Guias reg;

    reg.cargar();
    archGuias.grabarRegistro(reg);
}

void bajaLogica(){

    archivoGuias archGuias("guías.dat");
    int cantGuias = archGuias.contarRegistros();
    Guias reg;

    int DNI;

    cout << "INGRESE NUMERO DE DNI A DAR DE BAJA: ";
    cin >> DNI;


    for(int i=0;i<cantGuias;i++){
        reg = archGuias.leerRegistro(i);

        if(reg.getDni() == DNI){
            reg.setestado(false);
            archGuias.remplazarReg(reg,i);
        }
    }
}

void listar(){
    archivoGuias archGuias("guías.dat");
    archGuias.listarArchivo();
}


int main(){

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
                case 1:Alta();
                    break;
                case 2: bajaLogica();
                    break;
                case 3: listar();
                    break;

                case 0:  cout << "saliendo..." <<endl;
                    break;

                default : cout << "OPCION INCORRECTA" <<endl;

            }
            system("pause");
        }


return 0;
}
