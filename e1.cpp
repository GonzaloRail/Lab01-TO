#include <stdio.h>
#include "iostream"
#include "string"
#include <cmath> // Para usar log10 y abs

using namespace std;

bool anstrong(int numero){
    int a,b,c,aux;
    // numero =321
        a=numero%10;//el ultimo digito// a=1
        aux=((numero-a)/10);//===32
        b=aux%10; // 321-1=320%10=====2
        c=(aux-b)/10;

    if(pow(a,3)+pow(b,3)+pow(c,3)==numero){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    cout << "Ingrese un numero: ";
    int numero;
    cin >> numero;

    if(anstrong(numero)==true){
        cout << "Es un numero de Anstrong";
    }
    else{
        cout << "No es un numero de Anstrong";
    }

}

