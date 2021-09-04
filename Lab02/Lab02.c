/*
Aluno: Lucas Otavio Nascimento de Araujo - RA240106
Disciplina: MC458 - Projeto e Análise de Algoritmos I
Professor: Eduardo Candido Xavier
Problema: Ordenar um vetor A[0...n-1] com valores no intervalo [0, n^2 - 1] em tempo O(n)
Solucao: Radix Sort implementado com Counting Sort em k=n
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void RadixSortn(int*, int);
void CountingSortn(int*, int*, int, int);
int getDigitn(int, int, int);

int main() {
    //Declaracao das variaveis | O(1)
    int n;
    int *A;

    //Leitura de n e definicao dos vetores | O(1)
    scanf("%d", &n);
    A = malloc(n * sizeof(int));

    //Leitura do Vetor de Entrada | O(n)
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    //Ordenacao | O(n)
    RadixSortn(A, n);
    
    //Saida | O(n)
    for(int i = 0; i < n-1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[n-1]);

    //O(1)
    free(A);

    return 0;
}

//Ordena o vetor A[0...n-1] e coloca o resultado em B
// o algoritmo ordena via Counting Sort os numeros pela casa na base n: da menos significativa para a mais
// como a entrada tem numeros no intervalo [0, n^2-1], 2 digitos na base n bastam para representacao
void RadixSortn(int *A, int n) {

    //O(1)
    int *B = malloc(n*sizeof(int));

    //Como couting sort eh in-place, o algoritmo eh executado intercalando o vetor de entrada com o de saida
    // para evitar copia do vetor | O(n)
    CountingSortn(A, B, n, 0); //log_n(n^2-1) < 2 => todos os valores tem menos que dois digitos na base n
    CountingSortn(B, A, n, 1);

    //O(1)
    free(B);
}

//Ordena o vetor A[0...n-1] com base no digito d de cada numero na base n e retorna o vetor ordenado em B[0...n-1] | O(n)
void CountingSortn(int *A, int *B, int n, int d) {
    
    //Inicializando vetor auxiliar | O(k) = O(n)
    int k = n;
    int C[k];
    for(int i = 0; i < k; i++) 
        C[i] = 0;
    
    //C[i] conta quantos numeros tem com digito d = i | O(n)
    for(int i = 0; i < n; i++)
        C[getDigitn(A[i], n, d)]++;
    
    C[0]--; //Ajuste, pois vetor comeca no 0 | O(1)
    
    //C[i] contem # de (elementos com digito d <= i) - 1 i.e. a posicao do ultimo numero com digito d=i | O(n)
    for(int i = 1; i < k; i++)
        C[i] += C[i-1];

    //B recebe A ordenado de n a 0, usando o vetor C como auxiliar para identificar a posicao dos elementos | O(n)
    for(int i = n-1; i >= 0; i--) {
        B[C[getDigitn(A[i], n, d)]] = A[i];
        C[getDigitn(A[i], n, d)]--;
    }

}

//Funcao que retorna o d-esimo digito do numero m na base b
// serve como interface para Counting Sort
// i.e. Counting Sort ve o numero m como seu digito d na base b | O(1)
int getDigitn(int m, int b, int d) { 
    return (m / (int) (pow(b, d))) % b;
}