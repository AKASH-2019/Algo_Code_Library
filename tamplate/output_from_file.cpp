#include<stdio.h>


int main()
{
    FILE * fPtr;

    char ch;



    fPtr = freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);


    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
     
    }


    
    printf("File opened successfully. Reading file contents character by character. \n\n");

    do 
    {
        ch = fgetc(fPtr);
        
        /// check the id...

        putchar(ch);

    } while(ch != EOF);


    
    fclose(fPtr);


    return 0;
}
