#include <stdio.h>
#include <string.h>
//el objetivo es clasificar el tipo de constante entera que es 
//mediante el uso del automata de c




/*USANDO EL ENUM
//esta funcion va a devolver en que categoria entra el caracter que recibio
typeOfEntry clasificarChar (char unChar){
	if (unChar == ' '){return space;};
	if (unChar == '0'){return zero;};
	if (unChar == '1' || unChar == '2'|| unChar == '3'|| unChar == '4'|| unChar == '5'|| unChar == '6'|| unChar == '7'){return octalEntry;};
	if (unChar == 'a' || unChar == 'b'|| unChar == 'c'|| unChar == 'd'|| unChar == 'e'|| unChar == 'f'){return hexEntry;};
	if (unChar == 'A' || unChar == 'B'|| unChar == 'C'|| unChar == 'D'|| unChar == 'E'|| unChar == 'F'){return hexEntry;};
	if (unChar == 'X' || unChar == 'x'){return x;};	
	if (unChar == '8' || unChar == '9'){return decimalEntry;};
	else return err;
}
*/

// SIN USAR EL ENUM
//esta funcion va a devolver en que categoria entra el caracter que recibio
int clasificarChar (char unChar){
	int a = 7;
	if (unChar == ' '){a=1;};
	if (unChar == '0'){a=2;};
	if (unChar == '1' || unChar == '2'|| unChar == '3'|| unChar == '4'|| unChar == '5'|| unChar == '6'|| unChar == '7'){a=3;};
	if (unChar == 'a' || unChar == 'b'|| unChar == 'c'|| unChar == 'd'|| unChar == 'e'|| unChar == 'f'){a=5;};
	if (unChar == 'A' || unChar == 'B'|| unChar == 'C'|| unChar == 'D'|| unChar == 'E'|| unChar == 'F'){a=5;};
	if (unChar == 'X' || unChar == 'x'){a=6;};	
	if (unChar == '8' || unChar == '9'){a=4;};
	return a;
};


//en esta funcion se genera la produccion devolviendo lo de la tabla (resolver en una linea)
//int changeStatus(int currentStatus, typeOfEntry type);

//El estado es final? -1 = NO, 1 = SI
int isFinalStatus(int status){
	if(status == 1 || status == 2 ||status == 3 ||status == 5){   //NO ESTOY SEGURO QUE ESTOS SEAN LOS ESTADOS FINALES
		return 1;
	}
		else return -1;
};

//utiliza isFinalStatus para saber que sea final y si no lo es devuelvo 
//'err' si es final devuelve una cadena 
//ej: 'constante hexadecimal'
//se utiliza un shwitch con el enum
//terminar linea con \n
//bool getResult(int status);

//escribe en el archivo de resultado la cadena
//void addResult(char* textToPrint, FILE);

char* concatenate(char* a, char b){
	int tamanioA, tamanioB, i, j;
	tamanioA = strlen (a);
	tamanioB = 1;
	int size = tamanioA + tamanioB;
	char s[size];
	
	for(i = 0; i < tamanioA; i++){
		s[i] = a[i];	
		
	};

	s[tamanioA] = b;
		
	char* r = s;
	return r;

};

int main(int argc, char const *argv[])
{

	int productions[7][7] = {
		{0,2,1,1,6,6,6},
		{0,1,1,1,6,6,6},
		{0,3,3,6,6,4,6},
		{0,3,3,6,6,6,6},
		{0,5,5,5,5,6,6},
		{0,5,5,5,5,6,6},
		{0,6,6,6,6,6,6}
		
	};

	//int finalStatus[?] = {};

	enum typeOfEntry {  space,                    //' '
						zero,                     //0
						octalEntry,               //1-7
						decimalEntry,             //8,9
						hexEntry,                 //A-F, a-f
						x,                        //X,x
						err                       //other
	} ;



	int currentStatus = 0;
	char* currentWord = "";

	
	FILE *archivoDeEntrada = fopen( argv[1], "r" );  
	FILE *archivoDeSalida = fopen( "archivoDeSalida.txt", "w" );  


	while(!feof(archivoDeEntrada)){   // Mientras no termine el archivo de entrada

		char nextChar; //proxima letra del archivo, DECLARARLO

		currentWord = concatenate( currentWord, nextChar);

		// USANDO EL ENUM
		//typeOfEntry type = clasificarChar (nextChar);
		// SIN USAR EL ENUM
		int tipoDeChar = clasificarChar (nextChar);

		//int newStatus = changeStatus(currentStatus, type);

		//si el nuevo caracter vuelve a q0 y se estaba en otro estado se 
		//corta la palabra
		/*if(newStatus == 0 && currentStatus =! 0){

			char* result = getResult(currentStatus);
			char* pResult = concatenate(currentWord, result);

			currentWord = ''; //juraria que esta sentencia esta mal, pero la idea se entiende 
			addResult(pResult, archivoDeSalida);

		}

		currentStatus = newStatus;*/
	};

	fclose (archivoDeEntrada);
	fclose (archivoDeSalida);

	
	return 0;
};