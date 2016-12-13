/** 
 *Title: initials.c 
 *
 *Programmer: Pietro Foglia 
 * 
 *return numbers:
 * -0 > Retruns complete no errors;
 * -1 > Returns with errors, no specific reason;
 * 
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// prototype
void PrintInitials(char initials[], int initialCount);

int main()
{
// STRING
    string usersname = GetString();
// INT
    int nameLength = strlen(usersname);
    int initialCount = 0;
    int counter = 0;
    
    for(int i = 0; i < nameLength; i++ )
    {
        if(usersname[i] == ' ' && usersname[i + 1] != '\0' && usersname[i + 1] != ' ' )
        {
            initialCount++;
        }
        else if(i == 0)
        {
            initialCount++;
        }
    }
    
    //will initialize an array thats holds a the size of a char in total of as many first chars the computer finds 
    char *initials = malloc(sizeof(char) * initialCount);

    for(int y = 0; y < nameLength; y++ )
    {
        if(usersname[y] == ' ' && usersname[y + 1] != '\0' && usersname[y + 1] != ' ' )
        {
            initials[counter] = usersname[y + 1];
            counter++;
        }
        else if(y == 0)
        {
            initials[counter] = usersname[y];
            counter++;
        }
    }
    
    PrintInitials(initials, initialCount);

    printf("\n");
    return 0;
}


void PrintInitials(char initials[], int initialCount)
{
    
    // Prints chars out in capital letters
    for(int x = 0; x < initialCount; x++)
    {
        if(initials[x] >= 'a' && initials[x] <= 'z' )
        {
            printf("%c", initials[x] - ('a' - 'A'));
        }
        else
        {
            printf("%c", initials[x]);
        }   
    }
}