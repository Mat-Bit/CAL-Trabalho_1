#include "ordenadores.h"

double wtime(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}

int verifOrd(long long v[], int size){
    int i;
    //printf("Os primeiros e os ultimos 10 valores do vetor ordenado sao:\n");
    for(i=1; i<size; i++){

        if (i < 11){
          //printf("v[%d] = %lld\n", i, v[i-1]);
        }
        if (size-i <= 10){
          //printf("v[%d] = %lld\n", i+1, v[i]);
        }
        if(v[i]<v[i-1]){
            printf("\nFAIL!\n");
            return 0;
        }
    }
    return 1;
}

void bubble(long long v[], int size){
    int i, c;
    long long tmp;
    for(i=0; i<size; i++){
        for(c=0; c<size; c++){
            if(v[i]<v[c]){
                tmp = v[i];
                v[i] = v[c];
                v[c] = tmp;
            }
        }
    }
}

void insertion(long long v[], int size){
    int i, j;
    long long key;
    for (i = 1; i < size; i++){
        key = v[i];
        j = i-1;

        while (j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = key;
    }
}

void merge( long long vet[], int ini, int fim){
	int meio;
	//int k;
	if( fim - ini < 2){
		//printf("\nSaindo %i - %i\n", ini, fim);
		return;
	}
	meio = (fim + ini) / 2;
	//printf("ini: %i, fim: %i, meio: %i\n", ini, fim, meio);

	merge( vet, ini, meio);
	//for( k=ini; k<meio;k++)
	//	printf("%i ", vet[k]);
	//printf("\n");
	merge( vet, meio, fim);
	//for( k=meio+1; k<fim;k++)
	//	printf("%i ", vet[k]);
	//printf("\n");
	doMerge( vet, ini, meio, fim);
	//printf("\n");
    //	return 1;
}

void doMerge( long long vet[], int ini, int meio, int fim){
	//printf("doMerge %i : %i : %i\n", ini, meio, fim);
	int i, j, k;
    long long newVet[fim];
	//int *newVet;
	i = ini;
	j = meio;
	//newVet = malloc( (fim - ini +1) * sizeof(int));
	k = 0;
	while( (i < meio) && (j < fim)){
		if( vet[i] <= vet[j]){
			//printf("%i[%i] <= %i[%i]\n", vet[i], i, vet[j], j);
			newVet[k] = vet[i];
			i++;
		}else{
			//printf("%i > %i\n", vet[i], vet[j]);
			newVet[k] = vet[j];
			j++;
		}
		//printf("%i[%i]\n", newVet[k], k);
		k++;
	}
	//printf("i:%i %i j:%i %i k:%i %i\n", i, meio, j, fim, k, (fim - ini +1));
	if( i == meio){
		while( j < fim){
			newVet[k] = vet[j];
			//printf("j: %i[%i]\n", newVet[k], k);
			j++;
			k++;
		}
	}else{
		while( i < meio){
			newVet[k] = vet[i];
			//printf("i: %i[%i]\n", newVet[k], k);
			i++;
			k++;
		}
	}
	k = 0;
	i = ini;
	while( k < (fim-ini+1) && i < fim){
		vet[i] = newVet[k];
		//printf("%i ", vet[i]);
		k++;
		i++;
	}
	//free(newVet);
}

int pivoFirst( long long vet[], int ini, int fim){
    int pivo = ini;
    int i;
    long long aux =0;
    for( i = ini+1; i < fim; i++){
        if( vet[i] < vet[ini]){
            pivo++;
            aux = vet[i];
            vet[i] = vet[pivo];
            vet[pivo] = aux;
        }
    }
    aux = vet[ini];
    vet[ini] = vet[pivo];
    vet[pivo] = aux;
    //printf("pivo: %i  = %i\n", pivo, vet[pivo]);
    return pivo;
}

void quickFirst( long long vet[], int ini, int fim){
	int meio;
	//printf("ini: %i, fim: %i\n", ini, fim);
	if( ini >= fim){
		return;
	}
	meio = pivoFirst(vet, ini, fim);
	quickFirst(vet, ini, meio);
	quickFirst(vet, meio+1, fim);
	//return 1;
}

void quickRand( long long vet[], int ini, int fim){
	int meio;
	//printf("ini: %i, fim: %i\n", ini, fim);
	if( ini >= fim){
		return;
	}
	meio = pivoRand(vet, ini, fim);
	quickRand(vet, ini, meio);
	quickRand(vet, meio+1, fim);
}

int pivoRand( long long vet[], int ini, int fim){
	int pivo = ini + rand() % (fim - ini);
	int i;
    long long aux = 0;
	//printf("Troca %i[%i] por pivo %i[%i]\n", vet[ini], ini, vet[pivo], pivo);
	aux = vet[pivo];
	vet[pivo] = vet[ini];
	vet[ini] = aux;
	pivo = ini;
	for( i = ini+1; i < fim; i++){
		if( vet[i] < vet[ini]){
			//printf("Troca %i[%i] por %i[%i]\n", vet[i], i, vet[pivo+1], pivo+1);
			pivo++;
			aux = vet[i];
			vet[i] = vet[pivo];
			vet[pivo] = aux;
		}
	}
	aux = vet[ini];
	vet[ini] = vet[pivo];
	vet[pivo] = aux;
	//printf("Troca %i[%i] por pivo %i[%i]\n", vet[ini], ini, vet[pivo], pivo);
	//printf("Meio: %i[%i]\n", vet[pivo], pivo);
	return pivo;
}

void heap( long long vet[], int tam){
	int i;
    long long aux;
	buildHeap( vet, tam);
	for( i = tam-1; i > 0; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		heapfy(vet, i, 0);
	}
}

void heapfy( long long vet[], int tam, int i){
	int e, d;
    long long maior, aux;
	e = (2*i + 1);
	d = (2*i + 2);
	if( (e < tam) && ( vet[e] > vet[i]) )
		maior = e;
	else
		maior = i;

	if( (d < tam) && ( vet[d] > vet[maior]) )
		maior = d;

	if( maior != i){
		aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;
		heapfy( vet, tam, maior);
	}
}

void buildHeap( long long vet[], int tam){
	int i;
	for( i = tam/2; i >= 0; i--)
		heapfy( vet, tam, i);
}

void countSort(long long vet[], int tam){
	long long i, k;
	long long maior = 0;
	long long *aux;
	for( i = 0; i < tam; i++){
		if( vet[i] > maior)
			maior = vet[i];
	}

    if(maior > 10000000) maior = 1000000;

	aux = malloc( (maior+1) * sizeof(long long));
	for( i = 0; i < (maior+1); i++)
		aux[i] = 0;
	for( i = 0; i < tam; i++)
		aux[ vet[i]]++;
	k = 0;

	for( i = 0; i < (maior+1); i++){
		while((aux[i] > 0) && ( k < tam)){
			vet[k] = i;
			aux[i]--;
			k++;
		}
	}
	free(aux);
}

void bucket(long long v[],int tam, int op){
    long long **b = NULL, aux, *cont = NULL, vet[tam];
    int i, j, k, tam_baldes, qtd_baldes;
    float prop;
	long long maior = 0;

    for(i = 0; i < tam; i++){
		if( v[i] > maior)
			maior = v[i];
	}

    // Definindo a quantidade e tamanho dos baldes:
    tam_baldes = 30;
    if (op != 4){
        qtd_baldes = maior/10;
        b = (long long **)malloc(qtd_baldes * sizeof(long long *));
        cont = (long long *)malloc(qtd_baldes * sizeof(long long));
        for (i = 0; i < qtd_baldes; i++) {
            b[i] = (long long *)malloc(tam_baldes * sizeof(long long));
            cont[i] = 0;
        }
    }
    else{
        qtd_baldes = maior/1000000;
        b = (long long **)malloc(qtd_baldes * sizeof(long long *));
        cont = (long long *)malloc(qtd_baldes * sizeof(long long));
        for (i = 0; i < qtd_baldes; i++) {
            b[i] = (long long *)malloc(tam_baldes * sizeof(long long));
            cont[i] = 0;
        }
    }

    /* Ordenando os elementos por baldes */
    for (i = 0; i < tam; i++) {
        aux = v[i];
        // se for o elemento surpresa:
        if (aux > 10000000){
            j = qtd_baldes-1;
            b[j][0] = aux;
            //printf("O elemento %lld esta no balde numero %d na pos 0\n", aux, j);
        }
        else{
            prop = (qtd_baldes * 1.0 / tam) * aux;
            j = (int)prop;
            if (j == qtd_baldes) j = qtd_baldes-2;
            if (i < 20) {
                //printf("Prop: %.3f , item: %lld\n", prop, aux);
                //printf("O elemento %lld esta no balde numero %d na pos %d\n", aux, j, cont[j]);
            }
            b[j][cont[j]] = aux;
            cont[j]++;

        }
    }

    k = 0;
    for (i = 0; i < qtd_baldes; i++) {
        if (cont[i] > 1){
            bubble2(b[i], cont[i]);
            for (j = 0; j < cont[i]; j++) {
                vet[k] = b[i];
                k++;
            }
        }
        else{
            if(cont[i] != 0){
                vet[k] = b[i];
                k++;
            }
        }
    }

    for (i = 0; i < tam; i++) {
        v[i] = vet[i];
    }


    free(cont);
    for (i = 0; i < qtd_baldes; i++) {
        free(b[i]);
    }
    free(b);

}

void bubble2(long long *v,int tam){
    int i,j, flag;
    long long temp;
    if(tam){
        for(j=0;j<tam-1;j++){
            flag=0;
            for(i=0;i<tam-1;i++){
                if(v[i+1]<v[i]){
                    temp=v[i];
                    v[i]=v[i+1];
                    v[i+1]=temp;
                    flag=1;
                }
            }
            if(!flag)
            break;
        }
    }
}
