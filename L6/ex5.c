#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Enunciado:
 *
 * Crie uma estrutura Retângulo com dois pontos: superior esquerdo e inferior direito.
 * Cada ponto tem X e Y. Leia um retângulo e calcule a área, perímetro e a diagonal.
 */

typedef struct
{
  float xCoord;
  float yCoord;
} Point;

float calculateDiagonal(Point p1, Point p2)
{
  return sqrt(pow(p2.xCoord - p1.xCoord, 2) + pow(p2.yCoord - p1.yCoord, 2));
}

float calculateArea(Point p1, Point p2)
{
  return fabs((p2.xCoord - p1.xCoord) * (p2.yCoord - p1.yCoord));
}

float calculatePerimeter(Point p1, Point p2)
{
  return 2 * (fabs(p2.xCoord - p1.xCoord) + fabs(p2.yCoord - p1.yCoord));
}

int main(int argc, char *argv[])
{
  Point points[2];

  printf("Digite as coordenadas do ponto superior esquerdo (x y): ");
  scanf("%f %f", &points[0].xCoord, &points[0].yCoord);

  printf("Digite as coordenadas do ponto inferior direito (x y): ");
  scanf("%f %f", &points[1].xCoord, &points[1].yCoord);

  printf("Area: %.2f\n", calculateArea(points[0], points[1]));
  printf("Perimetro: %.2f\n", calculatePerimeter(points[0], points[1]));
  printf("Diagonal: %.2f\n", calculateDiagonal(points[0], points[1]));

  return 0;
}
