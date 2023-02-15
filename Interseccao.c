

#include <stdio.h>
#include <stdlib.h>

void Imprime(int *C, int t)
{

    printf("Tamanho: %d\n", t);
    printf("Imprimindo C: ");
    for (int i = 0; i < t; i++)
    {
        printf("%d - ", C[i]);
    }
}

int *Intersecao(int *c1, int *c2, int t1, int t2)
{

    int *C = (int *)malloc(sizeof(int) * (t2));
    int indice = 0;
    // 1 2 3 4 5 6 7 8 9 10
    // 1 3 5 7 9

    printf("\nTamanhos : %d %d\n\n", t1, t2);

    for (int i = 0; i < t1; i++)
    {
        for (int j = 0; j < t2; j++)
        {
            if (c1[i] == c2[j])
            {
                C[indice] = c1[i];
                indice++;
                // printf("%d ", C[i]);
            }
        }
    }

    // Imprime(C, t2);
    return C;
    free(C);
}

// Faça a união de dois vetores
int *Uniao(int *c1, int *c2, int t1, int t2)
{
    int tam = t1 + t2;
    int *C = (int *)malloc(sizeof(int) * (t1 + t2));
    int indice = 0, valores_repetidos = 0, redimensionado = 0;

    // União dos vetores
    for (int i = 0; i < t1; i++)
    {
        C[indice] = c1[i];
        indice++;
    }

    for (int i = 0; i < t2; i++)
    {
        C[indice] = c2[i];
        indice++;
    }
    //conta quantos valores repetidos tem
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (C[j] == C[i])
            {
                valores_repetidos++;
            }
        }
    }

    // Ordenar
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (C[i] < C[j])
            {
                int aux = C[i];
                C[i] = C[j];
                C[j] = aux;
            }
            
        }
    }
    /*
    
    */
    // Redireciona os valores repetidos para o final do vetor
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (C[j] == C[i])
            {

                for (int k = j; k < tam; k++)
                {
                    C[k] = C[k + 1];
                }
            }
        }
    }

    // Redimensiona
    printf("Valores repetidos: %d\n", valores_repetidos);
    redimensionado = tam - valores_repetidos;
    printf("Redimensionado: %d\n", redimensionado);
    C = (int *)realloc(C, sizeof(int) * (redimensionado));
    Imprime(C, redimensionado);
    return C;
    free(C);
}

int main()
{
    // {1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9, 10}
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int a2[] = {1, 3, 5, 7, 9, 11};
    int *P;
    int *U;
    // P = Intersecao(a1, a2, 10, 5);
    U = Uniao(a1, a2, 11, 6);

    // Imprime(P, 5);

    return 0;
}