/**
 * Enunciado | Exercício 3
 *
 * @details
 * Desenvolva um programa capaz de ler dois vetores com três elementos
 * inteiros cada. A leitura deve ser feita em uma única linha para cada
 * vetor, com os elementos separados por espaços. Após a leitura, o
 * programa deve exibir o produto escalar entre os vetores digitados no
 * formato exemplificado abaixo.
 *
 * O cálculo do produto escalar deve obrigatoriamente ser feito pela função
 * produto_escalar, que recebe como referência os dois arrays e retorna um
 * valor inteiro referente ao resultado do produto escalar.
 *
 * @example
 * Digite o primeiro array: 1 2 3
 * Digite o segundo array: 3 2 1
 * [1, 2, 3] . [3, 2, 1] = 10
 *
 * @example
 * Digite o primeiro array: 10 20 30
 * Digite o segundo array: -10 2 5
 * [10, 20, 30] . [-10, 2, 5] = 90
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 3

int vectorScalarProduct(int firstArray[], int secondArray[]);

int vectorScalarProduct(int firstArray[], int secondArray[])
{
    int scalarProduct = 0;

    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        scalarProduct += firstArray[i] * secondArray[i];
    }

    return scalarProduct;
}

// TODO: Revisar para fazer o main de forma mais elegante.
void main()
{
    int firstArray[ARRAY_MAX_SIZE], secondArray[ARRAY_MAX_SIZE];

    printf("Digite o primeiro vetor: \n");
    scanf("%i %i %i", &firstArray[0], &firstArray[1], &firstArray[2]);

    printf("Digite o segundo vetor: \n");
    scanf("%i %i %i", &secondArray[0], &secondArray[1], &secondArray[2]);

    printf("[%i %i %i] . ", firstArray[0], firstArray[1], firstArray[2]);
    printf("[%i %i %i] = ", secondArray[0], secondArray[1], secondArray[2]);
    printf("%i", vectorScalarProduct(firstArray, secondArray));
}