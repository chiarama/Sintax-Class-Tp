#include <stdio.h>
#include <stdbool.h>

//ejercicio 20
int length(char s[]){
   int c = 0;
   char a = s[0];
   while(a != '\0'){
      c++;
      a = s[c];
   }
   return c;
}




bool isEmpty(char s[]){
   return length(s)==0 ? 1 : 0;
}

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

//programa que prueba las funciones. (ejercicio 21)
int main(void){
	char *a = "hollla";
	char *b = "noooo";
	char *c =	concatenate(a,b);
	printf("la longitud del cadena hollla es %d \n", length(a));
	printf("esta vacio? %i \n", isEmpty(a));
	printf("concatenacion: %s \n", concatenate(a,b));
}
