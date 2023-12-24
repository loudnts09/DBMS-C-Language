#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

void listarDados() {
    FILE *arquivo;
    char nomeTabela[50], l[100];
    int aux1 = 0, totalCol = 0, lAtual = 1;

    printf("Nome da tabela: ");
    scanf("%s", nomeTabela);

    arquivo = fopen("projeto.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da tabela:") != NULL) {
            char nomeExistente[50];
            sscanf(l, "Nome da tabela: %s", nomeExistente);
            if (strcmp(nomeExistente, nomeTabela) == 0) {
                aux1 = 1;
            }
        }

        if (aux1 && strstr(l, "Total de colunas:") != NULL) {
            sscanf(l, "Total de colunas: %d", &totalCol);
            printf("Dados da tabela %s:\n", nomeTabela); 
            break; 
        }
    }

    if (!aux1 || totalCol == 0) {
        printf("Tabela não encontrada ou sem colunas.\n");
        fclose(arquivo);
        return;
    }

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da coluna") != NULL) {
            lAtual++;
            if (lAtual > totalCol * 2) {
                break;
            }
            printf("%s", l);
        }
    }

    fclose(arquivo);
}
