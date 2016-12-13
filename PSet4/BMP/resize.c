/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy [size] [infile] [outfile]\n");
        return 1;
    }

    // remember filenames
    int scaleSize = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    // Checks to make sure scale size in in a range between 1 and 100
    if(scaleSize < 1 || scaleSize > 100 )
    {
        printf("Usage: ./copy [size] [infile] [outfile]\n");
        printf(" -Please enter a number between 1 and 100!\n");
        return 4;
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // copies attributes from bf variable    
    BITMAPFILEHEADER bfResize = bf;
    // copies attributes from the bi variable
    BITMAPINFOHEADER biResize = bi;
     
     
//START of HEADERINFO change
    //Scales width of image by number provided 
    biResize.biWidth = biResize.biWidth * scaleSize;
    //Scales height of image by number provided 
    biResize.biHeight = biResize.biHeight * scaleSize;

    //calculate pixel storage.
    //bitPerPixel = 24; 
    double rowSize = floor((24 * biResize.biWidth + 31 ) / 32) * 4;
    long pixelArraySize = rowSize * abs(biResize.biHeight);

    // determine padding for scanlines
    long padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // determines padding for new file
    long paddingResize =  (4 - (biResize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Size of raw bitmap data(including padding)
    //Change image size. Takers size of TRIPLE(3) and multiples it by padding required for each line. 
    biResize.biSizeImage = pixelArraySize ;
    
    //Size of BMP file   
    bfResize.bfSize = biResize.biSizeImage + 54; //pixelArraySize;
//END of HEADERINFO change   

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfResize, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&biResize, sizeof(BITMAPINFOHEADER), 1, outptr);

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(int xx = 0; xx < scaleSize; xx++){
            // iterate over pixels in scanline
            for(int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for(int x = 0; x < scaleSize; x++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
                    
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < paddingResize; k++)
            {
                fputc(0x00, outptr);
            }
            // Sets the file pointer back to the begining of the line it just finished coping.
            fseek(inptr,-(bi.biWidth * sizeof(RGBTRIPLE) + padding),SEEK_CUR);  
        }        
       // Sets the file pointer back to the end of the line it just copied n number of times.
       fseek(inptr,(bi.biWidth * sizeof(RGBTRIPLE) + padding),SEEK_CUR);
    }

    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);
    // that's all folks
    return 0;
}