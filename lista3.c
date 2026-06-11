// Lista de exercicios 3

// 1) C
// 2) C
// 3) C
// 4) B
// 5) Vai comecar pela raiz, depois vai ser comparado o valor com o nó atual, se for menor ele vai pra esquerda
//    se for maior vai pra direita, e quando encontrar um ponteiro NULL vai ser inserido o valor ali
// 6) Comeca pela raiz, depois compara com o valor atual, se for igual, encontramos o valor
//    se for menor, vai para a esquerda. Se for maior, vai para a direita. Se chegarmos em NULL, o valor não existe.
// 7) 
// Remocacao da folha: basta apagar nó desejado, colocando o null no ponteiro pai
// Remocacao de nó com dois filhos: precisamos encontrar o seu sucessor em ordem

// 8) A ABB deixa os dados ordenados, permitindo fazer buscas eficientes e insercão e remocao
// 9) quando a árvore fica muito inclinada ela fica parecida com uma lista encadeada, deixando sua busca mais lenta junto com a insercao e remocap

// Esse codigo faz parte das respostas de implementacoes
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Criar nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// 10) Inserção recursiva
No* inserir(No* raiz, int valor) {

    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);

    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}
// 11) Busca
No* buscar(No* raiz, int valor) {

    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}
// 12. Em ordem
void emOrdem(No* raiz) {

    if (raiz != NULL) {

        emOrdem(raiz->esq);

        printf("%d ", raiz->valor);

        emOrdem(raiz->dir);
    }
}
// 16. Menor valor
No* menorValor(No* raiz) {

    while (raiz->esq != NULL)
        raiz = raiz->esq;

    return raiz;
}

// Maior valor
No* maiorValor(No* raiz) {

    while (raiz->dir != NULL)
        raiz = raiz->dir;

    return raiz;
}
// Nesse codigo esta a resposta da 13,14,15
No* remover(No* raiz, int valor) {

    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);

    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);

    else {

        // Caso 1: folha
        if (raiz->esq == NULL && raiz->dir == NULL) {

            free(raiz);
            return NULL;
        }

        // Caso 2: um filho
        if (raiz->esq == NULL) {

            No* temp = raiz->dir;

            free(raiz);

            return temp;
        }

        if (raiz->dir == NULL) {

            No* temp = raiz->esq;

            free(raiz);

            return temp;
        }

        // Caso 3: dois filhos
        No* sucessor = menorValor(raiz->dir);

        raiz->valor = sucessor->valor;

        raiz->dir = remover(raiz->dir, sucessor->valor);
    }

    return raiz;
}
// 17. Verificar ABB
int verificarABB(No* raiz, int min, int max) {

    if (raiz == NULL)
        return 1;

    if (raiz->valor <= min || raiz->valor >= max)
        return 0;

    return verificarABB(raiz->esq, min, raiz->valor)
        &&
        verificarABB(raiz->dir, raiz->valor, max);
}

// Altura
int altura(No* raiz) {

    if (raiz == NULL)
        return -1;

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    return (esq > dir ? esq : dir) + 1;
}

// 18. Número de níveis
int niveis(No* raiz) {

    return altura(raiz) + 1;
}

int main() {

    No* raiz = NULL;

    int op, valor;

    do {

        printf("\n===== MENU ABB =====\n");
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir em ordem\n");
        printf("5 - Mostrar altura\n");
        printf("6 - Mostrar menor valor\n");
        printf("7 - Mostrar maior valor\n");
        printf("8 - Verificar ABB\n");
        printf("9 - Encerrar\n");

        scanf("%d", &op);

        switch(op) {

            case 1:

                printf("Valor: ");
                scanf("%d", &valor);

                raiz = inserir(raiz, valor);

                break;

            case 2:

                printf("Valor: ");
                scanf("%d", &valor);

                if(buscar(raiz, valor))
                    printf("Encontrado!\n");
                else
                    printf("Nao encontrado!\n");

                break;

            case 3:

                printf("Valor: ");
                scanf("%d", &valor);

                raiz = remover(raiz, valor);

                break;

            case 4:

                printf("Em ordem: ");

                emOrdem(raiz);

                printf("\n");

                break;

            case 5:

                printf("Altura: %d\n", altura(raiz));

                printf("Niveis: %d\n", niveis(raiz));

                break;

            case 6:

                if(raiz)
                    printf("Menor valor: %d\n",
                           menorValor(raiz)->valor);

                break;

            case 7:

                if(raiz)
                    printf("Maior valor: %d\n",
                           maiorValor(raiz)->valor);

                break;

            case 8:

                if(verificarABB(raiz, -999999, 999999))
                    printf("ABB valida\n");
                else
                    printf("Nao e ABB\n");

                break;

            case 9:

                printf("Encerrando...\n");

                break;
        }

    } while(op != 9);

    return 0;
}