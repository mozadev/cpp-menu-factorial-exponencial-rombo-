// ConsoleApplication3.cpp : main project file.
#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace System;
using namespace std;


void menu()
{
	cout << endl; cout << endl;
	cout << "MENU PRINCIPAL" << endl;
	cout << "1. determinar el factoria de un numero" << endl;
	cout << "2. calcular e^a" << endl;
	cout << "3. imprimir rombo" << endl;
	cout << "4. fin" << endl;
	cout << " ingrese opcion: ";
}

int ingresapositivofactorial()
{
	int n;
	cout << "ingresa numero"; cin >> n;
	while (n <= 0)
	{
		cout << "ingresa numero"; cin >> n;
	}return n;
}

float factorial(int n)
{
	float result = 1;
	int i = 1;
	while (i <= n)
	{
		result = result*i;
		i++;
	}
	return result;
}

float calculapotencia(float b, int e)
{
	float result = 1;
	int i = 1;
	while (i <= e)
	{
		result = result*b;
		i++;
	}
	return result;
}


float ingresak()
{
	float k;
	do
	{
		cout << "ingrese k (k: numero de terminos de la serie debe ser <=20 ): "; cin >> k;
	} while (k <= 0 || k > 20);
	return k;
}

float sumaserie()
{
	float a, suma = 0;
	float k;
	cout << "ingresa a:  "; cin >> a;
	k = ingresak();
	for (int i = 0; i < k; i++)
		suma = suma + calculapotencia(a, i) / factorial(i);
	return suma;
}

int ingresanumrombo()
{
	int num; cout << "ingrese numero"; cin >> num;
	while (num <= 0 || num >= 11)
	{
		int num; cout << "ingrese numero"; cin >> num;
	}return num;
}

void dibujarombo()
{
	int n = ingresanumrombo();
	for (int i = 1; i <= n; i++)
	{
		for (int e = 40 - i*3; e >= 1; e--)
			cout << " ";
		for (int j = 1; j < i * 2; j++)
			cout <<" "<<j<<" ";
		cout << endl;
	}
	for (int i = n; i > 1; i--)
	{
		for (int e = 40 - (i-1)*3; e >= 1; e--)
			cout << " ";
		for (int j = 1; j < i * 2 - 2; j++)
			cout <<" " <<j<<" ";
		cout << endl;
	}
}
//void dibujarombo()
//{
//	int n = ingresanumrombo();
//	for (int i = 1; i <= n; i++)
//	{
//		for (int e = 1; e <= 40 - i * 3; e++)
//			cout << " ";
//		for (int j = 1; j < i * 2; j++)
//			cout << " " << j << " ";
//		cout << endl;
//	}
//	for (int i = n - 1; i >= 1; i--)
//	{
//		for (int e = 1; e <= 40 - i * 3; e++)
//			cout << " ";
//		for (int j = 1; j < i * 2; j++)
//			cout << " " << j << " ";
//		cout << endl;
//	}
//}

int main()
{
	int option, n;
	while (1)
	{
		menu();
		cin >> option;
		switch (option)
		{
		case 1:
			cout << endl << "funcion factorial" << endl;
			n = ingresapositivofactorial();
			cout << "factorial de" << n << "es: " << factorial(n) << endl;
			break;
		case 2:
			cout << endl << "funcion exponencial e^a" << endl;
			cout << "e^a calculada como serie (suma de terminos de una sucesion infinita)" << endl;
			cout << sumaserie() << " es el valor de la exponecial e^a";
			break;
		case 3:
			cout << endl << "Funcion Dibuja" << endl;
			dibujarombo();
			break;
	
		}
	}
	_getch();
}