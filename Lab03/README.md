### Instituto de Computação - Unicamp
### MC458 - Projeto e Análise de Algoritmos I
# Laboratório 03 - Movendo-se em um Tabuleiro de Damas

## Descrição
Suponha que você receba um tabuleiro de damas de dimensões  n * n  e uma peça. Você deve mover a peça da borda inferior do tabuleiro para a borda superior do tabuleiro de acordo com a seguinte regra. Em cada etapa você podemover a peça para uma das três casas:

1. a casa imediatamente acima,
2. a casa na diagonal superior esquerda (mas apenas se a peça ainda não estiver na coluna mais a esquerda),
3. a casa na diagonal superior direita (mas apenas se a peça ainda não estiver na coluna mais a direita).

Cada vez que você se move da casa  `x`  para a casa  `y` , você recebe  `p(x, y)`  reais.
Projete e implemente um algoritmo  `O(n²)`  que descubra a sequência de movimentos que moverá a peça de algum
lugar ao longo da borda inferior para algum lugar ao longo da borda superior coletando o máximo de reais possível.
Seu algoritmo tem liberdade para escolher qualquer casa ao longo da borda inferior como ponto de partida e
qualquer casa ao longo da borda superior como destino, a fim de maximizar a quantidade de reais reunidos ao longo
do caminho.

## Entrada
A primeira linha contém um inteiro positivo  `n < 1000` , o tamanho do tabuleiro de damas. As linhas subsequentes
contém os valores em reais para todos os movimentos possíveis, no sequinte formato:

```rx cx ry cy p```

Onde  `rx`  e  `cx`  são números inteiros que representam a linha e coluna da casa de origem,  `ry`  e  `cy`  são números
inteiros que representam a linha e coluna da casa de destino e  `p`  é um número inteiro que representa a quantidade
de reais coletados ao mover a peça da casa  `(rx, cx)`  para a casa  `(ry, cy)`
Assuma que  `(0, 0)`  representa a casa da borda inferior esquerda,  `(n - 1, n - 1)`  representa a casa da borda
superior direita e  `- 1000 < p < 1000`

## Saída
Como saída o seu programa deverá imprimir duas linhas.

A primeira linha deve conter um número inteiro, representando a quantidade de reais coletada pela melhor sequência
de movimentos.

A segunda linha deve conter  n  números inteiros, representando as colunas da melhor sequência de movimentos.

Em caso de empate, dê preferência para as colunas mais a esquerda.

## Exemplos

### Teste 01

[Entrada](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab03/Test%20Cases/arq01.in)

```
3
0 0 1 0 -3 
0 0 1 1 1 
0 1 1 0 5 
0 1 1 1 -1 
0 1 1 2 4 
0 2 1 1 3 
0 2 1 2 -5 
1 0 2 0 -3 
1 0 2 1 -4 
1 1 2 0 -4 
1 1 2 1 2 
1 1 2 2 2 
1 2 2 1 -1 
1 2 2 2 -1 
```

[Saída](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab03/Test%20Cases/arq01.out)

```
5 
2 1 1
```

Neste exemplo, a peça começa na casa  `(0, 2)`  e é movida para a casa  `(1, 1)` , coletando-se  `3`  reais.

Então, a peça é movida da casa  `(1, 1)`  para a casa  `(2, 1)` , coletando-se mais  `2`  reais.

Note que a peça poderia ser movida da casa  `(1, 1)`  para a casa  `(2, 2)`  coletando-se a mesma quantidade de reais.

Porém, deu-se preferência para a coluna  `1`, que fica mais a esquerda.

Logo, no total, é coletado  `1 + 2 = 3`  reais.

### Teste 02
[Entrada](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab03/Test%20Cases/arq02.in)

```
5 
0 0 1 0 7 
0 0 1 1 8 
0 1 1 0 6 
0 1 1 1 6 
0 1 1 2 -2
0 2 1 1 2 
0 2 1 2 7 
0 2 1 3 -6
0 3 1 2 2 
0 3 1 3 3 
0 3 1 4 3 
0 4 1 3 -5
0 4 1 4 -3
1 0 2 0 6 
1 0 2 1 -8
1 1 2 0 8 
1 1 2 1 6 
1 1 2 2 8 
1 2 2 1 -1 
1 2 2 2 -1 
1 2 2 3 -5 
1 3 2 2 -4 
1 3 2 3 -5 
1 3 2 4 1 
1 4 2 3 0 
1 4 2 4 6 
2 0 3 0 0 
2 0 3 1 4 
2 1 3 0 4 
2 1 3 1 6 
2 1 3 2 3 
2 2 3 1 6 
2 2 3 2 -7
2 2 3 3 -8 
2 3 3 2 -6 
2 3 3 3 -2 
2 3 3 4 0 
2 4 3 3 -3
2 4 3 4 -8 
3 0 4 0 2 
3 0 4 1 -6 
3 1 4 0 -6 
3 1 4 1 7 
3 1 4 2 2 
3 2 4 1 7 
3 2 4 2 -8 
3 2 4 3 -1 
3 3 4 2 0 
3 3 4 3 5 
3 3 4 4 8 
3 4 4 3 5 
3 4 4 4 -8
```

[Saída](https://github.com/Lucas-Otavio/MC458-1s21/blob/main/Lab03/Test%20Cases/arq02.out)

```
29 
0 1 2 1 1 
```

Neste exemplo, a peça começa na casa  `(0, 0)`  e é movida para a casa  `(1, 1)` , coletando-se  `8`  reais.

Então, a peça é movida da casa  `(1, 1)`  para a casa  `(2, 2)` , coletando-se  `8`  reais.

Depois, a peça é movida da casa  `(2, 2)`  para a casa  `(3, 1)` , coletando-se  `6`  reais.

Por fim, a peça é movida da casa  `(3, 1)`  para a casa  `(4, 1)` , coletando-se  `7`  reais.

Logo, no total, é coletado  `8 + 8 + 6 + 7 = 29`  reais.

## Observações
O número máximo de submissões é 10;
O seu programa deve estar completamente contido em um único arquivo denominado `lab03.c`;
Para a realização dos testes do SuSy, a compilação dos programas desenvolvidos considerar o comando:`gcc -std=c99 -pedantic -Wall -o lab02 lab03.c`;
Idente corretamente o seu código e inclua comentários no decorrer do seu programa.
