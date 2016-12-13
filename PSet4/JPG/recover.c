/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    FILE* card = fopen("card.raw","r");
    if(card == NULL)
    {
        printf("File failed to open.");
        return 1;
    }

    uint8_t buffer[512];
    char title[10];
    int titleCount = 0;
    FILE* outptr = NULL;
    int stage = 0 ;

    while(fread(&buffer, sizeof(uint8_t), 512, card))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8  && buffer[2] == 0xff  )
        { 
            if(buffer[3] == 0xe1 || buffer[3] == 0xe0)
            {
                if(stage == 2)
                {
                    fclose(outptr);
                }
                stage = 1;
            }            
        }

        if(stage == 1)
        {
            sprintf(title, "%.3d.jpg", titleCount);  
            titleCount++;      
            outptr = fopen(title, "a");
            stage = 2;
        }

        if(stage == 2)
        {
            fwrite(&buffer, sizeof(uint8_t), 512, outptr);
        }
    }

    fclose(outptr);
    fclose(card);
    return 0;
}
