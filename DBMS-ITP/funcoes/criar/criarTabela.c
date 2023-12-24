#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>
#include "../headers.h"

typedef struct { 
    char nome[50];
    char tipo[20];
} Coluna;

typedef struct {
    char nome[50];
    Coluna colunas[20];
    int chavePrimaria;
    int totalColunas;
} Tabela;

void criarTabela() {
    Tabela novaTabela;
    int chave;

    printf("Nome da tabela: ");
    scanf("%s", novaTabela.nome);

    printf("Nome da chave primaria: ");
    scanf("%s", novaTabela.colunas[0].nome);

    while (1) {
        printf("Qual chave primaria (int): ");
        int r = scanf("%d", &chave);

        if (r == 1) {
            novaTabela.chavePrimaria = chave;
            break;
        } else {
            printf("Digite um valor inteiro!\n");
            while (getchar() != '\n');
        }
    }

    printf("Nº de colunas: ");
    scanf("%d", &novaTabela.totalColunas);

    FILE *arquivo; 
    arquivo = fopen("projeto.txt", "a");
   
    fprintf(arquivo, "Nome da tabela: %s\n", novaTabela.nome);
    fprintf(arquivo, "Chave primaria: %s\n", novaTabela.colunas[0].nome);
    fprintf(arquivo, "Valor da chave primaria: %d\n", novaTabela.chavePrimaria);
    fprintf(arquivo, "Total de colunas: %d\n", novaTabela.totalColunas); 

    for (int i = 1; i <= novaTabela.totalColunas; i++) {
        printf("Digite o nome da coluna %d: ", i); 
        scanf("%s", novaTabela.colunas[i].nome); 
        printf("Digite o tipo de dado da coluna %d: ", i); 
        scanf("%s", novaTabela.colunas[i].tipo);
        fprintf(arquivo, "Nome da coluna %d: %s\n", i, novaTabela.colunas[i].nome);
        fprintf(arquivo, "Tipo da coluna %d: %s\n", i, novaTabela.colunas[i].tipo);
    }

    printf("\nTabela criada!\n");
    fclose(arquivo);
}
