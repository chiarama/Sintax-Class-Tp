#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


int clasificarChar (char unChar){
	int a = 5;
	if (unChar == '0'){a=0;};
	if (unChar == '1' || unChar == '2'|| unChar == '3'|| unChar == '4'|| unChar == '5'|| unChar == '6'|| unChar == '7'){a=1;};
	if (unChar == 'a' || unChar == 'b'|| unChar == 'c'|| unChar == 'd'|| unChar == 'e'|| unChar == 'f'){a=3;};
	if (unChar == 'A' || unChar == 'B'|| unChar == 'C'|| unChar == 'D'|| unChar == 'E'|| unChar == 'F'){a=3;};
	if (unChar == 'X' || unChar == 'x'){a=4;};
	if (unChar == '8' || unChar == '9'){a=2;};
	return a;
};
int main()
         //int argc, char const *argv[])
{
	int productions[7][7] = {
		{2,1,1,6,6,6},
		{1,1,1,6,6,6},
		{3,3,6,6,4,6},
		{3,3,6,6,6,6},
		{5,5,5,5,6,6},
		{5,5,5,5,6,6},
		{6,6,6,6,6,6}
	};

	int currentStatus = 0;
	char* currentWord = "";

	FILE *archivoDeEntrada = fopen( "archivoDeEntrada.txt", "r" );
	FILE *archivoDeSalida = fopen( "archivoDeSalida.txt", "w" );

	while(!feof(archivoDeEntrada)){ //Entra en bucle infinito (no termina al menos que se depure, y escribe repetidas veces “0x” en el archivo.
		char nextChar; //proxima letra del archivo, DECLARARLO
		//algo con fread sizeof(char)*1,1, SEEK_CUR
		fread(&nextChar, 1, 1, archivoDeEntrada);
		while (nextChar != 32){
            		currentStatus = productions [currentStatus][clasificarChar(nextChar)];
            		fwrite(&nextChar,1, 1, archivoDeSalida);
			fread(&nextChar, 1, 1, archivoDeEntrada);
		};
		if (currentStatus != 0){
                             	switch (currentStatus) {
				case 1:
					currentWord = "    Decimal\n";
				break;
				case 5:
					currentWord = "    Hexadecimal\n";
				break;
				case 2:
				case 3:
					currentWord = "    Octal\n";
				break;
				case 4:
				case 6:
					currentWord = "    No es una constante entera\n";
				break;
			};
		       	fwrite(currentWord ,1, strlen(currentWord), archivoDeSalida);
		};
		currentStatus = 0;
	};
	fclose (archivoDeEntrada);
	fclose (archivoDeSalida);
	printf ("Archivo creado.");
	return 0;
};






