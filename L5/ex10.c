/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, exibir o maior pal�ndromo poss�vel dentro da string digitada.
 * Caso n�o haja nenhum pal�ndromo poss�vel, o programa deve alertar o usu�rio.
 * O programa deve desconsiderar diferen�as entre letras min�sculas e letras
 * mai�sculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   N�o existe nenhum pal�ndromo poss�vel
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */
void ler_string(char s[MAX]);
void inverte_string(char s[MAX], char s_inv[MAX]);
void substring(char destino[MAX], char origem[MAX], int comeco, int fim);
int verifica_palindromo(char s[MAX]);
void maior_palindromo(char s[MAX], char s2[MAX]);
void to_lower_string(char s[MAX]);

int main (int argc, char *argv[]){


  return 0;
}

