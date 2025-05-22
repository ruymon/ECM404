#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Enunciado:
 *
 * Crie uma estrutura para representar as coordenadas de um ponto (X, Y).
 * Leia dois pontos do teclado e exiba a distância entre eles.
 */

typedef struct
{
  float xCoord;
  float yCoord;
} Point;

float calculateDistante(Point p1, Point p2)
{
  // Norma do vetor
  return sqrt(pow(p2.xCoord - p1.xCoord, 2) + pow(p2.yCoord - p1.yCoord, 2));
}

int main(int argc, char *argv[])
{
  Point points[2];

  for (int i = 0; i < 2; i++)
  {
    printf("Digite as coordenadas do ponto %i (x y): ", i + 1);
    scanf("%f %f", &points[i].xCoord, &points[i].yCoord);
  }

  float distance = calculateDistante(points[0], points[1]);

  printf("A distancia entre os pontos e: %.2f\n", distance);

  return 0;
}
