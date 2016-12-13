#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
// INT
    int changeInPenny = 0;
    int coinDeductionValue = 0;
    int totalCoinCount = 0;
// FLOAT
    float changeOwed = 0.0; 


    do
    {
        printf("How much change is owed: ");
        changeOwed = GetFloat();
    }
    while(changeOwed < 0.0);
    
    changeOwed = changeOwed * 100;
    changeOwed = roundf(changeOwed); 

    changeInPenny = changeOwed;

    while(changeInPenny > 0)
    {
        //Will change the coin deduction value depending on if the total value is more then the current coin deduction value.
        if(changeInPenny >= 25)  
        {
            coinDeductionValue = 25;
        }
        else if(changeInPenny >= 10) 
        {
            coinDeductionValue = 10;
        }
        else if(changeInPenny >= 5) 
        {
            coinDeductionValue = 5;
        }
        else
        {
            coinDeductionValue = 1;
        }

        changeInPenny = changeInPenny - coinDeductionValue;
        totalCoinCount++;
    }
    printf("%d\n", totalCoinCount);
}