#include <stdio.h>
#include <cs50.h>

int main(void)
{
// INT
    int intHeight = 0;
    
    do
    {
        printf("Height: ");
        intHeight = GetInt();
    }
    while(intHeight < 0 || intHeight > 23 );

    for(int pyramidHeight = 0; pyramidHeight < intHeight; pyramidHeight++)
    {
        for(int spaces = intHeight; spaces > pyramidHeight + 1; spaces = spaces - 1 )
        {
            printf(" ");
        }
        for(int levelWidth = 0; levelWidth < pyramidHeight + 1; levelWidth++ )
        {
            printf("#");
        }
        printf("#\n");
    }
}
