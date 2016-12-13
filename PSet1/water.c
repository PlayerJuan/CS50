#include <stdio.h>
#include <cs50.h>

int main(void)
{
// INT
    float minutes = 0;
// FLOAT
    float ounceWaterPerMin = 0.0;
    float bottles = 0.0;


    do
    {
        printf("minutes: ");
        minutes = GetFloat();
    }
    while(minutes < 0);

    ounceWaterPerMin = minutes * 1.5;
    ounceWaterPerMin = ounceWaterPerMin * 128.0;
    bottles = ounceWaterPerMin / 16.0;
    
    printf("bottles: %.0f  \n", bottles);
}