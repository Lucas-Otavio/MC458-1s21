/*
Aluno: Lucas Otavio Nascimento de Araujo RA240106
Disciplina: MC458 - Projeto e Analise de algoritmos I
Docente: Eduardo Xavier
Problema: Dada uma lista de tarefas com certa duração, escalonar tarefas para minimizar o somatorio do tempo final de execucao de cada uma
Solucao: escolha gulosa de selecionar a tarefa de menor duracao para ser realizada primeiro
        1. Ordena com MergeSort (O(nlogn) estavel)
        2. Soma cada elemento com seu antecessor para obter o tempo em que a execucao se encerra
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Tarefa
typedef struct task
{
    int index;
    int cost;
} task;

void mergeSort(task*, int, int);
void merge(task*, int, int, int);

int main() {

    //Leitura dos dados
    int n;
    task *tasks;

    scanf("%d", &n);
    tasks = malloc(n * sizeof(task));

    for(int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].cost);
        tasks[i].index = i+1;
    }

    //Ordenacao da lista
    mergeSort(tasks, 0, n-1);

    //Calcula momento em que execucao se encerra
    for(int i = 1; i < n; i++) {
        tasks[i].cost += tasks[i-1].cost;
    }

    //Calcula custo total
    int sum = 0;
    for(int i = 0; i < n; i++) {
       sum += tasks[i].cost;
    }

    //Imprime saida
    printf("%d\n", sum);

    for(int i = 0; i < n-1; i++) {
        printf("%d ", tasks[i].index);
    }
    printf("%d\n", tasks[n-1].index);

    //Libera memoria
    free(tasks);
    return 0;
}

//Algoritmo mergeSort separa lista em 2, ordena cada uma, e junta elas ordenadamente em merge
void mergeSort(task* tasks, int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(tasks, l, m);
        mergeSort(tasks, m+1, r);
        merge(tasks, l, m, r);
    }
}

//Algoritmo junta as listas ordenadamente
void merge(task* tasks, int l, int m, int r) {

    //Vetor auxiliar
    task* aux = malloc((r - l + 1) * sizeof(task));
    int l_idx = l, r_idx = m+1, aux_idx = 0;

    //Copia o menor elemento entre as duas listas para aux a cada iteracao enquanto houver elemento em ambos r e l
    while(aux_idx < r - l + 1 && l_idx <= m && r_idx <= r) {
        if (tasks[l_idx].cost <= tasks[r_idx].cost) {
            aux[aux_idx] = tasks[l_idx];
            aux_idx++; l_idx++;
        } else {
            aux[aux_idx] = tasks[r_idx];
            aux_idx++; r_idx++;
        }
    }

    //Se sobrou em l, copia o resto
    while(l_idx <= m)
        aux[aux_idx++] = tasks[l_idx++];
    
    //Se sobrou em r, copia o resto
    while(r_idx <= r)
        aux[aux_idx++] = tasks[r_idx++];
    
    //Transfere do aux para a lista canonica
    for(int i = 0; i < r - l + 1; i++)
        tasks[l+i] = aux[i];
}
