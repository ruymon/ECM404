#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado - Faça um programa que leia duas notas de um aluno em uma
 * única linha, separando cada valor com uma vírgula. Verifique se as notas
 * são válidas e, caso sejam, exiba a média do aluno na tela.
 *
 * Para que a nota seja válida, ela deve estar entre 0.0 e 10.0.
 * Caso alguma das notas não seja válida, o programa deve informar o usuário
 * e encerrar sua operação.
 *
 * Exemplos:
 *
 * Notas: 5.0, 10.0
 * 7.5
 *
 * Notas: 5, 5.0
 * 5.0
 *
 * Notas: -1.0, 5.0
 * Nota invalida. Deve ser entre 0.0 e 10.0
 */

bool isGradeValid(float grade)
{
    return grade >= 0 && grade <= 10;
}

float calculateAverageBetweenTwoNumbers(float firstNumber, float secondNumber)
{
    return (firstNumber + secondNumber) / 2;
}

void main()
{
    float firstGrade, secondGrade;

    printf("Notas: ");
    scanf("%f, %f", &firstGrade, &secondGrade);

    if (isGradeValid(firstGrade) && isGradeValid(secondGrade))
    {
        printf("%.1f", calculateAverageBetweenTwoNumbers(firstGrade, secondGrade));
        return;
    }
    else
    {
        printf("Nota invalida. Deve ser entre 0.0 e 10.0 \n");
        return;
    }

    return;
}
