/** 
 *Title: caesar.c 
 *
 *Programmer: Pietro Foglia 
 *
 * return numbers:
 * -0 > Retruns complete no errors;
 * -1 > Returns with errors, no specific reason;
 * 
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h> 

// prototype
int Encrypter(int key, string userInput);
int Printer(int printString[], int inputLength);


int main(int argc, string argv[])
{
// INT
    int key = 0;
// STRING
    //userInput
    
    // If arguments given to program is not equal to 2 the program will not run and will return to user proper use of program.
    if(argc != 2)
    {
        printf("Useage: ./caesar key\n - key must be positive number. \n");
        return 1;
    }
    else
    {
        // atoi function makes a string integer represent its true interger value.
        key = atoi(argv[1]);

        if(key < 0)
        {
            printf("Y U NO LISTEN!?! \n");
            return 1;
        }
        else
        { 
            string userInput = GetString();
            Encrypter(key, userInput);
        }    
     }
}

int Encrypter(int key, string userInput)
{
// INT
    int inputLength = strlen(userInput);
    int encryptString[inputLength];
    int holder = 0;
    
    for(int i = 0; i < inputLength; i++)
    {
        // Checks to see if 
        if(isupper(userInput[i]))
        {
            if( (userInput[i] + key) > 'Z' )
            {
                holder = userInput[i] - 'A';   
                encryptString[i] = (( holder + key ) % 26) + 'A';
            }
            else
            {
                encryptString[i] = userInput[i] + key;
            }
        }
        else if(islower(userInput[i]))
        {
            if( (userInput[i] + key) > 'z' )
            {
                holder = userInput[i] - 'a';   
                encryptString[i] = (( holder + key ) % 26) + 'a';
            }
            else
            {
                encryptString[i] = userInput[i] + key;
            }
        }
        else
        {
            encryptString[i] = userInput[i];
        }
    }
    
    if(Printer(encryptString, inputLength))
    {
        return 0;
    }
    else
    {
        return 1;   
    }
}

int Printer(int printString[], int inputLength)
{
    for(int x = 0; x < inputLength; x++ )
    {
        printf("%c", (char) printString[x]);
    }
    printf("\n");
    return 0;
}