#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Parameters
int I;
int h;
int D;
int W;


void readFile( FILE *fp ) {
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        exit(EXIT_FAILURE);

    while( getline(&line, &len, fp) != -1 ) {
        line = strtok(line, "\r\n");
        //printf("%c", *line);
        if( line[0] != '#' ) {

            if( strcmp(line, "SECTION_HORIZON") ==0 ) {
                getline(&line, &len, fp);
                while( line[0] == '#' ) {
                    getline(&line, &len, fp);
                }
                I = atoi(line);
                break;
                
            }
        }
    }
    

    
    if(line)
        free(line);
}




int main( int argc, char *argv[] ) {
    
    if( argc == 3) {
        FILE *fp;
        fp = fopen(argv[1], "r");
        readFile(fp);
        fclose(fp);
        printf("%d",I);

    } else {
        printf("Revise los parámetros de inicialización.");
        return 1;
    }   
    return 0;
}