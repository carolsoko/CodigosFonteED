//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Algortimo de busca sequencial (busca linear)
int buscaLinear(int x, int v[], int n){
    for (int i = 0; i < n; i++){
        if (v[i] == x){
            return 1;
        }
    }
    return -1;
}

// Algortimo de busca binária
int buscaBinaria(int x, int v[], int n){
    int esquerda = 0;
    int direita = n - 1;
    while (esquerda <= direita){
        int meio = (esquerda + direita) / 2;
        if (v[meio] == x){
            return meio;
        }else if (v[meio] < x){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }
    return -1;
}

// Algoritmo de ordenação por bolha (bubble sort)
void bubbleSort(int v[], int n){
    int i, j;
    int cont = 0;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            cont++;
            if (v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    printf("\nQuantidade de vezes que o algoritmo de ordenacao foi executado: %d\n", cont);
}

// Algoritmo de ordenação por inserção (insertion sort)
void insertionSort(int v[], int n){
    int i, j, key;
    int cont = 0;
    for (i = 1; i < n; i++){
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key){
            cont++;
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    printf("\nQuantidade de vezes que o algoritmo de ordenacao foi executado: %d\n", cont);
}

// Algoritmo de ordenação por seleção (selection sort)
void selectionSort(int v[], int n){
    int i, j, min_idx;
    int cont = 0;
    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for (j = i + 1; j < n; j++){
            cont++;
            if (v[j] < v[min_idx]){
                min_idx = j;
            }           
        }
        int temp = v[min_idx];
        v[min_idx] = v[i];
        v[i] = temp;
    }
    printf("\nQuantidade de vezes que o algoritmo de ordenacao foi executado: %d\n", cont);
}

// Algoritmo de ordenação merge sort
void merge(int v[], int l, int m, int r, int* cont) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*cont)++;
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int l, int r, int* cont) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m, cont);
        mergeSort(v, m + 1, r, cont);
        merge(v, l, m, r, cont);
    }
}

void mergeSortWrapper(int v[], int n) {
    int cont = 0;
    mergeSort(v, 0, n - 1, &cont);
    printf("\nQuantidade de vezes que o algoritmo de ordenacao foi executado: %d\n", cont);
}

// Algoritmo de ordenação quick sort // OBS: NÃO FAZ CONTAGEM DE COMPARAÇÕES FEITAS
void quickSort(int v[], int n) {
    if (n <= 1) {
        return;
    }

    int pivo = v[n/2];
    int a = 0;
    int b = n-1;

    while (a <= b) {
        if (v[a] < pivo) {
            a++;
            continue;
        }
        if (v[b] > pivo) {
            b--;
            continue;
        }

        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;

        a++;
        b--;
    }

    quickSort(v, b+1);
    quickSort(&v[b+1], n-b-1);
}

// Algoritmo de ordenação heap sort
void heapify(int v[], int n, int i, int* cont) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // if (esquerda < n && v[esquerda] > v[maior]) {
    //     maior = esquerda;
    // }

    // if (direita < n && v[direita] > v[maior]) {
    //     maior = direita;
    // }

    if (esquerda < n) {
        (*cont)++;
        if (v[esquerda] > v[maior]) {
            maior = esquerda;
        }
    }

    if (direita < n) {
        (*cont)++;
        if (v[direita] > v[maior]) {
            maior = direita;
        }
    }

    if (maior != i) {
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;

        heapify(v, n, maior, cont);
    }
}

void heapSort(int v[], int n) {
    int cont = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i, &cont);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0, &cont);
    }

    printf("\nQuantidade de vezes que o algoritmo de ordenacao foi executado: %d\n", cont);
}

// Algoritmo para preencher o vetor com numeros sequenciais
void preencherVetorSequencial(int v[], int n){
    for (int i = 0; i < n; i++){
        v[i] = i + 1;
    }
}

