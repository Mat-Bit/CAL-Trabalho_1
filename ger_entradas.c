#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
  Para compilar:
    gcc -Wall -o entrada ger_entradas.c
    ./entrada tam op
    tam: 25000, 50000, 75000, 100000, 1000000
    op: 1 (cresc), 2 (decresc), 3 (Aleatorio), 4 (Aleatorio alto)
    ex:
    ./ent 75000 3
*/

#define D25 25000
#define D50 50000
#define D75 75000
#define D100 100000
#define D1000 1000000


int main(int argc, char const *argv[]) {
  FILE *arq;
  int num, i, op, cond = 0, aleat;
  long long valor;

  arq = fopen("entrada.txt", "w");
  if (arq == NULL){ // Se nào conseguiu criar
      printf("Problemas na CRIACAO do arquivo\n");
      exit(-1);
  }
  // Tamanho do vetor
  num = atoi(argv[1]);
  /* Tipo de ordenacao:
      1: Crescente
      2: Decrescente
      3: Aleatorio
      4: Aleatorio com surpresa */
  op = atoi(argv[2]);

  // Se o numero passado por parametro for igual a um tamanho valido:
  switch (num) {
    case D25:
      switch (op) {
        case 1:
        printf("Gerando arquivo de 25000 numeros crescentes..\n");
          for (i = 0; i < D25; i++) {
            valor = i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 2:
          printf("Gerando arquivo de 25000 numeros decrescentes..\n");
          for (i = 0; i < D25; i++) {
            valor = D25 - i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 3:
          printf("Gerando arquivo de 25000 numeros aleatorios..\n");
          for (i = 0; i < D25; i++) {
            valor = rand() % D25;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 4:
          printf("Gerando arquivo de 25000 numeros aleatorios com surpresa..\n");
          for (i = 0; i < D25; i++) {
            aleat = rand() % (D25 / 100);
            valor = rand() % D25;
            if (cond == 0 && (aleat == valor || i > (D25 * 0.8))){
              printf("surpresa linha: %d\n", i+1);
              fprintf(arq, "100000000000\n");
              cond = 1;
            }
            else{
              fprintf(arq, "%lld\n", valor);
            }
          }
          break;
        default:
          printf("Opcao nao valida\n");
          fclose(arq);
          exit(-1);
      }
      fclose(arq);
      break;
    case D50:
      switch (op) {
        case 1:
          printf("Gerando arquivo de 50000 numeros crescentes..\n");
          for (i = 0; i < D50; i++) {
            valor = i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 2:
          printf("Gerando arquivo de 50000 numeros decrescentes..\n");
          for (i = 0; i < D50; i++) {
            valor = D50 - i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 3:
          printf("Gerando arquivo de 50000 numeros aleatorios..\n");
          for (i = 0; i < D50; i++) {
            valor = rand() % D50;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 4:
          printf("Gerando arquivo de 50000 numeros aleatorios com surpresa..\n");
          for (i = 0; i < D50; i++) {
            aleat = rand() % (D50 / 100);
            valor = rand() % D50;
            if (cond == 0 && (aleat == valor || i > (D50 * 0.8))) {
              printf("surpresa linha: %d\n", i+1);
              fprintf(arq, "100000000000\n");
              cond = 1;
            }
            else{
              fprintf(arq, "%lld\n", valor);
            }
          }
          break;
        default:
          printf("Opcao nao valida\n");
          fclose(arq);
          exit(-1);
      }
      fclose(arq);
      break;
    case D75:
      switch (op) {
        case 1:
          printf("Gerando arquivo de 75000 numeros crescentes..\n");
          for (i = 0; i < D75; i++) {
            valor = i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 2:
          printf("Gerando arquivo de 75000 numeros decrescentes..\n");
          for (i = 0; i < D75; i++) {
            valor = D75 - i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 3:
          printf("Gerando arquivo de 75000 numeros aleatorios..\n");
          for (i = 0; i < D75; i++) {
            valor = rand() % D75;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 4:
          printf("Gerando arquivo de 75000 numeros aleatorios com surpresa..\n");
          for (i = 0; i < D75; i++) {
            aleat = rand() % (D75 / 100);
            valor = rand() % D75;
            if (cond == 0 && (aleat == valor || i > (D75 * 0.8))){
              printf("surpresa linha: %d\n", i+1);
              fprintf(arq, "100000000000\n");
              cond = 1;
            }
            else{
              fprintf(arq, "%lld\n", valor);
            }
          }
          break;
        default:
          printf("Opcao nao valida\n");
          fclose(arq);
          exit(-1);
      }
      fclose(arq);
      break;
    case D100:
      switch (op) {
        case 1:
          printf("Gerando arquivo de 100000 numeros crescentes..\n");
          for (i = 0; i < D100; i++) {
            valor = i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 2:
          printf("Gerando arquivo de 100000 numeros decrescentes..\n");
          for (i = 0; i < D100; i++) {
            valor = D100 - i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 3:
          printf("Gerando arquivo de 100000 numeros aleatorios..\n");
          for (i = 0; i < D100; i++) {
            valor = rand() % D100;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 4:
          printf("Gerando arquivo de 100000 numeros aleatorios com surpresa..\n");
          for (i = 0; i < D100; i++) {
            aleat = rand() % (D100 / 100);
            valor = rand() % D100;
            if (cond == 0 && (aleat == valor || i > (D100 * 0.8))){
              printf("surpresa linha: %d\n", i+1);
              fprintf(arq, "100000000000\n");
              cond = 1;
            }
            else{
              fprintf(arq, "%lld\n", valor);
            }
          }
          break;
        default:
          printf("Opcao nao valida\n");
          fclose(arq);
          exit(-1);
      }
      fclose(arq);
      break;
    case D1000:
      switch (op) {
        case 1:
          printf("Gerando arquivo de 1000000 numeros crescentes..\n");
          for (i = 0; i < D1000; i++) {
            valor = i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 2:
          printf("Gerando arquivo de 1000000 numeros decrescentes..\n");
          for (i = 0; i < D1000; i++) {
            valor = D1000 - i;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 3:
          printf("Gerando arquivo de 1000000 numeros aleatorios..\n");
          for (i = 0; i < D1000; i++) {
            valor = rand() % D1000;
            fprintf(arq, "%lld\n", valor);
          }
          break;
        case 4:
          printf("Gerando arquivo de 1000000 numeros aleatorios com surpresa..\n");
          for (i = 0; i < D1000; i++) {
            aleat = rand() % (D1000 / 100);
            valor = rand() % D1000;
            if (cond == 0 && (aleat == valor || i > (D1000 * 0.8))){
              printf("surpresa linha: %d\n", i+1);
              fprintf(arq, "100000000000\n");
              cond = 1;
            }
            else{
              fprintf(arq, "%lld\n", valor);
            }
          }
          break;
        default:
          printf("Opcao nao valida\n");
          fclose(arq);
          exit(-1);
      }
      fclose(arq);
      break;
    default:
      printf("O tamanho passado por parametro nao eh valido\n");
      fclose(arq);
      exit(-1);
      break;
  }

  return 0;
}
