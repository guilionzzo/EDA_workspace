#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFERSIZE 10000

#define DEBUG_SESSION 0

#ifdef DEBUG_SESSION
    #define PRINT 1
#endif

#ifndef DEBUG_SESSION
    #define PRINT 0
#endif

//
char* getUserInput(void);

void rot13( char * str );

int main() {

	char buffer[BUFFERSIZE];

    while(fgets(buffer, BUFFERSIZE , stdin)!=NULL)
    {
        int i,flagLoop=0;
        int j=0;

        char* aux=(char*)calloc(1,BUFFERSIZE);

        char* inputString = buffer;//getUserInput();

        if(inputString==0){break;}  // REACH THE EOF CASE

        if(DEBUG_SESSION){inputString ="pHpzp pfprpepvpnpqpbp pyprptpnpy";}

        for(i=0;i<strlen(inputString);i++){
            if(inputString[ i ]==' '){

                aux[j]=' ';
                j++;
                flagLoop=0;

            }else{
                if(flagLoop){
                    aux[j]=inputString[ i ];
                    j++;
                    flagLoop=0;
                }else{
                    flagLoop=1;
                }
    		}
        }

        if(DEBUG_SESSION){printf("%s\n",aux);}

        rot13(aux); // STRING ROTATION
        if(aux[strlen(aux)-1]=='\n'){
            printf("%s\n",aux);
        }else{
            printf("%s\n",aux);
        }


        //free(inputString);
    }

    return 0;
}

/*
FUCTION TO READ A USER INPUT
    IN CASE OF EOF SITUATION, RETURN -1
*/
char* getUserInput(void){

    char* inputValue=(char*)malloc(BUFFERSIZE); //ALOCATE A SPACE ON MEMORY

    char buffer[BUFFERSIZE];

    if(DEBUG_SESSION){printf("Enter a message: \n");}

    fgets(buffer, BUFFERSIZE , stdin);

    if(!fgets(buffer, BUFFERSIZE , stdin)){return 0;} // EOF return -1

    buffer[strlen(buffer)-1]='\0';

    strcpy(inputValue,buffer);

    return inputValue;
}

void rot13( char * str )
{
        int i = 0;

        /* You do this until you find a '\0' */
        for( i = 0; str[ i ] != '\0' ; i++ ){

            /* Use the pointer notation if you passed a pointer. */
            /* If the letter is between a and m you can simply  sum it. */
            if( (*( str + i ) >= 'a' && *( str + i ) < 'n')||  //LOWERCASE
               (*( str + i ) >= 'A' && *( str + i ) < 'N'))    //UPPERCASE
                *( str + i ) += 13;

            /* If the letter is between the n and z you have to do the opposite.*/
            else if((*( str + i ) >= 'n' && *( str + i ) <= 'z')||  //LOWECASE
                    (*( str + i ) >= 'N' && *( str + i ) <= 'Z'))   //UPPERCASE
                *( str + i ) -= 13;
        }
}
