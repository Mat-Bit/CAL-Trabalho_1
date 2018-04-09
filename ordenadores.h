#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

#define D25 25000
#define D50 50000
#define D75 75000
#define D100 100000
#define D1000 1000000
#define TAM_BUK 1000
#define NUM_BUK 1000

typedef struct {
    long long topo;
    long long balde[TAM_BUK];
}v_bucket;



double wtime();
int verifOrd(long long v[], int size);

void bubble(long long v[], int size);
void insertion(long long v[], int size);
void merge( long long vet[], int ini, int fim);
void doMerge( long long vet[], int ini, int meio, int fim);
int pivoFirst( long long vet[], int ini, int fim);
void quickFirst( long long vet[], int ini, int fim);
int pivoRand( long long vet[], int ini, int fim);
void quickRand( long long vet[], int ini, int fim);
void buildHeap( long long vet[], int tam);
void heapfy( long long vet[], int tam, int i);
void heap( long long vet[], int tam);
void countSort(long long vet[], int tam);
void bucket( long long vet[], int tam, int op);
void bubble2(long long v[],int tam);
