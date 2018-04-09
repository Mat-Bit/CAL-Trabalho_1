#include "ordenadores.h"

/*
Para compilar:
gcc -Wall -o teste01 main.c ordenadores.c
./teste01 tam tipo
    tam: 25000, 50000, 75000, 100000, 1000000
    tipo: 1 (cresc), 2 (decresc), 3 (Aleatorio), 4 (Aleatorio alto)
ex:
./teste01 25000 1
*/


long long v25[D25];
long long v50[D50];
long long v75[D75];
long long v100[D100];
long long vMil[D1000];

void leArqParaVet(FILE *arquivo, long long v[], int tam){
    printf("Lendo arquivo de %d numeros...\n", tam);
    int i;
    long long valor;
    fseek(arquivo, 0, SEEK_SET);
    //printf("Os primeiros e os ultimos 10 valores do vetor desordenado sao:\n");

    for (i = 0; i < tam; i++) {
        fscanf(arquivo, "%lld", &valor);
        v[i] = valor;
        if (i < 10 || (tam-i) < 10){
            //printf("v[%d] = %lld\n", i+1, v[i]);
        }
    }
}

void menu(){
    printf("\n\tAlgoritmos de Ordenacao:\n");
    printf("1: BubbleSort\t2: InsertionSort\t3: MergeSort\n");
    printf("4: QuickSort 1\t5: QuickRand\t\t6: HeapSort\n");
    printf("7: CountingSort\t8: BucketSort\n\n");
}

char *criaNomeRelat(int tam, int tipo){
    char *nome;

    nome = malloc(sizeof(char) * 30);
    if(sprintf(nome, "%d - %d.txt", tam, tipo)){
        return nome;
    }
    else{
        printf("Falha na criacao do nome do arquivo\n");
        exit(-1);
    }

}

