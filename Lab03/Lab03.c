///////////////////////////////////////////////////////////////////////////////////////////
// Aluno: Lucas Otavio Nascimento de Araujo RA240106
// Disciplina: MC458 - Projeto e Analise de Algoritmos I
// Objetivo: Encontrar maior custo (e seu caminho) de se deslocar verticalmente
//           para cima ou diagonal, da base ao topo, em um tabuleiro de damas
// Solucao: Programacao Dinamica, encontrar maior custo para cada posicao abaixo
//          e usar elas para calcular o maior custo da posicao atual.
//          Entao, percorrer linha superior para identificar posicao superior de
//          menor custo e definir recursivamente o caminho percorrido. Custo: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX2(a, b) ((a) > (b))? (a):(b)
#define MAX3(a, b, c) MAX2((a), MAX2((b), (c)))

void printPath(int**, int**, int**, int**, int, int, int);

int main() {

    // Definicao e Reserva da memoria necessaria
    int i, j, n, **supesq, **supdir, **sup, **custo;

    scanf("%d", &n);
    sup = malloc((n-1) * sizeof(int*));
    supesq = malloc((n-1) * sizeof(int*));
    supdir = malloc((n-1) * sizeof(int*));
    custo = malloc(n * sizeof(int*));

    for(i=0; i < n-1; i++) {
        sup[i] = malloc(n * sizeof(int));
        supesq[i] = malloc((n-1) * sizeof(int));
        supdir[i] = malloc((n-1) * sizeof(int));
    }
    
    for(i=0; i < n; i++)
        custo[i] = malloc(n * sizeof(int));
    
    // Tratamento da Entrada
    int leituras = 3*n*n - 5*n + 2;
    int rx, cx, ry, cy, p;

    for(i=0; i < leituras; i++) {
        scanf("%d %d %d %d %d", &rx, &cx, &ry, &cy, &p);
        if (cx > cy) //supesq
            supesq[rx][cx-1] = p;
        else if (cx == cy) //sup
            sup[rx][cx] = p;
        else //supdir
            supdir[rx][cx] = p;
    }

    // Inicializacao do vetor de custo ("caso base")
    for(i=0; i < n; i++)
        custo[0][i] = 0;
    
    int s, sd, se;

    // Percorre o tabuleiro - para cada iteracao define a resposta de uma subestrutura otima | O(n^2)
    for(i=1; i < n; i++) {
        for(j=0; j < n; j++) { // O(n)
            // Redefinicao dos valores para ignorar historico da variavel em caso de borda
            se = INT_MIN;
            sd = INT_MIN;

            //supdir
            if (j > 0)
                sd = custo[i-1][j-1] + supdir[i-1][j-1];
            
            //sup
            s = custo[i-1][j] + sup[i-1][j];

            //supesq
            if (j < n-1)
                se = custo[i-1][j+1] + supesq[i-1][j];
            
            // Custo otimo pode ser consequencia de uma subida para dir, reta, ou para esq
            custo[i][j] = MAX3(sd, s, se);
        }
    }

    // Determinacao da posicao final otima | O(n)
    int posMax = 0;
    for(i=1; i < n; i++) {
        if (custo[n-1][i] > custo[n-1][posMax])
            posMax = i;
    }

    // Imprime custo otimo
    printf("%d\n", custo[n-1][posMax]);

    // Determinacao do Caminho Otimo | O(n)
    printPath(custo, supesq, sup, supdir, n, n-1, posMax);

    // Liberacao de Memoria
    for(i=0; i < n-1; i++) {
        free(sup[i]);
        free(supesq[i]);
        free(supdir[i]);
        free(custo[i]);
    }
    free(custo[n-1]);
    free(sup);
    free(supesq);
    free(supdir);
    free(custo);

    return 0;
}

// Executado de i=n-1 ate i=0 | O(n)
void printPath(int** custo, int** supesq, int** sup, int** supdir, int n, int i, int j) {
    // Caso "base": recursao chega ao fim e valor do inicio do caminho eh acessado
    if (i == 0);

    // Caso nao-borda: o valor pode ter sido obtido por supdir, sup ou supesq
    else if (j > 0 && j < n-1) {
        if (custo[i][j] == custo[i-1][j-1] + supdir[i-1][j-1]) //supdir 
            printPath(custo, supesq, sup, supdir, n, i-1, j-1);
        else if (custo[i][j] == custo[i-1][j] + sup[i-1][j]) //sup
            printPath(custo, supesq, sup, supdir, n, i-1, j); 
        else //supesq
            printPath(custo, supesq, sup, supdir, n, i-1, j+1);
    }

    // Caso margem esquerda: o valor anterior nao pode estar a esquerda
    else if (j == 0) {
        if (custo[i][j] == custo[i-1][j] + sup[i-1][j]) //sup
            printPath(custo, supesq, sup, supdir, n, i-1, j); 
        else //supesq
            printPath(custo, supesq, sup, supdir, n, i-1, j+1);
    }

    // Caso margem direita: o valor anterior nao pode estar a direita
    else {
        if (custo[i][j] == custo[i-1][j-1] + supdir[i-1][j-1])  //supdir
            printPath(custo, supesq, sup, supdir, n, i-1, j-1);
        else //sup
            printPath(custo, supesq, sup, supdir, n, i-1, j); 
    }

    // Impressao do valor na "volta" da recursao para que a ordem esteja correta
    printf("%d", j);
    
    // Nao imprime espaco p ultimo valor, pula linha ao inves
    if (i < n-1)
        printf(" ");
    else
        printf("\n");
}