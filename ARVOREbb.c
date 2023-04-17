#include <stdio.h>
#include <stdlib.h>

struct no {
    int data;
    struct no* L1;
    struct no* R1;
};

struct no* criar_no(int data) {
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->data = data;
    novo->L1 = NULL;
    novo->R1 = NULL;
    return novo;
}

struct no* inserir(struct no* raiz, int data) {
    if (raiz == NULL) {
        return criar_no(data);
    }
    if (data < raiz->data) {
        raiz->L1 = inserir( raiz->L1, data);
    } else if (data > raiz->data) {
        raiz->R1 = inserir(raiz->R1, data);
    }
    return raiz;
}

void destruir_arvore(struct no* raiz) {
    if (raiz != NULL) {
        destruir_arvore(raiz->L1);
        destruir_arvore(raiz->R1);
        free(raiz);
    }
}

void exibir_arvore(struct no* raiz) {
    if (raiz != NULL) {
        exibir_arvore(raiz->L1);
        printf("%d ", raiz->data);
        exibir_arvore(raiz->R1);
    }
}

int main() {
    struct no* raiz = NULL;
    int num_elementos, elemento, op;
    printf("====================================\n");
    printf("1->INSERIR NA ARVORE\n2->MOSTRAR ARVORE\n3->DESTRUIR ARVORE\n");
    printf("====================================\n>");
    scanf("%d",&op);
    while(op != 4) {
        if(op == 1) {
            printf("Digite o número de elementos que deseja inserir: ");
            scanf("%d", &num_elementos);
            for(int i = 0; i < num_elementos; i++) {
                printf("Digite o elemento %d: ", i + 1);
                scanf("%d", &elemento);
                raiz = inserir(raiz, elemento);
            }
        }
        else if(op == 2) {
            printf("==========ARVORE BINARIA==========\n");
            exibir_arvore(raiz);
            printf("\n==================================\n");
        }
        else if(op == 3) {
            destruir_arvore(raiz);
        }
        
        printf("====================================\n");
        printf("1->INSERIR NA ARVORE\n2->MOSTRAR ARVORE\n3->DESTRUIR ARVORE\n");
        printf("====================================\n>");
        scanf("%d", &op);
    }
    return 0;
}
