#include <stdio.h>
//el objetivo es clasificar el tipo de constante entera que es 
//mediante el uso del automata de c

int main(int argc, char const *argv[])
{

	int productions[6][6] = {
		{0,2,1,1,6,6,6},
		{0,1,1,1,6,6,6},
		{0,3,3,6,6,4,6},
		{0,3,3,6,6,6,6}
		{0,5,5,5,5,6,6},
		{0,5,5,5,5,6,6},
		{0,6,6,6,6,6,6}
		
	}

	int finalStatus[?] = {}

	enum typeOfEntry {  space, //' '
						zero, //0
						octalEntry, //1-7
						decimalEntry, //8,9
						hexEntry, //A-F, a-f
						x, //X,x
						err //other
	}



	int currentStatus = 0;
	char currentWord* = '';

	//aqui abrir archivo por linea de argumentos
	FILE *f = fopen( argv[1], "r" );  //algo asi (?)

	//fw = crear archivo 

	//mientras no se temine el flujo del archivo
	while(/*endof(f)*/){ 
		char next = //proxima letra del archivo

		currentWord = concatenate( currentWord, next);

		typeOfEntry type = classify(next);

		int newStatus = changeStatus(currentStatus, type);

		//si el nuevo caracter vuelve a q0 y se estaba en otro estado se 
		//corta la palabra
		if(newStatus == 0 && currentStatus =! 0){

			char result* = getResult(currentStatus);
			char pResult* = concatenate(currentWord, result);

			currentWord = ''; //juraria que esta sentencia esta mal, pero la idea se entiende 
			addResult(pResult, fw);



		}

		currentStatus = newStatus;
	}

	//cerrar ambos archivos
	//finaliza programa
	return 0;
}



//esta funcion va a devolver en que categoria entra el caracter que recibio
typeOfEntry classify (char c);

//en esta funcion se genera la proddcuion devolviendo lo de la tabla (resolver en una linea)
int changeStatus(int currentStatus, typeOfEntry type);

//devolver si el estado es final
bool isFinalStatus(int status);

//utiliza isFinalStatus para saber que sea final y si no lo es devuelvo 
//'err' si es final devuelve una cadena 
//ej: 'constante hexadecimal'
//se utiliza un shwitch con el enum
//terminar linea con \n
bool getResult(int status);

//escribe en el archivo de resultado la cadena
void addResult(char* textToPrint, file);

char* concatenate(char a[], char b[]){
	int size = length(a) + length(b);
	char s[size];
	
	for(int i = 0; i < length(a); i++){
		s[i] = a[i];	
		
	}

	for(int i = length(a); i< size; i++){
		s[i] = b[i-length(a)];	
		
	}
		
	char *r = s;
	return r;

}