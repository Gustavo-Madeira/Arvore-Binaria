#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

// Função para inserir um valor na árvore
No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

// Função para caminhar em pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Função para caminhar em pós-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Função para caminhar em intraordem
void intraOrdem(No* raiz) {
    if (raiz != NULL) {
        intraOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        intraOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;
    int valores[10];
    int opcao;

    printf("Digite 10 valores numericos para criar a arvore binaria:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
        raiz = inserirNo(raiz, valores[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Pre-ordem\n");
        printf("2 - Pos-ordem\n");
        printf("3 - Intraordem\n");
        printf("9 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Caminhamento Pre-ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 2:
                printf("Caminhamento Pos-ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Caminhamento Intraordem: ");
                intraOrdem(raiz);
                printf("\n");
                break;
            case 9:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 9);

    return 0;
}