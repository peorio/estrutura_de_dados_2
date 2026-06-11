// Lista de exercicios 1

// 1) C
// 2) B
// 3) C
// 4) C
// 5) B
// 6) A
// 7) D
// 8) A
// 9) Uma árvore é uma estrutura de dados composta por nós de uma forma hierárquica tendo pai e filhos
// 10) 
// Nó raiz: primeiro nó da arvore
// Nó folha: nó que nao tem filho
// Nó interno: nó que tem pelo menos um filho
// 11) 
// Ancestrais: São todos os nós que estão acima de um determinado nó
// Descendentes: São todos os nós abaixo de um determinado nó
// 12) São as quantidades de ligacões entre a raiz e o nó
// 13)
// Grau de um nó: Quantidades de filho do nó
// Grau da árvore: Maior graú encontrado entre todos os nós da árvore
// 14) As árvores permitem organizar de forma hierarquicas os dados, melhorando na hora de fazer buscas, e em insercão de dados e remocao
// 15)
//         10
//        /  \
//       5   14
//      / \    \
//     3   7   20
//            /  \
//           18   24

// 16)
#include <stdio.h>
#include <stdlib.h>

#define max_filhos 10

typedef struct No {
    int valor;
    struct No *filhos[max_filhos];
    int numFilhos;
} No;

// 17)
No *arvoreVazia() {
    return NULL;
}

// 18)
void inserirFilho(No *pai, int valor) {

    if(pai->numFilhos < max_filhos) {

        No *novo = criarNo(valor);

        pai->filhos[pai->numFilhos] = novo;

        pai->numFilhos++;
    }
}

// 19)
int cont(No *raiz) {

    if(raiz == NULL)
        return 0;

    int total = 1;

    for(int i = 0; i < raiz->numFilhos; i++) {
        total += cont(raiz->filhos[i]);
    }

    return total;
}

// 20)
int altura(No *raiz) {

    if(raiz == NULL)
        return -1;

    int maior = -1;

    for(int i = 0; i < raiz->numFilhos; i++) {

        int h = altura(raiz->filhos[i]);

        if(h > maior)
            maior = h;
    }

    return maior + 1;
}

// 21)
int contarFolhas(No *raiz) {

    if(raiz == NULL)
        return 0;

    if(raiz->numFilhos == 0)
        return 1;

    int total = 0;

    for(int i = 0; i < raiz->numFilhos; i++) {
        total += contarFolhas(raiz->filhos[i]);
    }

    return total;
}

// 22)
int buscar(No *raiz, int valor) {

    if(raiz == NULL)
        return 0;

    if(raiz->valor == valor)
        return 1;

    for(int i = 0; i < raiz->numFilhos; i++) {

        if(buscar(raiz->filhos[i], valor))
            return 1;
    }

    return 0;
}

// 23)
void imprimirNivel(No *raiz, int nivel) {

    if(raiz == NULL)
        return;

    if(nivel == 0) {
        printf("%d ", raiz->valor);
    }
    else {

        for(int i = 0; i < raiz->numFilhos; i++) {
            imprimirNivel(raiz->filhos[i], nivel - 1);
        }
    }
}

// 24) A recurcão é muito usada em árvores porque deixa suas operacoes mais faceis e organizadas

// 25)
void destruirArvore(No *raiz) {

    if(raiz == NULL)
        return;

    for(int i = 0; i < raiz->numFilhos; i++) {

        destruirArvore(raiz->filhos[i]);
    }

    free(raiz);
}