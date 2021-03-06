/*
STRING4
=======

Escreva um programa que leia N strings e imprima a maior string lida.

Entrada
-------

A entrada é composta com um único caso de teste. A primeira linha do caso de
teste possui um número inteiro N (1<= N <= 1000), a seguir existem N linhas,
cada uma contendo uma única string, sem espaços, de tamanho T (1<= T <=
100).

Saída
-----

A saída deverá conter uma única linha contendo a maior string lida. Havendo
mais de uma string contendo o mesmo maior tamanho, imprima a primeira.

Exemplo:
-------

Entrada:
3
Sol
Fundamentos
Foguete

Saída:
Fundamentos

Exemplo:
--------
Entrada:
3
Sol
Nina
Maca

Saída:
------
Nina
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 10000

int main()
{
	int inputValue = 0;
	char greaterString[MAX_STRING_LEN];
	while(1)
	{

		char auxInput[MAX_STRING_LEN];

	    //printf("Enter:");

		fgets(auxInput, MAX_STRING_LEN, stdin);

		//CHECK WHETHER THE INPUT IS EOF, IF TRUE, BREAK!      
		if(feof(stdin))
		{
			break;
		}
		else
		{

			int greaterValue=0;
			int auxLoop =atoi(auxInput);

			for(int i=0;i<auxLoop;i++){

				//printf("Enter the names:");

				fgets(auxInput, MAX_STRING_LEN, stdin);

				//printf("%d\n", strlen(auxInput)-1);

				if(greaterValue<(strlen(auxInput)-1)){

					greaterValue =strlen(auxInput)-1;
					
					strcpy(greaterString,auxInput);
				}
				
			}

			printf("%s",greaterString);
		}
	}
}
