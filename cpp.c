#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int time;
    if ( argc < 2 || (time = atoi( argv[1] )) < 1)
        printf("Please enter %s+possitive inter\n", argv[0]);
    else
        for ( int i = 0; i < time; i++)
            printf("Hello, good looking!\n");

    return 0;
}
