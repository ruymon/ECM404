#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Usando a estrutura Retângulo (do exercício 5) e Ponto (do exercício 4), leia um
 * retângulo e um ponto. Informe se o ponto está dentro do retângulo.
 */

typedef struct
{
  float xCoord;
  float yCoord;
} Point;

typedef struct
{
  Point upperLeft;
  Point lowerRight;
} Rectangle;

int isPointInsideRectangle(Point point, Rectangle rect)
{
  int isBoundedInX = point.xCoord >= rect.upperLeft.xCoord && point.xCoord <= rect.lowerRight.xCoord;
  int isBoundedInY = point.yCoord <= rect.upperLeft.yCoord && point.yCoord >= rect.lowerRight.yCoord;

  return isBoundedInX && isBoundedInY;
}

int main(int argc, char *argv[])
{
  Rectangle rect;
  Point point;

  printf("Digite as coordenadas do ponto superior esquerdo do retangulo (x y): ");
  scanf("%f %f", &rect.upperLeft.xCoord, &rect.upperLeft.yCoord);

  printf("Digite as coordenadas do ponto inferior direito do retangulo (x y): ");
  scanf("%f %f", &rect.lowerRight.xCoord, &rect.lowerRight.yCoord);

  printf("Digite as coordenadas do ponto (x y): ");
  scanf("%f %f", &point.xCoord, &point.yCoord);

  printf("O ponto %s dentro do retangulo.\n",
         isPointInsideRectangle(point, rect) ? "esta" : "nao esta");

  return 0;
}
