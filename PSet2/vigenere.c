#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// prototype
int Checker(string key, string userInput);
int Cipher(int userInput, int key, int asciiValue);
int Printer(int *encryptString, int inputLength);

int main(int argc, string argv[])
{

// STRING
    //userInput
    //key
    
    // If arguments given to program is not equal to 2 the program will not run and will return to user proper use of program.
    if(argc != 2)
    {
        printf("Useage: ./devigenere key\n - key must be positive string. \n");
        return 1;
    }
    else
    {
        string key = argv[1];

        for(int i = 0; i < strlen(key);i++)
        {
            if(!isalpha(key[i]))
            {
                printf("Y U DIGIT!?! \n");
                return 1;
            } 
        }
        
        string userInput = GetString();
        Checker(key, userInput);
        return 0;
     }
}

int Checker(string key, string userInput)
{
// INT
    int inputLength = strlen(userInput);
    int keyLength = strlen(key);  
    int keyIndex = 0; // this is to step through the key letter by letter in order to use them as the offset.
    int *encryptString = malloc(sizeof(int) * inputLength); // creates a pointer to a chunck of memory which holds 1 int for the total of the inputs length. (is input length is 12 you will end up with an array of 12 ints)
    
    for(int i = 0, n = inputLength; i < n; i++ )
    {
        // When the counter for the keys index reaches the end this will reset the counter back to 0.
        // This will allow the program to reuse the key as needed
        if(keyIndex == keyLength)
        {
            keyIndex = 0;
        }
        
        if(isupper(userInput[i]))
        {
            encryptString[i] = Cipher(userInput[i], key[keyIndex], 65);
            keyIndex++;
        }
        else if(islower(userInput[i]))
        {
            encryptString[i] = Cipher(userInput[i], key[keyIndex], 97);
            keyIndex++;
        }
        else
        {
            encryptString[i] = userInput[i];
        }
    }
    
    Printer(encryptString, inputLength);
    return 0;
}

int Cipher(int userInput, int key, int asciiValue)
{
// INT
    int userHolder = 0; // Temp holding variable for the next character to be changed.
    int keyHolder = 0; // Temp holding variable for the next key to be used.
    int ciphertext = 0; // Temp holding variable for the ciphertext value to be returned to calling function;
    
    if((userInput + key) > (char)asciiValue)
    {
        userHolder = userInput - asciiValue;
        if(isupper(key))
        {
            keyHolder = key - 65;
        }
        else if(islower(key))
        {
            keyHolder = key - 97;
        }
        
        ciphertext = (( userHolder + keyHolder ) % 26) + asciiValue;
    }
    else
    {
        ciphertext = userInput + key ;
    }
    
    return ciphertext;
}

int Printer(int *encryptString, int inputLength)
{
    for(int i = 0; i < inputLength; i++)
    {
        printf("%c", encryptString[i]);
    }
    printf("\n");
    return 0;
}