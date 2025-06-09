#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
} pizza;

typedef struct {
    char nome[50], cpf[20];
} cliente;

pizza pizzas[10];
int numpizza = 0;

cliente clientes[100];
int numcliente = 0;

void cadastrarpizza();
void cadastrarcliente();
void listarclientes();
void listapizzas();
void finalizarcompra();

int main() {
    int opcao;

    do {
        printf("-- Pizzaria Nostra Pizza --\n");
        printf("1-- Cadastre a Pizza \n");
        printf("2-- Cadastre o cliente \n");
        printf("3-- Lista de clientes \n");
        printf("4-- Lista de pizzas \n");
        printf("5-- Finalizar a compra \n");
        printf("0-- Sair \n");
        printf("Selecione a opção desejada: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao) {
            case 1:
                cadastrarpizza();
                break;
            case 2:
                cadastrarcliente();
                break;
            case 3:
                listarclientes();
                break;
            case 4:
                listapizzas();
                break;
            case 5:
                finalizarcompra();
                break;
            case 0:
                printf("Obrigado e volte sempre!\n");
                break;
            default:
                printf("Inválido!\n");
                break;
        }

        printf("Aperte enter para continuar...");
        getchar(); 
        getchar();
        system("clear");

    } while (opcao != 0);

    return 0;
}

void cadastrarpizza() {
    printf("--Cadastre a pizza--\n");

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", pizzas[numpizza].nome);

    printf("Digite o preço para pizza: ");
    scanf("%f", &pizzas[numpizza].preco);
    numpizza++; 
}

void cadastrarcliente() {
    printf(" Cadastre-se \n");

    printf("Digite o seu nome: ");
    scanf(" %[^\n]", clientes[numcliente].nome);

    printf("Digite o  seu CPF: ");
    scanf(" %s", clientes[numcliente].cpf);
    numcliente ++;
}

void listarclientes() {
    printf("--Clientes Cadastradas--\n");
    for (int i = 0; i < numcliente; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
    }
}

void listapizzas() {
    printf("--Pizzas Cadastradas--\n");
    for (int i = 0; i < numpizza; i++) {
        printf("Nome: %s\n", pizzas[i].nome);
        printf("Preço: %.2f\n", pizzas[i].preco);
    }
}

void finalizarcompra() {
    char cpfconferido[20];
    int casa, opcaopizza;
    float valortotal;

    printf("Para começar a sua compra escreva seu CPF: ");
    scanf(" %s", cpfconferido);

    for (int i = 0; i < numcliente; i++) {
        int iguais = 1;
        int j = 0;
        while (cpfconferido[j] == clientes[i].cpf[j] && cpfconferido[j] != 0) {
            j++;
        }
        if (cpfconferido[j] != clientes[i].cpf[j]) {
            iguais = 0;
        }

        if (iguais) {
            printf("Bem-vindo, %s!\n", clientes[i].nome);

            printf("\nEscolha os sabores desejados dentre os listados:\n");
            for (int k = 0; k < numpizza; k++) {
                printf("%d -- Nome: %s, Preço: %.2f\n", k + 1, pizzas[k].nome, pizzas[k].preco);
            }

            printf("Digite o número da pizza que deseja comprar: ");
            scanf("%d", &opcaopizza);

            printf("Digite seu número de casa para entrega: ");
            scanf("%d", &casa);

            valortotal = pizzas[opcaopizza - 1].preco;

            printf("\nPizza escolhida: %s\n", pizzas[opcaopizza - 1].nome);
            printf("O valor total da sua compra foi: R$ %.2f\n", valortotal);
            printf("A pizza será entregue na casa número: %d\n", casa);
            return;
        }
    }

    printf("Você não pode comprar por não estar cadastrado!!\n");
}

