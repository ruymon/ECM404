/*
 * Enunciado:
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um
 * array. A leitura deve ser feita de acordo com o programa feito no ex1.
 * Ap�s a leitura, desenvolva a fun��o calcula_media e calcula_dvp
 * para calcular a m�dia e o desvio padr�o dos valores informados.
 * O programa principal deve receber os valores lidos pelo array e retornar a
 * m�dia e o desvio padr�o no seguinte formato: M�DIA +- DVP
 *
 * Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 -100
 *    4.00 +- 2.0
 *
 *    Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 *    1.00 +- 0.0
 *
 *    Digite os valores para o array: 10 20 1 40 50 90 100 -100
 *    44.43 +- 35.6
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // A biblioteca math tem pow e sqrt

#define ARRAY_MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */
float calcula_media(int array[], int tam_array);
float calcula_dvp(int array[], int tam_array);

int main()
{
    printf("Hello world!\n");
    return 0;
}

/* Implementa��o das Fun��es */
float calcula_media(int array[], int tam_array) {

}

float calcula_dvp(int array[], int tam_array) {

}