int main(int argc, char const *argv[]) {
    double start_time, end_time, soma;
    int op, tamanho, tipo;
    FILE *entrada, *saida;
    entrada = fopen("entrada.txt", "r");
    tamanho = atoi(argv[1]);
    tipo = atoi(argv[2]);
    char *nome;
    nome = malloc(sizeof(char) * 30);

    switch (tamanho) {
        case D25:
            switch (tipo) {
                case 1:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Crescente\n\n", tamanho);
                    break;
                case 2:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Decrescente\n\n", tamanho);
                    break;
                case 3:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio\n\n", tamanho);
                    break;
                case 4:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio alto\n\n", tamanho);
                    break;
            }
            menu();
            op = 1;
            while(op != 9){
                leArqParaVet(entrada, v25, D25);
                printf("Opcao %d:\n", op);
                switch (op) {
                    case 1:
                        start_time = wtime();
                        bubble(v25, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUBBLE sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - BubbleSort:\t\t%lf seg\n", soma);
                        break;
                    case 2:
                        start_time = wtime();
                        insertion(v25, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O INSERTION sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - InsertionSort:\t%lf seg\n", soma);
                        break;
                    case 3:
                        start_time = wtime();
                        merge(v25, 0, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O MERGE sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - MergeSort:\t\t%lf seg\n", soma);
                        break;
                    case 4:
                        start_time = wtime();
                        quickFirst(v25, 0, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort 1 (pivo = primeiro) levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - QuickSort 1:\t\t%lf seg\n", soma);
                        break;
                    case 5:
                        start_time = wtime();
                        quickRand(v25, 0, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort rand levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - QuickSort 2:\t\t%lf seg\n", soma);
                        break;
                    case 6:
                        start_time = wtime();
                        heap(v25, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O HEAP sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - HeapSort:\t\t%lf seg\n", soma);
                        break;
                    case 7:
                        if(tipo == 4){
                            fprintf(saida, " - CoutingSort:\t\tSegment. Fault\n");
                            break;
                        }
                        start_time = wtime();
                        countSort(v25, D25);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O COUNTING sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - CoutingSort:\t\t%lf seg\n", soma);
                        break;
                    case 8:
                        start_time = wtime();
                        bucket(v25, D25, tipo);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v25, D25)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUCKET sort levou %lf seg para ordenar %d itens.\n\n", soma, D25);
                        fprintf(saida, " - BucketSort:\t\t%lf seg\n", soma);
                        break;
                }
                op++;
            }
            break;
        case D50:
            switch (tipo) {
                case 1:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Crescente\n\n", tamanho);
                    break;
                case 2:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Decrescente\n\n", tamanho);
                    break;
                case 3:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio\n\n", tamanho);
                    break;
                case 4:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio alto\n\n", tamanho);
                    break;
            }
            menu();
            op = 1;
            while(op != 9){
                leArqParaVet(entrada, v50, D50);
                printf("Opcao %d:\n", op);
                switch (op) {
                    case 1:
                        start_time = wtime();
                        bubble(v50, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUBBLE sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - BubbleSort:\t\t%lf seg\n", soma);
                        break;
                    case 2:
                        start_time = wtime();
                        insertion(v50, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O INSERTION sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - InsertionSort:\t%lf seg\n", soma);
                        break;
                    case 3:
                        start_time = wtime();
                        merge(v50, 0, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O MERGE sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - MergeSort:\t\t%lf seg\n", soma);
                        break;
                    case 4:
                        start_time = wtime();
                        quickFirst(v50, 0, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort 1 (pivo = primeiro) levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - QuickSort 1:\t\t%lf seg\n", soma);
                        break;
                    case 5:
                        start_time = wtime();
                        quickRand(v50, 0, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort rand levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - QuickSort 2:\t\t%lf seg\n", soma);
                        break;
                    case 6:
                        start_time = wtime();
                        heap(v50, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O HEAP sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - HeapSort:\t\t%lf seg\n", soma);
                        break;
                    case 7:
                        if(tipo == 4){
                            fprintf(saida, " - CoutingSort:\t\tSegment. Fault\n");
                            break;
                        }
                        start_time = wtime();
                        countSort(v50, D50);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O COUNTING sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - CoutingSort:\t\t%lf seg\n", soma);
                        break;
                    case 8:
                        start_time = wtime();
                        bucket(v50, D50, tipo);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v50, D50)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUCKET sort levou %lf seg para ordenar %d itens.\n\n", soma, D50);
                        fprintf(saida, " - BucketSort:\t\t%lf seg\n", soma);
                        break;
                }
                op++;
            }
            break;
        case D75:
            switch (tipo) {
                case 1:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Crescente\n\n", tamanho);
                    break;
                case 2:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Decrescente\n\n", tamanho);
                    break;
                case 3:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio\n\n", tamanho);
                    break;
                case 4:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio alto\n\n", tamanho);
                    break;
            }
            menu();
            op = 1;
            while(op != 9){
                leArqParaVet(entrada, v75, D75);
                printf("Opcao %d:\n", op);
                switch (op) {
                    case 1:
                        start_time = wtime();
                        bubble(v75, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUBBLE sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - BubbleSort:\t\t%lf seg\n", soma);
                        break;
                    case 2:
                        start_time = wtime();
                        insertion(v75, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O INSERTION sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - InsertionSort:\t%lf seg\n", soma);
                        break;
                    case 3:
                        start_time = wtime();
                        merge(v75, 0, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O MERGE sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - MergeSort:\t\t%lf seg\n", soma);
                        break;
                    case 4:
                        start_time = wtime();
                        quickFirst(v75, 0, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort 1 (pivo = primeiro) levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - QuickSort 1:\t\t%lf seg\n", soma);
                        break;
                    case 5:
                        start_time = wtime();
                        quickRand(v75, 0, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort rand levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - QuickSort 2:\t\t%lf seg\n", soma);
                        break;
                    case 6:
                        start_time = wtime();
                        heap(v75, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O HEAP sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - HeapSort:\t\t%lf seg\n", soma);
                        break;
                    case 7:
                        if(tipo == 4){
                            fprintf(saida, " - CoutingSort:\t\tSegment. Fault\n");
                            break;
                        }
                        start_time = wtime();
                        countSort(v75, D75);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O COUNTING sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - CoutingSort:\t\t%lf seg\n", soma);
                        break;
                    case 8:
                        start_time = wtime();
                        bucket(v75, D75, tipo);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v75, D75)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUCKET sort levou %lf seg para ordenar %d itens.\n\n", soma, D75);
                        fprintf(saida, " - BucketSort:\t\t%lf seg\n", soma);
                        break;
                }
                op++;
            }
            break;
        case D100:
            switch (tipo) {
                case 1:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Crescente\n\n", tamanho);
                    break;
                case 2:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Decrescente\n\n", tamanho);
                    break;
                case 3:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio\n\n", tamanho);
                    break;
                case 4:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio alto\n\n", tamanho);
                    break;
            }
            menu();
            op = 1;
            while(op != 9){
                leArqParaVet(entrada, v100, D100);
                printf("Opcao %d:\n", op);
                switch (op) {
                    case 1:
                        start_time = wtime();
                        bubble(v100, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUBBLE sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - BubbleSort:\t\t%lf seg\n", soma);
                        break;
                    case 2:
                        start_time = wtime();
                        insertion(v100, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O INSERTION sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - InsertionSort:\t%lf seg\n", soma);
                        break;
                    case 3:
                        start_time = wtime();
                        merge(v100, 0, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O MERGE sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - MergeSort:\t\t%lf seg\n", soma);
                        break;
                    case 4:
                        start_time = wtime();
                        quickFirst(v100, 0, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort 1 (pivo = primeiro) levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - QuickSort 1:\t\t%lf seg\n", soma);
                        break;
                    case 5:
                        start_time = wtime();
                        quickRand(v100, 0, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort rand levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - QuickSort 2:\t\t%lf seg\n", soma);
                        break;
                    case 6:
                        start_time = wtime();
                        heap(v100, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O HEAP sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - HeapSort:\t\t%lf seg\n", soma);
                        break;
                    case 7:
                        if(tipo == 4){
                            fprintf(saida, " - CoutingSort:\t\tSegment. Fault\n");
                            break;
                        }
                        start_time = wtime();
                        countSort(v100, D100);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O COUNTING sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - CoutingSort:\t\t%lf seg\n", soma);
                        break;
                    case 8:
                        start_time = wtime();
                        bucket(v100, D100, tipo);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(v100, D100)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUCKET sort levou %lf seg para ordenar %d itens.\n\n", soma, D100);
                        fprintf(saida, " - BucketSort:\t\t%lf seg\n", soma);
                        break;
                }
                op++;
            }
            break;
        case D1000:
            switch (tipo) {
                case 1:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Crescente\n\n", tamanho);
                    break;
                case 2:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Decrescente\n\n", tamanho);
                    break;
                case 3:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio\n\n", tamanho);
                    break;
                case 4:
                    strcpy(nome, criaNomeRelat(tamanho, tipo));
                    saida = fopen(nome, "w");
                    fprintf(saida, "  Relatorio para arquivo de %d itens tipo: Aleatorio alto\n\n", tamanho);
                    break;
            }
            menu();
            op = 1;
            while(op != 9){
                leArqParaVet(entrada, vMil, D1000);
                printf("Opcao %d:\n", op);
                switch (op) {
                    case 1:
                        break;
                        start_time = wtime();
                        bubble(vMil, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUBBLE sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - BubbleSort:\t\t%lf seg\n", soma);
                        break;
                    case 2:
                        break;
                        start_time = wtime();
                        insertion(vMil, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O INSERTION sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - InsertionSort:\t%lf seg\n", soma);
                        break;
                    case 3:
                        start_time = wtime();
                        merge(vMil, 0, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O MERGE sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - MergeSort:\t\t%lf seg\n", soma);
                        break;
                    case 4:
                        start_time = wtime();
                        quickFirst(vMil, 0, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort 1 (pivo = primeiro) levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - QuickSort 1:\t\t%lf seg\n", soma);
                        break;
                    case 5:
                        start_time = wtime();
                        quickRand(vMil, 0, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O QUICK sort rand levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - QuickSort 2:\t\t%lf seg\n", soma);
                        break;
                    case 6:
                        start_time = wtime();
                        heap(vMil, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O HEAP sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - HeapSort:\t\t%lf seg\n", soma);
                        break;
                    case 7:
                        if(tipo == 4){
                            fprintf(saida, " - CoutingSort:\t\tSegment. Fault\n");
                            break;
                        }
                        start_time = wtime();
                        countSort(vMil, D1000);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O COUNTING sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - CoutingSort:\t\t%lf seg\n", soma);
                        break;
                    case 8:
                        start_time = wtime();
                        bucket(vMil, D1000, tipo);
                        end_time = wtime();
                        soma = end_time - start_time;
                        if (verifOrd(vMil, D1000)) printf("Ordenacao bem sucedida\n");
                        else printf("Falha na ordenacao\n");
                        printf("O BUCKET sort levou %lf seg para ordenar %d itens.\n\n", soma, D1000);
                        fprintf(saida, " - BucketSort:\t\t%lf seg\n", soma);
                        break;
                }
                op++;
            }
            break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}
