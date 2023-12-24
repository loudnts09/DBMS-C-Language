#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

void apagarTupla() {
    FILE *arquivo;
    char nomeTabela[50], l[100];
    int encontrouTupla = 0, encontrouChave = 0, chave;

    printf("Digite o nome da tabela para excluir a tupla: ");
    scanf("%s", nomeTabela);

    printf("Digite a chave primaria da tupla a ser excluida: ");
    scanf("%d", &chave);

    arquivo = fopen("projeto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    FILE *arquivoTemp = fopen("temp.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao criar arquivo temporario.");
        exit(1);
    }

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da tabela:") != NULL) {
            char nomeExistente[50];
            sscanf(l, "Nome da tabela: %s", nomeExistente);

            if (strcmp(nomeExistente, nomeTabela) == 0) {
                encontrouTupla = 1;
            }
        }

        if (strstr(l, "Valor da chave primaria:") != NULL) {
            int chaveExistente;
            sscanf(l, "Valor da chave primaria: %d", &chaveExistente);
            if (chaveExistente == chave && encontrouTupla) {
                encontrouChave = 1;
                encontrouTupla = 0;
                continue;
            }
        }

        if (!encontrouChave) {
            fprintf(arquivoTemp, "%s", l);
        } else {
            encontrouChave = 0;
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    remove("projeto.txt");
    rename("temp.txt", "projeto.txt");

    printf("Tupla excluida com sucesso da tabela %s.\n", nomeTabela);
}