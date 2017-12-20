/*
Aufgabe	5.2			integral.c	
Autor				Florian Bopp
Datum				6.12.17

Kurzbeschreibung:	Diese Programm berechnet ein Integral einer beliebigen Funktion auf 2 verschiedene varianten.
					In aufgabe (a) wird ein beispielrechteck berechnet. In Aufgabe (b) wird wird über eine Funktion 
					ein Integral berechnet und in aufgabe (c) wird dies wiederholt über eie andere Funktion welche 
					die Trapezformel für integrale beinhaltet.

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

//Irgendeine Mathematische funktion von welcher ein Integral berechnet werden soll
double f(double x) {
	return 4 - x*x;
}

//Aufgabe (a)
double flaeche(double von, double bis) {
	return  f((von + bis) / 2) * (bis - von);					//berechnung eines rechtecks (funktionswert(höhe) * breite)
}

//Aufgabe (b)
double integral(double von, double bis, int anzahl) {	
	double ergebnis = 0;
	double teilvon = von;											//variable welche sich im forloop weiterschiebt
	double teilbis = (bis - von)/anzahl;							//variable welche sic im foorloop weiterschiebt
	int i;
	
	for ( i = 1; i <= anzahl; i++)	{								//For loop für die menge der teilintervalle
		ergebnis = ergebnis + flaeche(teilvon, teilbis * i + von);	//die Funktion fläche wird aufgerufen und angepasst an die teilintervalle ausgeführt
		teilvon = teilbis * i + von;								//teilvon wird der aktuelle wert von teilbis zugeordnet
	}
	return ergebnis;
}

//Aufgabe (c) trapez reihe zur berechnung von integralen
double integral_trapez(double von, double bis, int n) {
	double ergebnis = 0;
	double h = (bis - von) / n;
	int i;

	for (i = 1; i <= n-1; i++)	{	//For schleife zum errechnen der Folge
		ergebnis = ergebnis + f(von + i*h);
	}
	ergebnis = (ergebnis*2 + f(von) + f(bis))*(h / 2); //Das Ergebnis der Folge wird mit dem Rest der Trapez Formel verrechnet
	return ergebnis;
}

// Main function
int main(void) {
	double von, bis;
	int teilintervalle;
	char janein;
	do {						//Do-While schleife in welcher die Integrale berechnet werden.
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

		printf("Fl%cche von einem rechteck des Intervalles ist %f\n\n\n", 132, flaeche(von, bis)); //Aufgabe a wird abgerufen
		printf("Fl%cche der funktion integral = %f\n\n", 132, integral(von, bis, teilintervalle)); //Aufgabe b wird abgerufen
		printf("Fl%cche der funktion integral_trapez = %f\n\n", 132, integral_trapez(von, bis, teilintervalle)); //Aufgabe c wird abgerufen
		
		do{
			printf("\n\n\n\nNoch ein Integral berechnen?\ny/n:");
			scanf("%c", &janein);
			flashStandardInput();
		} while (janein != 'y' && janein != 'n'); //abfrage ob nochmal ein integral berechnet werden soll
		printf("\n\n");
	} while (janein == 'y');
		
	return 0;
}