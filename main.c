#include <stdio.h>

int buscarProduto(int codigo[], int total, int codigoBusca) {
    int i;

    for (i = 0; i < total; i++) {
        if (codigo[i] == codigoBusca) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int codigo[20];
    char nome[20][50];
    float preco[20];
    int quantidade[20];
    int total = 0;

    int opcao, codigoBusca, posicao, i, j;

    do {
        printf("\n1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total == 20) {
                    printf("Limite maximo de cadastros atingido.\n");
                    break;
                }

                printf("Codigo: ");
                scanf("%d", &codigo[total]);

                posicao = buscarProduto(codigo, total, codigo[total]);
                if (posicao != -1) {
                    printf("Codigo ja cadastrado.\n");
                    break;
                }

                printf("Nome (sem espacos, ate 49 caracteres): ");
                scanf("%49s", nome[total]);

                printf("Preco (use ponto para os centavos): ");
                scanf("%f", &preco[total]);

                printf("Quantidade: ");
                scanf("%d", &quantidade[total]);

                total++;
                printf("Produto cadastrado.\n");
                break;

            case 2:
                printf("Codigo para consultar: ");
                scanf("%d", &codigoBusca);

                posicao = buscarProduto(codigo, total, codigoBusca);

                if (posicao == -1) {
                    printf("Registro nao encontrado.\n");
                } else {
                    printf("\nCodigo: %d\n", codigo[posicao]);
                    printf("Nome: %s\n", nome[posicao]);
                    printf("Preco: %.2f\n", preco[posicao]);
                    printf("Quantidade: %d\n", quantidade[posicao]);
                }
                break;

            case 3:
                if (total == 0) {
                    printf("Nenhum registro cadastrado.\n");
                } else {
                    for (i = 0; i < total; i++) {
                        printf("\nCodigo: %d\n", codigo[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Preco: %.2f\n", preco[i]);
                        printf("Quantidade: %d\n", quantidade[i]);
                    }
                }
                break;

            case 4:
                printf("Codigo para alterar: ");
                scanf("%d", &codigoBusca);

                posicao = buscarProduto(codigo, total, codigoBusca);
                if (posicao == -1) {
                    printf("Registro nao encontrado.\n");
                    break;
                }

                printf("Novo nome (sem espacos, ate 49 caracteres): ");
                scanf("%49s", nome[posicao]);

                printf("Novo preco (use ponto para os centavos): ");
                scanf("%f", &preco[posicao]);

                printf("Nova quantidade: ");
                scanf("%d", &quantidade[posicao]);
                printf("Produto alterado.\n");
                break;

            case 5:
                printf("Codigo para excluir: ");
                scanf("%d", &codigoBusca);

                posicao = buscarProduto(codigo, total, codigoBusca);
                if (posicao == -1) {
                    printf("Nao foi possivel excluir.\n");
                    break;
                }

                for (i = posicao; i < total - 1; i++) {
                    codigo[i] = codigo[i + 1];
                    preco[i] = preco[i + 1];
                    quantidade[i] = quantidade[i + 1];
                    for (j = 0; nome[i + 1][j] != '\0'; j++) {
                        nome[i][j] = nome[i + 1][j];
                    }
                    nome[i][j] = '\0';
                }
                total--;
                printf("Produto excluido.\n");
                break;

            case 0:
                printf("Sistema encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
