/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

// prototype
int binary_search(int key, int values[], int first, int last);

/**
 * Returns true if value is in array of n values, else false.
 * (needle, haystack, sizeOfStack)
 * valueSize has already been decremented by previous function 
 * 
 */
 
bool search(int value, int values[], int n)
{
    if(n < 0)
    {
        return 0;    
    }
    else
    {
        // Passes to recusive function  all values that were passed in from 
        if(binary_search(value, values,0,n - 1))
        {
            return 1;        
        }
        else
        {
            return 0;
        }
    }
}
 
int binary_search(int key, int values[], int first, int last)
{  
    int middle = ( first + last ) / 2;

    if(key == values[middle])
    {
        return 1; 
    }
    else if(last <= first || middle < 0)
    {
        return 0;
    }
   
    
    if(key > values[middle] )
    {
        first = middle + 1;
    }
    else
    {
        last = middle - 1;
    }
    return binary_search(key, values, first, last);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int tempValue = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(values[j] < values[i])
            {
                // assigns [i]th value to a temp variable.
                tempValue = values[j];
                
                // assigns the min value index to the [i]th value in the array.
                values[j] = values[i];
                
                
                // assigns the value that was stored in the temp variable back into the array
                values[i] = tempValue;
            }
        }
     }
    return;
}