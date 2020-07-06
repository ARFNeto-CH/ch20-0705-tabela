#include <stdio.h>
#include <stdlib.h>

void    arruma_matriz(char*, int, int); // preenche
float   calcula_valor(char); // o calculo como pedido
int     conta_ocorrencias(char*, int, int); // conta
int     mostra_matriz(char*, int, int); // mostra a matriz

int main()
{
    srand(20200705);
    char    matriz[10][10]; // a matriz maior possivel
    int N = 6; // N testes com matrizes aleatorias
    printf("Agora %d matrizes com tamanho e atributos aleatorios\n\n", N);
    for (int i = 1; i <= N; i += 1)
    {
        int l = rand() % 10 + 1; // linhas
        int c = rand() % 10 + 1; // colunas
        int o = rand() % 2; // opcao
        printf("\n\nTeste %d de %d: Matriz [%d,%d] opcao %d\n\n",
            i, N, l, c, o);
        arruma_matriz(&matriz[0][0], l, c);
        mostra_matriz(&matriz[0][0], l, c);
        printf("Valor calculado a partir de %c [decimal %d]: %4.2f\n\n",
            matriz[0][0], 
            matriz[0][0],
            calcula_valor(matriz[0][0]));
        conta_ocorrencias(&matriz[0][0], l, c);
    };  // for()
    return 0;
};  // main()

void     arruma_matriz(char* M, int linhas, int colunas)
{
    for (int i = 0; i < linhas * colunas; i += 1)
        *(M + i) = (rand() % 26) + 'a' - (rand() % 2 * 32);
}

float   calcula_valor(char C)
{
    if (C > 'Z') return (float)(C + C);
    return (float)(C / 10.f);
};

int     conta_ocorrencias(char* M, int L, int C)
{   // conta as ocorrencias de cada letra na matriz M[L,C]
    const char* barra =  "-------------------------\n";
    const char* titulo = "| Letra |  Ocorrencias  |\n";
    int tabela[256] = { 0 };
    for (int i = 0; i < (L * C); i += 1) tabela[*(M + i)] += 1;
    printf("%s%s%s", barra, titulo, barra);
    for (int i = 0; i < 256; i += 1)
        if (tabela[i] > 0)
            printf("|   %c   |      %3d      |\n", i, tabela[i]);
    printf("%s", barra);
    return 0;
};

int     mostra_matriz(char* M, int L, int C)
{
    // mostra na tela a matriz M[L,C]
    int N = L * C; // o tamanho da matriz
    int z = 0;
    char* p = M;
    for (int i = 0; i < N; i += 1)
    {
        z = z + 1;
        printf("%c ", *(p + i));
        if ((z % C) == 0) printf("\n");
    };  // for()
    printf("\n");
    return 0;
};

//  fim ch 1462569