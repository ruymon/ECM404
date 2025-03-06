#include <stdio.h>
#include <stdlib.h>

/**
 * Enunciado | Exercício 8
 *
 * @details
 * Faça um programa que calcula a associação em paralelo
 * de dois resistores R1 e R2 fornecidos pelo usuário via teclado e
 * retorna seu valor com duas casas decimais.
 *
 * O programa deverá solicitar valores e calcular a resistência
 * equivalente até que o usuário entre com um valor para alguma das
 * resistências igual a 0.
 *
 * @example
 * Digite um valor para R1: 470
 * Digite um valor para R2: 2200
 * Resistencia equivalente em paralelo: 387.27
 *
 * @example
 * Digite um valor para R1: 0
 * Digite um valor para R2: 100
 * Finalizando o programa!
 */

float calculateParallelResistance(float r1, float r2)
{
    return (r1 * r2) / (r1 + r2);
}

void main()
{
    // Start equivalentResistance with a value different than zero.
    float equivalentResistance = 1;

    do
    {
        float firstResistance, secondResistance;

        printf("Digite um valor para R1: ");
        scanf("%f", &firstResistance);

        printf("Digite um valor para R2: ");
        scanf("%f", &secondResistance);

        equivalentResistance = calculateParallelResistance(firstResistance, secondResistance);

        if (equivalentResistance != 0)
        {
            printf("Resistencia equivalente em paralelo: %.2f \n", equivalentResistance);
        }
        else
        {
            printf("Finalizando o programa! \n");
        }

    } while (equivalentResistance != 0);

    return;
}
