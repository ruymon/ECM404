/**
 * Enunciado | Exercício 2
 *
 * @details
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um
 * array. A leitura deve ser feita de acordo com o programa feito no exercício 1.
 * Após a leitura, desenvolva a função calcula_media e calcula_dvp
 * para calcular a média e o desvio padrão dos valores informados.
 * O programa principal deve receber os valores lidos pelo array e retornar a
 * média e o desvio padrão no seguinte formato: MÉDIA +- DVP
 *
 * @example
 * Digite os valores para o array: 1 2 3 4 5 6 7 -100
 * 4.00 +- 2.0
 *
 * @example
 * Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 * 1.00 +- 0.0
 *
 * @example
 * Digite os valores para o array: 10 20 1 40 50 90 100 -100
 * 44.43 +- 35.6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_MAX 100

float calculateAverage(int array[], int arraySize);
float calculateStandardDeviation(int array[], int arraySize);

float calculateAverage(int array[], int arraySize)
{
    float sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    return sum / arraySize;
}

float calculateStandardDeviation(int array[], int arraySize)
{
    float average = calculateAverage(array, arraySize);
    float sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += pow(array[i] - average, 2);
    }
    return sqrt(sum / arraySize);
}

void main()
{
    int array[ARRAY_MAX];
    int arrayFilledPositionsSize = 0;

    printf("Digite os valores para o array: ");

    while (1)
    {
        scanf("%d", &array[arrayFilledPositionsSize]);

        if (array[arrayFilledPositionsSize] == -100)
        {
            break;
        }

        arrayFilledPositionsSize++;
    }

    printf("%.2f +- %.1f", calculateAverage(array, arrayFilledPositionsSize), calculateStandardDeviation(array, arrayFilledPositionsSize));
}
