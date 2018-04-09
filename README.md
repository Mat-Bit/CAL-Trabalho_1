# CAL-Trabalho_1
Trabalho em C para analisar a eficiência de diferentes algoritmos de ordenação com diversos tipos e tamanhos de arquivo de entrada

1- Primeiramente será necessário criar um arquivo de entrada para realizar o teste, o mesmo pode ser gerado através do código ger_entradas.c da seguinte forma:
    gcc -o exec_ger_arq ger_entrada.c

  Após ter sido criado o executável para gerar o arquivo de entrada (exec_ger_arq), execute o mesmo passando 2 argumentos em seguida, que são:
  - Quantidade de itens que deseja que o arquivo de entrada possua, podendo ser de: 25000, 50000, 75000, 100000 e 1000000;
  - O modo que esses itens estarão no arquivo: 1 (Ordenado Crescente), 2 (Ordenado Decrescente), 3 (Aleatório) e 4 (Aleatório com uma das linhas tendo um iten de valor 100000000000);
  
  Exemplo:
    ./exec_ger_arq 75000 3
    // Irá gerar um arquivo de nome "entrada.txt" com 75000 valores aleatórios entre 0 e 75000
    

2- Tendo já o arquivo de entrada para teste, agora é hora de testá-lo, para isso basta compilar o arquivo main.c juntamente com o ordenadores.c:
    gcc -o Teste ordenadores.c main.c
    
  Após a compilação, execute o arquivo Teste com os mesmos argumentos que foram utilizados pra gerar o arquivo de entrada:
  
  Exemplo:
    ./Teste 75000 3
    
  O código analisará a eficiência de 8 (oito) tipos de algoritmos de ordenação para o arquivo de entrada recebido, esses algoritmos são:
  1- BubbleSort;
  2- InsertionSort;
  3- MergeSort;
  4- QuickSort (sendo o pivô sempre o primeiro elemento);
  5- QuickSort (pivô escolhido aleatoriamente);
  6- HeapSort;
  7- CountingSort;
  8- BucketSort;
  
  Feito a análise, o código criará um arquivo tipo txt de saída com o tempo em segundos pra cada teste de entrada, e o nome do arquivo será o tamanho da quantidade de itens mais o modo de disposição desses itens.
  
  Exemplo:
    75000 - 3.txt
    // Relatório de saída com a análise dos algoritmos de ordenação pro arquivo de 75000 registro modo aleatório (opção 3).
