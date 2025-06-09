#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produto;
int produtoCadastrado = 0;

void cadastrarProduto();
void visualizarEstoque();
void finalizarCompra();

int main() {
    int opcao;

    do {
        printf("\n--Supermercado SuperMAIS--\n");
        printf("1. Cadastrar produto\n");
        printf("2. Estoque\n");
        printf("3. Finalizar compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarEstoque();
                break;
            case 3:
                finalizarCompra();
                break;
            case 0:
                printf("\nEncerrando o sistema. Obrigado!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }

        if(opcao != 0) {
            printf("Pressione Enter para continuar...");
            getchar();
            system("clear");
        }

    } while (opcao != 0);

    return 0;
}

void cadastrarProduto() {
    printf("\n--Cadastre O produto--\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    getchar();

    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);
    getchar();

    printf("Preço: ");
    scanf("%f", &produto.preco);
    getchar();

    produtoCadastrado = 1;
    printf("Produto cadastrado com sucesso!\n");
}

void visualizarEstoque() {
    if (produtoCadastrado) {
        printf("\n--- Informações do Produto ---\n");
        printf("Nome: %s\n", produto.nome);
        printf("Quantidade em estoque: %d\n", produto.quantidade);
        printf("Preço: R$%.2f\n", produto.preco);
    } else {
        printf("\nNenhum produto cadastrado.\n");
    }
}

void finalizarCompra() {
    if (!produtoCadastrado) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int quantidadeCompra;
    printf("\n--- Finalizar Compra ---\n");
    printf("Quantidade a comprar: ");
    scanf("%d", &quantidadeCompra);
    getchar();

    if (quantidadeCompra <= 0) {
        printf("Quantidade inválida.\n");
        return;
    }

    if (quantidadeCompra > produto.quantidade) {
        printf("Quantidade solicitada é maior que o estoque atual: %d\n", produto.quantidade);
    } else {
        produto.quantidade -= quantidadeCompra;
        printf("Compra realizada com sucesso!\n");
        printf("Quantidade restante em estoque: %d\n", produto.quantidade);
    }
}

