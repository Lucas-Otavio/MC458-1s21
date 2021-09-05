### Instituto de Computação - Unicamp
### MC458 - Projeto e Análise de Algoritmos I
# Laboratório 02 - Ordenação em Tempo Linear

## Descrição
Seja x1, ..., xn uma sequência de números inteiros no intervalo [0, n2 - 1]. Projete um algoritmo O(n) para ordenar x1, ..., xn.

## Entrada
A entrada consiste em 2 linhas. A primeira linha contém um inteiro positivo n, o tamanho da sequência de números inteiros. A segunda linha contém n números inteiros no itervalo [0, n2 - 1], os elementos xi da sequência.

## Saída
Como saída o seu programa deverá imprimir uma única linha contendo os valores da sequência de entrada em ordem crescente.

## Exemplos
### Teste 01
[Entrada](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab02/Test%20Cases/arq01.in)

```
10
78 3 97 76 52 83 17 91 68 50
```

[Saída](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab02/Test%20Cases/arq01.out)

```
3 17 50 52 68 76 78 83 91 97
```


### Teste 02
[Entrada](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab02/Test%20Cases/arq02.in)

```
10
89 88 73 7 84 67 72 53 48 67
```

[Saída](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab02/Test%20Cases/arq02.out)

```
7 48 53 67 67 72 73 84 88 89
```


## Observações
O número máximo de submissões é 10;

O seu programa deve estar completamente contido em um único arquivo denominado `lab02.c`;

Para a realização dos testes do SuSy, a compilação dos programas desenvolvidos considerar o comando:`gcc -std=c99 -pedantic -Wall -o lab02 lab02.c`;

Idente corretamente o seu código e inclua comentários no decorrer do seu programa.
