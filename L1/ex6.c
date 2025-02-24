#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia os valores de duas resistencias eletricas (int)
 * e, em seguida, exiba o resultado da sua resistencia equivalente em serie
 * e em paralelo. O formato da saida deve ser:
 *
 * S: **Req_Serie** P: **Req_Paralelo**
 *
 *
 * Ex:
 *      R1: 3
 *      R2: 3
 *      S: 6 P: 1.50
 *
 *      R1: 5
 *      R2: 12
 *      S: 17 P: 3.53
 *
 * OBS: Utilize duas casas decimais para representar valores flutuantes.
 */

int main(int argc, char *argv[])
{
  int r1, r2;

  printf("R1:");
  scanf("%i", &r1);

  printf("R2:");
  scanf("%i", &r2);

  int s = r1 + r2;

  float r1_f = r1 * 1.0;
  float r2_f = r2 * 1.0;
  float p = (r1_f * r2_f) / (r1_f + r2_f);

  printf("S: %i P: %.2f\n", s, p);

  return 0;
}
