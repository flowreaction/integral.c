/*
Aufgabe	5.2		integral.c	
Autor			Florian Bopp
Datum		

Kurzbeschreibung:

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//functions
void flashStandardInput(void){
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

double f(double x) {
	return 4 - x*x;
}

//Aufgabe (a)
double flaeche(double von, double bis) {
	return  f((von + bis) / 2);
}

//Aufgabe (b)
double integral(double von, double bis, int anzahl) {
	double ergebnis = 0;
	double teilvon = von;
	double teilbis = (bis - von)/anzahl;
	int i;
	
	for ( i = 1; i <= anzahl; i++)	{
		ergebnis = ergebnis + f((teilvon + teilbis * i + von) / 2)*(teilbis * i + von - teilvon);
		teilvon = teilbis * i + von;
	}
	return ergebnis;
}

//Aufgabe (c)
double integral_trapez(double von, double bis, int n) {
	double ergebnis = 0;
	double h = (bis - von) / n;
	int i;

	for (i = 1; i <= n-1; i++)	{
		ergebnis = ergebnis + f(von + i*h);
	}
	ergebnis = (ergebnis*2 + f(von) + f(bis))*(h / 2);
	return ergebnis;
}

// Main function
int main(void) {
	double von, bis;
	int teilintervalle;
	char janein;
	do
	{
		printf("Bitte Integralsgrenzen eigeben.\nVon: ");
		scanf("%lf", &von);
		flashStandardInput();
		printf("\nBis: ");
		scanf("%lf", &bis);
		flashStandardInput();
		printf("\n\nBitte die Anzahl der Teilintervalle angeben: ");
		scanf("%d", &teilintervalle);
		flashStandardInput();
		printf("\n\n\n");

		printf("Fl%cche von einem rechteck des Intervalles mit der Breite 1 ist %f\n\n\n", 132, flaeche(von, bis));
		printf("Fl%cche der funktion integral = %f\n\n", 132, integral(von, bis, teilintervalle));
		printf("Fl%cche der funktion integral_trapez = %f\n\n", 132, integral_trapez(von, bis, teilintervalle));
		
		do
		{
			printf("\n\n\n\nNoch ein Integral berechnen?\ny/n:");
			scanf("%c", &janein);
			flashStandardInput();
		} while (janein != 'y' && janein != 'n');
		printf("\n\n");
	} while (janein == 'y');
		
	return 0;
}