#include <stdio.h>
#include <stdlib.h>

// Grupo: Gabriel Guidetti Gonzalez

const int INITIAL_SIZE = 4;

int * initVet(int *size, int *maxSize);
void printVet (int *v, int size, int maxSize);
int * addVet(int *v, int *size, int *maxSize, int e);
int * createVectorWithDoubleSize(int *v, int *size, int *maxSize);

void main()
{
    int size, maxSize;
    int *v;

    v = initVet(&size, &maxSize);

    v = addVet(v, &size, &maxSize, 2);
    v = addVet(v, &size, &maxSize, 51);
    v = addVet(v, &size, &maxSize, 23);
    v = addVet(v, &size, &maxSize, 70);

    printVet(v, size, maxSize);
}

int * initVet(int *size, int *maxSize) {
    int *v;
    *size = 0;
    *maxSize = INITIAL_SIZE;

    v = calloc(INITIAL_SIZE, sizeof(int));

    return v;
}

void printVet (int *v, int size, int maxSize) {
    int i;

    printf("SIZE: %d\n", size);
    printf("MAX SIZE: %d\n", maxSize);

    for(i = 0; i < size; i++)
        printf("%d - %d\n",i+1, *(v+i));
}

int * addVet(int *v, int *size, int *maxSize, int e) {
    if(*size == *maxSize) {
        int *tempVector, i;

        tempVector = createVectorWithDoubleSize(v, size, maxSize);

        for(i = 0; i < *size; i++) {
            *(tempVector+i) = *(v+i);
        }

        v = tempVector;
    }

    v[*size] = e;
    *size = *size + 1;

    return v;
}

int * createVectorWithDoubleSize(int *v, int *size, int *maxSize) {
    *maxSize = *maxSize * 2;
    int *newVector;

    newVector = calloc(*maxSize, sizeof(int));

    return newVector;
}



















