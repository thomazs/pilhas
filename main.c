#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define wait(msg) printf("%s\nPressione algo para continuar...\n", msg);getch();

typedef struct TNo{
    int info;
    struct PNo *prox;
}No;

typedef struct TPilha{
    No *topo;
    int quantidade;
} Pilha;

void inicia_pilha(Pilha *p){
    p->topo = NULL;
    p->quantidade = 0;
}

No *inicia_no(int info){
    No *n = (No *)malloc(sizeof(No));
    n->prox = NULL;
    n->info = info;
    return n;
}

void push(Pilha *p, No *n){
    No *tmp=p->topo;
    p->topo = n;
    n->prox = tmp;
    p->quantidade += 1;
}

No *pop(Pilha *p){
    No *tmp = p->topo;
    if (tmp!=NULL){
        p->topo = tmp->prox;
        tmp->prox = NULL;
        p->quantidade -= 1;
    }
    return tmp;
}

void desempilha_imprime(Pilha *p){
    No *tmp;
    printf("Total de itens empilhados: %d\n", p->quantidade);
    while((tmp = pop(p))!=NULL){
        printf(" - %d\n", tmp->info);
        free(tmp);
    }
}

void clear(){
    int i=0;
    while(i++<50) printf("\n");
}

char menu(){
    char op=' ';
    clear();
    printf("\n\nMENU\n");
    printf("   [0] - Sair\n");
    printf("   [1] - Inserir na Pilha(push)\n");
    printf("   [2] - Desempilhar (pop)\n");
    printf("   [3] - Tamanho da Pilha\n");
    printf("   [4] - Desempilhar Tudo e Imprimir\n");
    printf("Sua escolha: ");
    while(strchr("01234", op)==NULL)
        op = getch();
    printf("%c\n", op);
    return op;
}

int main(){
    Pilha *pilha=(Pilha *)malloc(sizeof(Pilha));
    No *n;
    int valor;
    char op = ' ';
    inicia_pilha(pilha);
    while(op!='0'){
        op = menu();
        if (op == '1'){
            printf("\n\nValor a empilhar:");
            scanf("%d", &valor);
            push(pilha, inicia_no(valor));
            wait("Valor empilhado!");
        }else if (op == '2'){
            n = pop(pilha);
            if (n == NULL)
                printf("\n\nNada para desempilhar!\n");
            else
                printf("\n\nValor desempilhado: %d\n", n->info);
            wait("");
        }else if (op == '3'){
            printf("\n\nTamanho da pilha: %d\n", pilha->quantidade);
            wait("");
        }else if (op == '4'){
            desempilha_imprime(pilha);
            wait("");
        }
    }

    return 0;
}
