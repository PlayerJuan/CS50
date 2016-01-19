/** 
 *Title: 
 *
 *Programmer: Pietro Foglia 
 *
 *Program Purpose: 
 *
 *Last Updated: 
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    
    printf("Please enter a non-negative number which is no greater then 23: ");
    do
    {
        if(height < 0 || height > 23)
        {
            printf("Retry: ");
        }
        height = GetInt();
    }
    while(height < 0 || height > 23 );
     
    int maxLine = height + 1;
    int hashCounter = maxLine;
    
    for(int i = 0; i < height; i++)
    {
        for(int x = 0; x <= maxLine; x++)
        {
            if(x > hashCounter - 2)
            {
                printf("#");  
            }
            else if(x < hashCounter - 2)
            {
                printf(" ");
            }
        }
        hashCounter = hashCounter - 1;
        printf("\n");
    }
}
