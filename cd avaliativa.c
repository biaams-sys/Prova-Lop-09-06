#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char genero[50];
    char banda[50];
    int escolha;
    int estoque;
    int vendidos;
} CD;

CD cds[60];
int totalCds = 0;
int qtdCompra = 0;
float valorCompra = 0;

void cadastrar();
void listarPorGenero();
void comprar();

int main() {
    int opc;

    do {
        printf("\n--- Loja Som & Arte ---\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Listar CDs por gênero\n");
        printf("3 - Comprar CD\n");
        printf("0 - Sair\n");
        scanf("%d", &opc);
        getchar();

        system("clear");

        switch(opc) {
            case 1: 
            cadastrar(); 
            break;
            case 2: 
            listarPorGenero(); 
            break;
            case 3: 
            comprar(); 
            break;
            case 0: 
            printf("Obrigada...\n"); 
            break;
            default: 
            printf("Opção inválida!\n");
        }

    } while(opc != 0);

    return 0;
}

void cadastrar() {
    if (totalCds >= 60) {
        printf("Estoque cheio!\n");
        return;
    }

    printf("CD nº: %d\n", totalCds + 1);
    printf("Escolha o gênero:\n1 - POP\n2 -Sertanejo \n3 - Rock\n4 - MPB\n");
    scanf("%d", &cds[totalCds].escolha);
    printf("Digite a banda:\n");
    scanf("%s", cds[totalCds].banda);
    printf("Quantidade em estoque:\n");
    scanf("%d", &cds[totalCds].estoque);
    getchar();

    cds[totalCds].vendidos = 0;
    totalCds++;
    printf("CD cadastrado com sucesso!\n");
}

void listarPorGenero() {
    int i, gen;
    printf("Escolha o gênero para listar:\n1 - POP \n2 - Sertanejo\n3 - Rock\n4 - MPB\n");
    scanf("%d", &gen);

    if (totalCds == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }

    int achou = 0;
    for (i = 0; i < totalCds; i++) {
        if (cds[i].escolha == gen) {
            printf("\nCD %d:\n", i + 1);
            printf("Banda: %s\n", cds[i].banda);
            printf("Qtd disponível: %d\n", cds[i].estoque - cds[i].vendidos);
            achou = 1;
        }
    }

    if (!achou) {
        printf("Nenhum CD encontrado para este gênero.\n");
    }
}

void comprar() {
    int num, qtd;

    printf("Número do CD para comprar:\n");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > totalCds) {
        printf("Número inválido.\n");
        return;
    }

    printf("Quantidade a comprar:\n");
    scanf("%d", &qtd);

    if (qtd > cds[num - 1].estoque - cds[num - 1].vendidos) {
        printf("Quantidade indisponível no estoque.\n");
        return;
    }

    cds[num - 1].vendidos += qtd;
    qtdCompra = qtd;
    valorCompra = qtd * 20.0;

    printf("Valor total: R$ %.2f\n", valorCompra);
    printf("Compra realizada com sucesso!\n");
}