// Algoritmo para preencher o vetor com numeros aleatorios
void preencherVetorNumAleatorio(int v[], int n){

    // Inicializa a semente de geracao de numeros aleatorios
    srand(time(NULL));

    int valorMinimo = 0;
    int valorMaximo = 0;
    int intervalo = 0;
   
    printf("\nDeseja inserir numeros numa faixa de valores especifica? [1 - Sim | 2 - Nao]: ");
    int opcao;

    do{
        scanf("%d", &opcao);
        if (opcao != 1 && opcao != 2){
            printf("Opcao invalida! Digite novamente: ");
        }else if(opcao == 1){
            printf("Digite o valor minimo: ");
            scanf("%d", &valorMinimo);
            printf("Digite o valor maximo: ");
            scanf("%d", &valorMaximo);
            intervalo = valorMaximo - valorMinimo + 1;
            // Preenche o vetor com numeros aleatorios dentro do intervalo especificado
            for (int i = 0; i < n; i++){
                v[i] = rand() % intervalo + valorMinimo;
            }
        }else{
            // Preenche o vetor com numeros aleatorios
            for (int i = 0; i < n; i++){
                v[i] = rand() % 100;
            }
        }
    }while(opcao != 1 && opcao != 2);
}

// Algoritmo para mostrar o vetor
void printVetor(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}

void printResultado(int x, int localizado){
    if (localizado != -1){
        printf("%d esta presente no vetor.\n", x);
    }else{
        printf("%d nao esta presente no vetor.\n", x);
    }
}

int capturarMaiorValor(int v[], int n){
    int maior = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

int capturarMenorValor(int v[], int n){
    int menor = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] < menor){
            menor = v[i];
        }
    }
    return menor;
}

void quebraLinha(){
    printf("\n");
}

