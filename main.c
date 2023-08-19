#include <stdio.h>
#include <stdlib.h>

// Grupo: Gabriel Guidetti Gonzalez

const int INITIAL_SIZE = 4;

int * initVet(int *size, int *maxSize);
void printVet (int *v, int size, int maxSize);
int * addVet(int *v, int *size, int *maxSize, int e);
int * createVectorWithDoubleSize(int *v, int *size, int *maxSize);
int find(int *v, int size , int e);
int * removeVet( int *v , int *size , int *maxSize , int e );
int * recreateVector(int *v, int *size, int *maxSize);

void main()
{
    int size, maxSize;
    int *v;

    v = initVet(&size, &maxSize);

    //ADD VECTOR AND FIND ELEMENT TEST, THE MAX SIZE SHOULD BE MULTIPLIED BY 2 IF SIZE == MAXSIZE
    v = addVet(v, &size, &maxSize, 2);
    v = addVet(v, &size, &maxSize, 51);
    v = addVet(v, &size, &maxSize, 23);
    v = addVet(v, &size, &maxSize, 70);
    v = addVet(v, &size, &maxSize, 51);

    printVet(v, size, maxSize);

    printf("\n");
    printf("\n");

    printf("Position of 51: %d\n", find(v, size, 51));
    printf("Position of 70: %d\n", find(v, size, 70));
    printf("Position of 17: %d\n", find(v, size, 17)); // should return -1 if the element doesn't exist in the vector

    printf("\n");
    printf("\n");
    printf("\n");

    // DELETE ELEMENT TEST, THE SIZE OF VECTOR SHOULD BE DIVIDED BY 2 IF THE SIZE IS LESS THAN 1/4 OF MAXSIZE
    int *v2;
    v2 = initVet(&size, &maxSize);

    v2 = addVet(v2, &size, &maxSize, 1);
    v2 = addVet(v2, &size, &maxSize, 2);
    v2 = addVet(v2, &size, &maxSize, 3);
    v2 = addVet(v2, &size, &maxSize, 4);
    v2 = addVet(v2, &size, &maxSize, 5);

    v2 = removeVet(v2, &size, &maxSize, 3);
    v2 = removeVet(v2, &size, &maxSize, 2);
    v2 = removeVet(v2, &size, &maxSize, 5);
    v2 = removeVet(v2, &size, &maxSize, 1);

    printVet(v2, size, maxSize);
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
        printf("Element %d = %d\n",i+1, *(v+i));
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

int find(int *v, int size , int e) {
    int i;

    for(i = 0; i < size; i++) {
        if(*(v+i) == e){
            return ++i;
        }
    }

    return -1;
}

int * removeVet( int *v , int *size , int *maxSize , int e ) {
    int i;

    for(i = 0; i < *size; i++) {
        if(*(v+i) == e) {
            *(v+i) = NULL;

            v = recreateVector(v, size, maxSize);

            break;
        }
    }

    return v;
}

int * recreateVector(int *v, int *size, int *maxSize) {
    int i = 0;

    for(i = 0; i < *size; i++) {
        if(*(v+i) == NULL && i != *(size)-1) {
            *(v+i) = *(v+i+1);
            *(v+i+1) = NULL;
        }
    }

    *size = *size-1;

    if((*size) <  *(maxSize)*25/100) {
        *maxSize = *maxSize / 2;
        int *newVector;
        int j;

        newVector = calloc(*maxSize, sizeof(int));

        for(j = 0; j < *size; j++) {
            *(newVector+j) = *(v+j);
        }

        v = newVector;
    }

    return v;

}
