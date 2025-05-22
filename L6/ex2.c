#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enunciado:
 *
 * Crie uma estrutura representando uma hora (hora, minuto, segundo). Escreva um
 * programa que leia um vetor de 5 posições dessa estrutura e imprima a maior hora.
 * Ajuste valores excedentes (segundos para minutos, minutos para horas).
 * Utilize funções para:
 * - leitura de cada estrutura (com ajuste);
 * - leitura do vetor;
 * - encontrar maior hora;
 * - comparar duas horas;
 * - exibir hora no formato hh:mm:ss.
 */

typedef struct
{
  int hour;
  int minute;
  int second;
} Time;

Time readTime()
{
  Time t;

  printf("Digite a hora (hh:mm:ss): ");
  scanf("%i:%i:%i", &t.hour, &t.minute, &t.second);

  if (t.second >= 60)
  {
    t.minute += t.second / 60;
    t.second %= 60;
  }
  if (t.minute >= 60)
  {
    t.hour += t.minute / 60;
    t.minute %= 60;
  }

  return t;
}

void readTimeArray(Time *times, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Hora %i: ", i + 1);
    times[i] = readTime();
  }
}

void displayTime(Time t)
{
  printf("%02i:%02i:%02i", t.hour, t.minute, t.second);
}

int compareTimes(Time firstTime, Time secondTime)
{
  if (firstTime.hour != secondTime.hour)
    return firstTime.hour - secondTime.hour;
  if (firstTime.minute != secondTime.minute)
    return firstTime.minute - secondTime.minute;
  return firstTime.second - secondTime.second;
}

int main(int argc, char *argv[])
{
  Time times[5];
  Time maxTime;
  int maxIndex = 0;
  readTimeArray(times, 5);
  maxTime = times[0];

  for (int i = 1; i < 5; i++)
  {
    if (compareTimes(times[i], maxTime) > 0)
    {
      maxTime = times[i];
      maxIndex = i;
    }
  }

  printf("Maior hora: ");
  displayTime(maxTime);

  printf("\n");

  // display all times
  printf("Todas as horas:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("Hora %i: ", i + 1);
    displayTime(times[i]);
    printf("\n");
  }

  return 0;
}
