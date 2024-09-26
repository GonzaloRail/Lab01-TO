#include <stdio.h>
#include "iostream"

using namespace std;

void divisores(int n){
    int cant=0, divisor;
    cout <<"Los divisores son: \n";
    for(int i=1; i<=n;i++){
        divisor=n%i;
        if(divisor==0){
           
            cout << i << "-";
        }

    }

}

int cantDivisores(int n){
    int cant=0, divisor;
    for(int i=1; i<=n;i++){
        divisor=n%i;
        if(divisor==0){
            cant++;
        }

    }
    return cant;

}
int main(){
    cout << "Ingrese un numero: ";
    int numero;
    cin >> numero;
    
    cout << "El numero de divisores es: "<<cantDivisores(numero)<<"\n";

    divisores(numero);


}
