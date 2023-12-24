#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

#define MAX_COLUMNS 10

typedef struct {
    char nome[50];
    char tipo[20];
} Coluna;

typedef struct {
    char nomeTabela[50];
    int chave;
    char nomeColuna[MAX_COLUMNS][50];
    int valorCol[MAX_COLUMNS];
    int tColunas;
} Tupla;

void criarTupla() {
    FILE *arquivo;
    Tupla novaTupla;

    printf("Nome da tabela: ");
    scanf("%s", novaTupla.nomeTabela);

    printf("Digite o valor da chave primaria: ");
    scanf("%d", &novaTupla.chave);

    printf("Quantidade de colunas (max %d): ", MAX_COLUMNS);
    scanf("%d", &novaTupla.tColunas);

    if (novaTupla.tColunas > MAX_COLUMNS || novaTupla.tColunas <= 0) {
        printf("Numero de colunas invalido.\n");
        return;
    }

    

    arquivo = fopen("projeto.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para inserir a nova tupla.");
        exit(1);
    }

    fprintf(arquivo, "\nNome da tabela: %s\n", novaTupla.nomeTabela);
    

    for (int i = 0; i < novaTupla.tColunas; i++) {
        printf("Nome da coluna %d: ", i + 1);
        scanf("%s", novaTupla.nomeColuna[i]);

        fprintf(arquivo, "Nome da coluna %d: %s\n", i + 1, novaTupla.nomeColuna[i]);

        printf("Valor da coluna %s: ", novaTupla.nomeColuna[i]);
        scanf("%d", &novaTupla.valorCol[i]);

        fprintf(arquivo, "Valor da coluna %s: %d\n", novaTupla.nomeColuna[i], novaTupla.valorCol[i]);
    }

    fclose(arquivo);
    

    printf("Nova tupla inserida com sucesso na tabela %s.\n", novaTupla.nomeTabela);
}