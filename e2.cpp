#include <stdio.h>
#include "iostream"
#include "string"
#include <vector>

#include <cmath> // Para usar log10 y abs

using namespace std;
//Primeor creamos el struct de Persona

struct Persona{
private:
    int numero;
    int grado;
    int edad;

public:

    void mostrarDatos() const {
        cout << "Numero : " << numero << endl;
        cout << "Grado: " << grado << endl;
        cout << "Edad: " << edad << endl;
    }
    // Setters
    void setNumero(const int& nuevoNumero) {
        numero = nuevoNumero;
    }


    void setGrado(const int& nuevoGradro) {
        grado = nuevoGradro;
    }

    void setEdad(const int& nuevoEdad) {
        edad = nuevoEdad;
    }

    // Getters
    int getNumero() const {
        return numero;
    }
    int getGrado() const {
        return grado;
    }
    int getEdad() const {
        return edad;
    }


};

//opcion 1- Promedio de las edades

int promedio(vector<Persona> persona){
    int suma=0, promedio;

    for(int i=0; i<persona.size();i++){
        suma+=persona[i].getEdad();
    }
    promedio=suma/(persona.size());
    return promedio;



};

//opcion 2- ver la mayor edad

double mayorEdad(vector<Persona> persona){
    double mayor=0;
    mayor=persona[0].getEdad();
    
    for(int i=1; i<persona.size();i++){
        if(mayor<persona[i].getEdad()){
            mayor=persona[i].getEdad();
           
        }

    }

    return mayor;
    
}

//opcion 3- cantidad de los de primaria

int instruccion(vector<Persona> persona, int grado){
    int cant=0;
    for(int i=0;i<persona.size();i++){
        if(persona[i].getGrado()==(grado-2)){
            cant++;
        }
    }
    return cant;
    
}

int menu(){
    
    cout << "1. Promedio de Edades \n";
    cout << "2. Ver mayor Edad \n";
    cout << "3. Cantidad de personas con instruccion Primaria \n";
    cout << "4. Cantidad de personas con instruccion Secundaria \n";
    cout << "5. Cantidad de personas con instruccion Superior \n";
    cout << "6. Salir\n";
    cout << "Eliga una opcion: \n";
    int opcion;
    cin >> opcion;

    return opcion;



};

int main(){

    cout << "Ingrese el total de numero de persona: ";
    int cantidad;
    cin >> cantidad;

    vector<Persona> personas(cantidad);
    int opcion; 
    for(int i=0;i<personas.size();i++){

        cout << "///////////////Persona " << i+1 <<"///////////////////////\n";

        personas[i].setNumero(i);


        cout << "Ingrese el grado de Instruccion ((1-Primaria/2-Secundaria/3-Superior)):  ";
        int grado;
        cin >> grado;

        
        personas[i].setGrado(grado);

        cout << "Ingrese la edad: ";
        int edad;
        cin >> edad;

        personas[i].setEdad(edad);
        //Se muestra el menu

        
    };

    while(opcion!=6){
            int respt;
            opcion=menu();
            if(opcion==1){
                respt=promedio(personas);
                cout << "El promedio de las edades es: "<<respt << "\n";    
            }
            else if(opcion==2){
                respt=mayorEdad(personas);
                cout << "La major edad es: "<<respt << "\n";
            }
            else if(opcion==3){
                respt=instruccion(personas, opcion);
                cout << "La cantidad de grado "<< opcion-2 << " es: "<< respt << "\n";
            }
            else if(opcion==4){
                respt=instruccion(personas, opcion);
                cout << "La cantidad de grado "<< opcion-2 << " es: "<< respt << "\n";
            }
            else if(opcion==5){
                respt=instruccion(personas, opcion);
                cout << "La cantidad de grado "<< opcion-2 << " es: "<< respt << "\n";
            }
            else if(opcion=6){
                break;
            }
            

        };
    

}