void printExplicacaoAlgoritmo(int opcao) {
    switch(opcao) {
        case 1:
            printf("Bubble Sort: e um algoritmo simples, mas ineficiente, que percorre repetidamente a lista e compara pares adjacentes de elementos e os troca se estiverem na ordem errada. O Bubble Sort tem uma complexidade de tempo de O(n^2).\n");
            break;
        case 2:
            printf("Selection Sort: e um algoritmo simples que percorre a lista e seleciona o menor elemento em cada iteracao e o coloca na posicao correta na lista. O Selection Sort tem uma complexidade de tempo de O(n^2), mas pode ser mais eficiente do que o Bubble Sort em listas grandes.\n");
            break;
        case 3:
            printf("Insertion Sort: e um algoritmo simples que percorre a lista de itens a serem ordenados, inserindo cada elemento na posicao correta em relacao aos elementos anteriores. O Insertion Sort tem uma complexidade de tempo de O(n^2), mas pode ser mais eficiente do que o Bubble Sort em listas pequenas.\n");
            break;
        case 4:
            printf("Merge Sort: e um algoritmo de ordenacao mais sofisticado que usa uma abordagem de 'dividir e conquistar'. Divide a lista em duas metades, ordena cada metade recursivamente e depois une as duas metades ordenadas. O Merge Sort tem uma complexidade de tempo de O(n log n).\n");
            break;
        case 5:
            printf("Quick Sort: e um algoritmo de ordenacao rapido que usa uma abordagem de 'dividir e conquistar' semelhante ao Merge Sort. Divide a lista em duas particoes, escolhendo um pivo e colocando todos os elementos menores que o pivo na primeira particao e os maiores na segunda. Em seguida, o algoritmo ordena recursivamente as duas particoes. O Quick Sort tem uma complexidade de tempo medio de O(n log n), mas pode ser O(n^2) no pior caso.\n");
            break;
        case 6:
            printf("Heap Sort: e um algoritmo que utiliza uma estrutura de dados chamada Heap para ordenar os elementos. Ele primeiro coloca os elementos em uma Heap, em seguida, extrai o menor elemento da Heap ate que todos os elementos sejam ordenados. O Heap Sort tem uma complexidade de tempo de O(n log n) em todos os casos.\n");
            break;
        case 7:
            printf("O algoritmo de busca linear e um metodo simples para encontrar um elemento em um conjunto de dados. Ele percorre os elementos um por um ate encontrar o elemento desejado ou percorrer todos os elementos do conjunto. O tempo de execucao desse algoritmo e proporcional ao tamanho do conjunto de dados e e chamado de tempo de busca linear ou tempo linear. A complexidade de tempo da Busca Linear e O(n).\n");
            break;
        case 8:
            printf("O algoritmo de busca binaria e um metodo eficiente para encontrar um elemento em um conjunto de dados ordenado. Ele divide repetidamente o conjunto de dados ao meio, descartando metade do conjunto em cada etapa, ate encontrar o elemento desejado ou concluir que o elemento nao esta no conjunto de dados. O tempo de execucao desse algoritmo e proporcional ao logaritmo do tamanho do conjunto de dados e e chamado de tempo de busca binaria ou tempo logaritmico.. A complexidade de tempo da Busca Binaria e O(log n).\n");
            break;
        case 9:
            printf("A diferenca entre os algoritmos de busca linear e binaria e a eficiencia, onde a busca binaria e mais rapida para grandes conjuntos de dados ordenados.");
            break;
        case 10:
            printf("O tempo logaritmico refere-se a relacao entre o tamanho do conjunto de dados e o tempo de execucao do algoritmo, onde o tempo cresce em proporcao ao logaritmo do tamanho do conjunto de dados, em vez de crescer em proporcao linear.");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

int main(){

    // Configuracao para acentuacao no Windows, Linux e Mac
    #ifdef _WIN32
        setlocale(LC_ALL, "Portuguese");
    #elif __APPLE__ || __linux__
        setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif

    // Configuracao para mostrar o tempo de execucao do programa
    clock_t inicio_BuscaLinear, fim_BuscaLinear, inicio_BuscaBinaria, fim_BuscaBinaria;
    double tempo_gastoBuscaLinear, tempo_gastoBuscaBinaria;

    // Variaveis usadas ao longo do programa 
    int n, localizado, opcao, opPreenchimento;
    // n = tamanho do vetor
    // x = numero a ser buscado no vetor
    // localizado = variavel que indica se o numero foi encontrado ou nao, sendo -1 para nao encontrado diferente de -1 para encontrado
    // opcao = variavel que indica a opcao escolhida pelo usuario no menu

    do{
        // Limpar tela
        system("cls");

        printf("Bem vindo ao programa de ordenacao e busca de vetores!\n");
        printf("Este programa foi desenvolvido para estudo de algoritmos de ordenacao e busca.\n");
        quebraLinha();
        printf("Este programa possui:\n");
        printf("2 opcoes de busca: Busca Linear e Busca Binaria.\n");
        printf("6 opcoes de ordenacao: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort e Heap Sort.\n");
        printf("3 opcoes de preenchimento do vetor: Numeros sequenciais, Numeros aleatorios e Numeros digitados pelo usuario (Manualmente).\n");
        quebraLinha();
        printf("Alem disso, este programa mede o tempo de execucao de cada algoritmo de busca (Busca Linear e Busca Binaria).\n");
        quebraLinha();

        printf("Para comecar, digite o tamanho do vetor: ");
        scanf("%d", &n);

        // Cria o vetor com o tamanho n
        int v[n]; 

        // Menu de opcoes de preenchimento do vetor
        printf("\nComo deseja preencher o vetor?\n");
        quebraLinha();
        printf("1 - Numeros sequenciais.\n");
        printf("2 - Numeros aleatorios.\n");
        printf("3 - Numeros digitados pelo usuario (Manualmente).\n");
        quebraLinha();
        printf("Digite a opcao desejada: ");
        scanf("%d", &opPreenchimento);

        switch(opPreenchimento){
            case 1:
                preencherVetorSequencial(v, n);
                break;
            case 2:
                preencherVetorNumAleatorio(v, n);
                break;
            case 3:
                for (int i = 0; i < n; i++){
                    printf("\nDigite um valor para a posicao %da: ", i + 1);
                    scanf("%d", &v[i]);
                }
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        // Mostrar vetor original
        printf("\nDeseja mostrar o vetor original? Caso seu vetor seja muito grande, talvez seja melhor nao mostrar. [1 - Sim | 2 - Nao]: ");
        scanf("%d", &opcao);

        if (opcao == 1){
            printf("\nValores do vetor original [Tamanho: %d]: \n\n", n);
            printVetor(v, n);
            quebraLinha();
        }

        if(opPreenchimento != 1){
            printf("\nPara continuar, o vetor deve ser ordenado!");
            printf("\nEscolha um algoritmo de ordenacao para ordenar o vetor:\n");
            quebraLinha();
            printf("1 - Bubble Sort.\n");
            printf("2 - Selection Sort.\n");
            printf("3 - Insertion Sort.\n");
            printf("4 - Merge Sort.\n");
            printf("5 - Quick Sort.\n");
            printf("6 - Heap Sort.\n");
            quebraLinha();
            printf("Opcao: ");
            scanf("%d", &opcao);
            
            switch(opcao){
                case 1:
                    bubbleSort(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                case 2:
                    selectionSort(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                case 3:
                    insertionSort(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                case 4:
                    mergeSortWrapper(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                case 5:
                    quickSort(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                case 6:
                    heapSort(v, n);
                    printf("\nVetor ordenado com sucesso!\n");
                    break;
                default:
                    printf("\nOpcao invalida!\n");
                    break;
            }
        }else{
            printf("O vetor ja esta ordenado!\n");
        }

        // Mostrar vetor ordenado
        if(opPreenchimento != 1){
            printf("\nDeseja mostrar o vetor ordenado? Caso seu vetor seja muito grande, talvez seja melhor nao mostrar. [1 - Sim | 2 - Nao]: ");
            scanf("%d", &opcao);

            if (opcao == 1){
                printf("\nValores do vetor ordenado [Tamanho: %d]: \n", n);
                printVetor(v, n);
                quebraLinha();
            }
        }

        // Captura o maior numero presente no vetor
        int maior = capturarMaiorValor(v, n);
        // Captura o menor numero presente no vetor
        int menor = capturarMenorValor(v, n);

        printf("\nDigite um numero entre %d e %d para ser buscado no vetor: ", menor, maior);
        int x;
        scanf("%d", &x);

        // Trecho de codigo cujo tempo de execucao deve ser medido quando usado com a busca linear
        inicio_BuscaLinear = clock();

        for (int i = 0; i < 1000000; i++){
            localizado = buscaLinear(x, v, n);
        }

        fim_BuscaLinear = clock();
        tempo_gastoBuscaLinear = ((double)(fim_BuscaLinear - inicio_BuscaLinear)) / CLOCKS_PER_SEC;

        printResultado(x, localizado);
        printf("Tempo gasto: %f segundos com a busca linear.\n", tempo_gastoBuscaLinear);

        // Trecho de codigo cujo tempo de execucao deve ser medido quando usado com a busca binaria

        inicio_BuscaBinaria = clock();

        for (int i = 0; i < 1000000; i++){
            localizado = buscaBinaria(x, v, n);
        }

        fim_BuscaBinaria = clock();
        tempo_gastoBuscaBinaria = ((double)(fim_BuscaBinaria - inicio_BuscaBinaria)) / CLOCKS_PER_SEC;

        printResultado(x, localizado);

        printf("Tempo gasto: %f segundos com a busca binaria.\n", tempo_gastoBuscaBinaria);

        printf("\nDeseja saber sobre algum conteudo relacionado a este programa? [1 - Sim | 2 - Nao]: ");
        scanf("%d", &opcao);

        while(opcao == 1){
            printf("Sobre o que gostaria de saber?\n");
            quebraLinha();
            printf("1 - Bubble Sort.\n");
            printf("2 - Selection Sort.\n");
            printf("3 - Insertion Sort.\n");
            printf("4 - Merge Sort.\n");
            printf("5 - Quick Sort.\n");
            printf("6 - Heap Sort.\n");
            printf("7 - Busca Linear.\n");
            printf("8 - Busca Binaria.\n");
            printf("9 - Diferenca entre Busca Linear e Busca Binaria.\n");
            printf("10 - Tempo logaritmico.\n");
            quebraLinha();
            printf("Opcao: ");
            scanf("%d", &opcao);
            printExplicacaoAlgoritmo(opcao);
            printf("\nDeseja saber sobre outro conteudo relacionado a este programa? [1 - Sim | 2 - Nao]: ");
            scanf("%d", &opcao);
        }
        
        printf("Deseja repetir o programa? [1 - Sim | 0 - Nao]: ");
        scanf("%d", &opcao);
    }while(opcao != 0);

    if(opcao == 0){
        printf("\nObrigado por usar o programa!");
        printf("\nEste programa foi desenvolvido por: Diogo Mascarenhas.\n");
    }
    
    return 0;
}