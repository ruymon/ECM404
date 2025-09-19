#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

void ExibirArestas(Grafo g)
{
    int i, j, a;
    printf("\nPeso da Aresta:\n");
    a = 65;
    for (i = 0; i < g.nVertices; i++)
        for (j = 0; j < g.nVertices; j++)
            if (PesoDaAresta(g, i, j) != 0)
                printf("Aresta %c%i,%i%c: w(%c)=%.1f\n",
                       g.digrafo == 0 ? '{' : '(',
                       i, j,
                       g.digrafo == 0 ? '}' : ')',
                       a++,
                       PesoDaAresta(g, i, j));
    printf("\n");
}

void ExibirGrafo(Grafo g)
{
    int i, j;
    // Troque por CLS se estiver usando Windows
    system("clear");
    printf("Numero de vertices do %s: %i\n", g.digrafo == 0 ? "GRAFO" : "DIGRAFO", g.nVertices);
    for (i = 0; i < g.nVertices; i++)
    {
        for (j = 0; j < g.nVertices; j++)
            printf("%0.1f   ", PesoDaAresta(g, i, j));
        printf("\n");
    }
    printf("\n");
}

void CriarGrafo(Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i = 0; i < g->nVertices; i++)
        for (j = 0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}

void InserirAresta(Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}

void RemoverAresta(Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}

float PesoDaAresta(Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}

int GrauDeEntrada(Grafo g, int v)
{
    int i, grau = 0;
    // Para um vértice 'v', percorremos a coluna 'v' da matriz,
    // somando 1 para cada aresta que chega em 'v'.
    for (i = 0; i < g.nVertices; i++)
    {
        if (g.Pesos[i][v] != 0)
        {
            grau++;
        }
    }
    return grau;
}

int GrauDeSaida(Grafo g, int v)
{
    int j, grau = 0;
    // Para um vértice 'v', percorremos a linha 'v' da matriz,
    // somando 1 para cada aresta que sai de 'v'.
    for (j = 0; j < g.nVertices; j++)
    {
        if (g.Pesos[v][j] != 0)
        {
            grau++;
        }
    }
    return grau;
}

int Vertedouro(Grafo g, int v)
{
    // Um vertedouro (fonte) é um vértice que não possui arestas de entrada.
    // Aplica-se apenas a dígrafos.
    if (!g.digrafo)
        return 0;
    return (GrauDeEntrada(g, v) == 0);
}

int Sorvedouro(Grafo g, int v)
{
    // Um sorvedouro (sumidouro) é um vértice que não possui arestas de saída.
    // Aplica-se apenas a dígrafos.
    if (!g.digrafo)
        return 0;
    return (GrauDeSaida(g, v) == 0);
}

int Adjacente(Grafo g, int de, int para)
{
    // Um vértice 'para' é adjacente a 'de' se houver uma aresta de 'de' para 'para'.
    return g.Pesos[de][para] != 0;
}

void Warshall(Grafo g, int w[MAX_VERT][MAX_VERT])
{
    int i, j, k;

    // Passo 1: Inicializa a matriz de alcançabilidade (w).
    // w[i][j] é 1 se i == j ou se existir uma aresta direta de i para j.
    for (i = 0; i < g.nVertices; i++)
    {
        for (j = 0; j < g.nVertices; j++)
        {
            if (i == j || g.Pesos[i][j] != 0)
            {
                w[i][j] = 1;
            }
            else
            {
                w[i][j] = 0;
            }
        }
    }

    // Passo 2: Itera sobre os vértices intermediários 'k'.
    for (k = 0; k < g.nVertices; k++)
    {
        for (i = 0; i < g.nVertices; i++)
        {
            for (j = 0; j < g.nVertices; j++)
            {
                // Existe um caminho de 'i' para 'j' se já existia um,
                // OU se existe um caminho de 'i' para 'k' E de 'k' para 'j'.
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
            }
        }
    }
}

int Alcanca(Grafo g, int de, int para)
{
    int w[MAX_VERT][MAX_VERT];
    // Calcula a matriz de alcançabilidade usando Warshall.
    Warshall(g, w);
    // Retorna 1 se 'para' é alcançável a partir de 'de', 0 caso contrário.
    return w[de][para];
}

float PesoDoPasseio(Grafo g, ListaDeVertices p)
{
    float pesoTotal = 0;
    int i;
    int de, para;

    // Um passeio precisa de pelo menos 2 vértices para ter uma aresta.
    if (p.nVertices < 2)
    {
        return 0;
    }

    // Itera pela sequência de vértices do passeio.
    for (i = 0; i < p.nVertices - 1; i++)
    {
        de = p.vertices[i];
        para = p.vertices[i + 1];

        // Verifica se existe uma aresta entre os vértices consecutivos.
        if (PesoDaAresta(g, de, para) == 0)
        {
            // Se a aresta não existe, a sequência não forma um passeio válido.
            return -1;
        }
        // Soma o peso da aresta ao total.
        pesoTotal += PesoDaAresta(g, de, para);
    }

    return pesoTotal;
}