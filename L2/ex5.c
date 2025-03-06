#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado - Faça um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada válida ou não.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos não
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

/**
 * Obeservação ao enunciado:
 *
 * Por convenção, a escrita do formato do exemplo acima (22/02/2022) deve ser
 * escrita da seguinte forma: dd/MM/YYYY
 *
 * @see https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Field_Symbol_Table
 */

bool isLeapYear(int year)
{
    /**
     * A validação de um ano bisexto é feita pela verificação
     * da existência de um resto na divisão do ano por 4.
     *
     * @see https://forum.choiceofgames.com/t/implementing-leap-years/151191
     */

    return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

bool isDateValid(int day, int month, int year)
{
    if (day <= 0 || month <= 0 || year <= 0)
        return false;

    if (month > 12)
        return false;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return day <= 31;
        break;
    case 2:
        return day <= (isLeapYear(year) ? 29 : 28);
        break;
    default:
        return day <= 30;
        break;
    }
}

void main()
{
    int day, month, year;

    printf("Data: ");
    scanf("%i/%i/%i", &day, &month, &year);

    printf("Data ");
    printf(isDateValid(day, month, year) ? "valida!" : "invalida!");

    return;
}
