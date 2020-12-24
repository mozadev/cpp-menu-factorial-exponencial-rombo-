// ConsoleApplication3.cpp : main project file.
 
#include "stdafx.h"
 
/*
1 con menu varios
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>
using namespace std;
using namespace System;
void IngresaPositivo(int *Nfact) //recibe con la indereccion, no crea una copia ni guarda direccion manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes
{
    do
    {
        cout << "Ingerese Numero Positivo:";
        cin >> *Nfact;  //manipulando o ingresando directamente el valor con la indireccion
    } while (*Nfact <= 0);
}
void IngresaNum(int *Num) //recibe con la indereccion, no crea una copia ni guarda direccion manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes
{
    do
    {
        cout << "Ingerese N:"; cin >> *Num; //manipulando o ingresando directamente el valor con la indireccion
    } while (*Num <= 0 || *Num > 10);
}
void IngresaK(int *k) //recibe con la indereccion, no crea una copia ni guarda direccion manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes
{
    do
    {
        cout << "Ingerese K:"; cin >> *k; //manipulando o ingresando directamente el valor con la indireccion
    } while (*k <= 0 || *k > 20);
}
float  Factorial(int &N)  // recibiendo con la dirección ahorra 2 bytes
{
    float Result = 1;
    int i = 1;
    while (i <= N)
    {
        Result = Result*i;
        i++;
    }
    return Result;
}
float Potencia(float &b, int &e) // recibiendo con la dirección ahorra 2+2 bytes
{
    float Result = 1;
    int i = 1;
    while (i <= e)
    {
        Result = Result*b;
        i++;
    }
    return Result;
}
void Funcion_SumaSerie(float *SumaSerie) //recibe con la indereccion, no crea una copia ni guarda direccion manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes
{
    *SumaSerie = 0;  //manipulando o ingresando directamente el valor con la indireccion
    float a;
    int *k = new int;  // crea un puntero ademas reserva para un entero ocupacion 2+4
    cout << "Ingresa a:"; cin >> a;  //ingresa a
    IngresaK(k);   //ingresa k
    cout << *k;
    for (int i = 0; i<*k; i++)
        *SumaSerie = *SumaSerie + Potencia(a, i) / Factorial(i); //manipulando o ingresando directamente el valor con la indireccion
    delete k;
}
 
void DibujaRombo()
{   system("cls");
    int *Num = new int;  // crea un puntero ademas reserva para un entero ocupacion 2+4
    int *k = new int;  // crea un puntero ademas reserva para un entero ocupacion 2+4
    IngresaNum(Num);
    int X = 40;
    int Y = 10;
    for (int i = 1; i <= *Num; i++)
    {   X = X - 2;
        Y = Y + 1;
        Console::SetCursorPosition(X, Y);
        for (int j = 1; j < i * 2; j++)
            cout << setw(2) << j;
 
        cout << endl;
    }
    for (int i = *Num; i>1; i--)
    {   X = X + 2;
        Y = Y + 1;
        Console::SetCursorPosition(X, Y);
        for (int j = 1; j < i * 2 - 2; j++)
            cout << setw(2) << j;
 
        cout << endl;
    }
    delete Num;
    delete k;
}
void Menu()
{
    system("cls");
    cout << endl; cout << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Determinar el factorial de un numero" << endl;
    cout << "2. Calcular e^â" << endl;
    cout << "3. Imprimir Rombo" << endl;
    cout << "4. Fin" << endl;
    cout << "Ingrese su opcion:";
}
 
int main()
{   int option;
    int Nfact; //ojo no es puntero esta normal
    float *SumaSerie = new float;
    while (1)
    {   Menu();
        cin >> option;
        switch (option)
        {
        case 1:
            cout << endl << "FUNCION FACTORIAL" << endl;
            IngresaPositivo(&Nfact); // pasa la direccion de Nfact esa funcion es void que manipula por con su indireccion por eso no hay retorno
            cout << "Factorial de " << Nfact << " es:" << Factorial(Nfact); //como la funcion Ingresapositivo ingreso el valor, se asume que ya tiene valor por tanto pasa ese valor a la funcion factorial
            int otronum;
            _getch();
            break;
        case 2:
            cout << endl << "FUNCION e^a " << endl;
            Funcion_SumaSerie(SumaSerie); //pasamos direccion de SumaSerie, para que ponga el resultado y es void por eso la ejuccion es asi
            cout << "La suma de e^a es:" << *SumaSerie << endl; //como ya tiene valor y lo podemos ver con la indreccion.
            delete SumaSerie;
            _getch();
            break;
        case 3:
            cout << endl << "FUNCION DIBUJA ROMBO" << endl;
            DibujaRombo();
            cout << endl;
            _getch();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << endl << "Ingrese opcion correcta" << endl;
            Menu();
        }
    }
   
    _getch();
}