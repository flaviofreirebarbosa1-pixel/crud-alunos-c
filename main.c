#include <stdio.h>

int main() {

    struct Aluno {
        int id;
        char nome[50];
        float nota;
    };

    struct Aluno alunos[10];

    int qtd = 0;
    int opcao;
    int i, j;
    int id;
    int encontrado;

    do {

        printf("\n=================================\n");
        printf("   SISTEMA DE CADASTRO DE ALUNOS\n");
        printf("=================================\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno por ID\n");
        printf("4 - Atualizar aluno\n");
        printf("5 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                if(qtd >= 10) {
                    printf("\nLimite de alunos atingido.\n");
                    break;
                }

                printf("\nDigite o ID: ");
                scanf("%d", &id);

                if(id <= 0) {
                    printf("ID invalido.\n");
                    break;
                }

                encontrado = 0;

                for(i = 0; i < qtd; i++) {
                    if(alunos[i].id == id) {
                        encontrado = 1;
                    }
                }

                if(encontrado) {
                    printf("ID ja cadastrado.\n");
                    break;
                }

                alunos[qtd].id = id;

                printf("Digite o nome: ");
                scanf(" %[^\n]", alunos[qtd].nome);

                printf("Digite a nota (0 a 10): ");
                scanf("%f", &alunos[qtd].nota);

                if(alunos[qtd].nota < 0 || alunos[qtd].nota > 10) {
                    printf("Nota invalida.\n");
                    break;
                }

                qtd++;

                printf("Aluno cadastrado com sucesso!\n");

                break;

            case 2:

                if(qtd == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\n===== LISTA DE ALUNOS =====\n");

                for(i = 0; i < qtd; i++) {

                    printf("\nAluno %d\n", i + 1);
                    printf("ID: %d\n", alunos[i].id);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Nota: %.2f\n", alunos[i].nota);
                }

                break;

            case 3:

                if(qtd == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\nDigite o ID do aluno: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < qtd; i++) {

                    if(alunos[i].id == id) {

                        printf("\nAluno encontrado:\n");
                        printf("ID: %d\n", alunos[i].id);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Nota: %.2f\n", alunos[i].nota);

                        encontrado = 1;
                    }
                }

                if(!encontrado) {
                    printf("Aluno nao encontrado.\n");
                }

                break;

            case 4:

                if(qtd == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\nDigite o ID do aluno: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < qtd; i++) {

                    if(alunos[i].id == id) {

                        printf("Novo nome: ");
                        scanf(" %[^\n]", alunos[i].nome);

                        printf("Nova nota: ");
                        scanf("%f", &alunos[i].nota);

                        if(alunos[i].nota < 0 || alunos[i].nota > 10) {
                            printf("Nota invalida.\n");
                            break;
                        }

                        printf("Aluno atualizado com sucesso.\n");

                        encontrado = 1;
                    }
                }

                if(!encontrado) {
                    printf("Aluno nao encontrado.\n");
                }

                break;

            case 5:

                if(qtd == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\nDigite o ID do aluno: ");
                scanf("%d", &id);

                encontrado = 0;

                for(i = 0; i < qtd; i++) {

                    if(alunos[i].id == id) {

                        for(j = i; j < qtd - 1; j++) {
                            alunos[j] = alunos[j + 1];
                        }

                        qtd--;

                        printf("Aluno removido com sucesso.\n");

                        encontrado = 1;

                        break;
                    }
                }

                if(!encontrado) {
                    printf("Aluno nao encontrado.\n");
                }

                break;

            case 0:

                printf("\nEncerrando sistema...\n");
                break;

            default:

                printf("\nOpcao invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}
