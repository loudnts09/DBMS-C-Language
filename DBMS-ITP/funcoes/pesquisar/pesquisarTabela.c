#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

void pesquisarTabela() {
    FILE *arquivo;
    char nomeTabela[50], l[100];
    int encontrou = 0;
    printf("Qual tabela deseja encontrar? ");
    scanf("%s", nomeTabela);

    arquivo = fopen("projeto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }


    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da tabela:") != NULL) {
            char nomeExist[50];
            sscanf(l, "Nome da tabela: %s", nomeExist);
            if (strcmp(nomeExist, nomeTabela) == 0) {
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou) {
        printf("Tabela nao encontrada.\n");
        fclose(arquivo);
        return;
    }

    printf("Escolha a coluna para a pesquisa:\n");

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da coluna") != NULL) {
            char nomeColuna[50];
            sscanf(l, "Nome da coluna %*d: %s", nomeColuna);
            printf("- %s\n", nomeColuna);
        }
    }

    char colunaSelecionada[50];
    printf("Escolha a coluna para a pesquisa: ");
    scanf("%s", colunaSelecionada);
    fclose(arquivo);
}