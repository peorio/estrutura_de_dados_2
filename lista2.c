// Lista de exercicios 2

// 1) C
// 2) C
// 3) C
// 4) B
// 5) A
// 6) B
// 7) 
// Árvore ccheia: todos os nós terão 0 ou 2 filhos
// Árvore completa: todos os nós estao completos, exceto o ultimo
// 8)     A
//       / \
//      B   C
//     / \
//    D   E
//
//    Pré-ordem: A,B,D,E,C
//    Em-ordem: D,B,E,A,C
//    Pós-ordem: D,E,B,C,A
// 9) Quando voce precisa buscar dados rapidamente
// 36)
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// 37)
No *criarNo(int valor) {

    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

// 38)
void preOrdem(No *raiz){

    if(raiz != NULL){

        printf("%d ", raiz->valor);

        preOrdem(raiz->esq);

        preOrdem(raiz->dir);
    }
}
// 39)
void emOrdem(No *raiz){

    if(raiz != NULL){

        emOrdem(raiz->esq);

        printf("%d ", raiz->valor);

        emOrdem(raiz->dir);
    }
}

// 40)
void posOrdem(No *raiz){

    if(raiz != NULL){

        posOrdem(raiz->esq);

        posOrdem(raiz->dir);

        printf("%d ", raiz->valor);
    }
}
// 41)
int cont(No *raiz){

    if(raiz == NULL)
        return 0;

    return 1 +
           contarNos(raiz->esq) +
           contarNos(raiz->dir);
}
// 42)
int altura(No *raiz){

    if(raiz == NULL)
        return -1;

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    return (esq > dir ? esq : dir) + 1;
}

// 43)
int contarFolhas(No *raiz){

    if(raiz == NULL)
        return 0;

    if(raiz->esq == NULL &&
       raiz->dir == NULL)
       return 1;

    return contarFolhas(raiz->esq) +
           contarFolhas(raiz->dir);
}

// 44)
void espelhar(No *raiz){

    if(raiz == NULL)
        return;

    No *temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;

    espelhar(raiz->esq);
    espelhar(raiz->dir);
}

// 45)
int iguais(No *a, No *b){

    if(a == NULL && b == NULL)
        return 1;

    if(a == NULL || b == NULL)
        return 0;

    return (a->valor == b->valor)
        && iguais(a->esq,b->esq)
        && iguais(a->dir,b->dir);
}