#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#define BUF_SIZE 1024

typedef struct muestra {
    float* datos[43];
    int size;
} Muestra;

const char* getfield(char* line, int num){
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num){
            return tok;
        }
    }
    return NULL;
}


int main(){
    int tamanoMuestra = 0, i;
    FILE *input = fopen("ventanaNormalizada.txt","r");
    char buf[BUF_SIZE];
    Muestra *m = malloc(sizeof(Muestra*));
    fgets(buf, sizeof(buf), input);
    while(fgets(buf, sizeof(buf), input)){
        for(i=0; i<43; i++){
            char* tmp = strdup(buf);
            m->datos[i] = (float*) malloc(sizeof(float));
            void* t = (void *) getfield(tmp, i+1);
            if(!t) break;
            else m->datos[i][tamanoMuestra] = atof(t);
            printf("%f ",m->datos[i][tamanoMuestra]);
        }
        tamanoMuestra++;
        printf("\n");
    }
    printf("Tamaño Muestra: %d\n", tamanoMuestra);
}
