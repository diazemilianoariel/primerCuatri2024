#include <iostream>
#include<cstdlib>
#include<cstring>
#include "Agente.h"
#include "AgenteArchivo.h"
#include "Fecha.h"
#include "Multa.h"
#include "MultaArchivo.h"
#include "MultaManager.h"

using namespace std;

void cargarCadena(char *palabra, int tam){
    int i=0;
    fflush(stdin);
    for (i=0; i<tam; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);

    }




/*Crear una clase llamada Reclamo que permita registrar un reclamo de una multa.
Debe poder registrar el ID de Multa, la fecha del reclamo, el ID sucursal del
reclamo y un texto de hasta 100 caracteres con los motivos. También debe
registrar un valor bool para determinar si el reclamo fue Aceptado o no.*/
#include <string>
#include <ctime>

class Reclamo {
private:
    int idMulta;
    Fecha fechaReclamo;
    int idSucursal;
    char motivos[100];
    bool aceptado;

public:
    // Constructor que inicializa los datos del reclamo con parámetros
    Reclamo(int idMulta, Fecha fechaReclamo, int idSucursal, char* motivo, bool aceptado) {
        idMulta = idMulta;
        fechaReclamo = fechaReclamo;
        idSucursal = idSucursal;
        strcpy(motivos,motivo);
        aceptado = aceptado;
    }

    // Constructor vacío que inicializa a 0 y cadena vacía
    Reclamo() {
        idMulta = 0;
        fechaReclamo = Fecha();  // llamo al constructor por  defecto que  llama al metodo establecer por defecto
        idSucursal = 0;
        strcpy(motivos, "");
        aceptado = false;
    }

    // Setters y Getters para cada atributo
    void setIdMulta(int id) { idMulta = id; }
    int getIdMulta() const { return idMulta; }

    void setFechaReclamo(Fecha fecha) { fechaReclamo = fecha; }
    Fecha getFechaReclamo() const { return fechaReclamo; }

    void setIdSucursal(int id) { idSucursal = id; }
    int getIdSucursal() const { return idSucursal; }

    void setMotivos(char* motivo) { strcpy(motivos, motivo); }
    char getMotivos(){ return *motivos; }

    void setAceptado(bool estado) { aceptado = estado; }
    bool getAceptado(){ return aceptado; }
};

/*Crear un método que permita guardar un registro de la clase Reclamo en un
archivo llamado reclamos.dat. Crear otro método que permita leer un registro de
la clase Reclamo a partir de la posición en el archivo reclamos.dat.
*/

class ArchivoReclamo{

    private:
    public:

        // Crear otro método que permita leer un registro de la clase Reclamo a partir de la posición en el archivo reclamos.dat.
            Reclamo leerRegistro(int pos){
            Reclamo reg;
            FILE *p;
            p=fopen("reclamos.dat", "rb");
            if(p==NULL) return reg;
            fseek(p, sizeof(Reclamo)*pos,0);
            fread(&reg, sizeof reg,1, p);
            fclose(p);
            return reg;
        }


        int contarRegistros(){
            FILE *p;
            p=fopen("reclamos.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Reclamo);
        }
        //Crear un método que permita guardar un registro de la clase Reclamo en un archivo llamado reclamos.dat

            bool guardar(Reclamo reg){
            FILE* p = fopen("reclamos.dat", "ab");
            if (p == NULL)
            {
            return false;
            }
            bool ok = fwrite(&reg, sizeof(Reclamo), 1, p);
            fclose(p);
            return ok;
            }


  void CargarReclamo(){
    /*Hacer un método que permita cargar un reclamo y guardarlo en el archivo de
reclamos. Debe solicitar el ID de Multa, la fecha del reclamo, el ID de sucursal, el
motivo del reclamo y si el reclamo fue aceptado o no. Si el reclamo fue aceptado,
la multa debe ser eliminada (de manera lógica) del archivo de multas. Puede haber un sólo reclamo por ID Multa*/
    int idmulta;
    Fecha fechaReclamo;
    int idsucursal;
    char motivos[100];
    bool aceptado=false;

    //pedir al ususario:
    cout << "ingrese id multa entre 0 y 5" <<endl;
    cin >> idmulta;
    int dia, mes, anio;
    cout << "Ingrese la fecha del reclamo (día mes año): ";
    cin >> dia >> mes >> anio;
    // Crear un objeto Fecha con los valores ingresados por el usuario
    fechaReclamo = Fecha(dia, mes, anio);
    cout << "Ingrese ID de sucursal: ";
    cin >> idsucursal;
    cout << "Ingrese motivo del reclamo (hasta 100 caracteres): ";
    cargarCadena(motivos, 99);
    cout << "¿El reclamo fue aceptado? (1 = Sí, 0 = No): ";
    cin >> aceptado;




    Multa multa;
    MultaArchivo archMulta;
    int CantMultas = archMulta.getCantidadRegistros();

    Reclamo reclamo(idmulta,fechaReclamo,idsucursal,motivos,aceptado);
    ArchivoReclamo archreclamo;


    archreclamo.guardar(reclamo); // aca ya se guarda el reclamo

    /*Si el reclamo fue aceptado,
    la multa debe ser eliminada (de manera lógica) del archivo de multas.
    Puede haber un sólo reclamo por ID Multa*/
        if(aceptado){
            for(int i =0;i<CantMultas;i++){
                multa = archMulta.leer(i);

                if(multa.getIDMulta() == idmulta){ // id de multa
                     multa.setEliminado(true);
                     archMulta.guardar(multa,i);
                     cout << "multa eliminada" <<endl;
                }

        }
    }
}

};







class Examen{

public:
    void Punto3(){
/*Hacer un método llamado Punto3 que liste la información de todas las multas
que hayan sido eliminadas a causa de un reclamo aceptado. Incluyendo el motivo
del reclamo asociado.*/


    Reclamo reclamo;
    ArchivoReclamo archReclamo;
    int CantReclamos = archReclamo.contarRegistros();



    Multa multa;
    MultaArchivo archMulta;
    MultaManager multaManager;

    for(int i=0; i<CantReclamos;i++){
        reclamo = archReclamo.leerRegistro(i);

        if(reclamo.getAceptado()== true){
            int posicion = archMulta.buscar(reclamo.getIdMulta());
            multa = archMulta.leer(posicion);
            multaManager.Listar(multa);
            cout << reclamo.getMotivos();

            }
        }
    }
};

int main (){

    Examen examen;

    examen.Punto3();




return 0;
}



