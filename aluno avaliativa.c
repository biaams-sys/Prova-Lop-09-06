#include <stdio.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
};

struct aluno alunos[3]; 

void listarAlunos() {
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("nome: %s\n", alunos[i].nome);
        printf("idade: %d\n", alunos[i].idade);
        printf("nota: %.2f\n", alunos[i].nota);
    }
}
int main() {
    for (int i = 0; i < 3; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        printf("nome: ");
        scanf("%s", alunos[i].nome); 

        printf("idade: ");
        scanf("%d", &alunos[i].idade);

        printf("nota: ");
        scanf("%f", &alunos[i].nota);
    }
    listarAlunos();
    return 0;
}