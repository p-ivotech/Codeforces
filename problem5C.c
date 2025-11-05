#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000000

typedef struct Pilha{
    int * S;
    int topo;
    int tamanho;
}Pilha;

void imprimir_pilha(Pilha * pilha){
    printf("\n");
    for(int i=pilha->topo; i > -1; i = i -1){
        printf("\t %d\n",pilha->S[i]);
    }
    printf("\n");
}
Pilha * criar_pilha(int tam){
    Pilha * nova = malloc(sizeof(Pilha));
    nova->S = malloc(tam * sizeof(int));
    nova->topo = -1;
    nova->tamanho = tam;
    return nova;
}

// opção 1
bool tem_espaco(Pilha * pilha){
    if(pilha->topo == pilha->tamanho -1){
        return false;
    }
    else{
        return true;
    }
}
//opção 2
bool tem_espaco_v2(Pilha * pilha){
    return !(pilha->topo == pilha->tamanho-1);
}


void empurrar(Pilha * pilha, int x){
    if(tem_espaco(pilha)){
        pilha->topo = pilha->topo +1;// pilha->topo++;
        pilha->S[pilha->topo] = x;
    }
    else{
        printf("Sem espaço na pilha \n");
    }
}

bool esta_vazia(Pilha * pilha){
    if(pilha->topo==-1) return true;
    else return false;
}

int pocar(Pilha * pilha){
    if(!esta_vazia(pilha)){
        pilha->topo = pilha->topo-1;
        return pilha->S[pilha->topo+1];
    }
    else{
        printf("Pilha vazia! ");
    }
}

int main() {
    char s[MAX];
    scanf("%s", s);
    int n = strlen(s);

    Pilha *pilha = criar_pilha(n);
    int *dp = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
        }

    int maxLen = 0;
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            empurrar(pilha, i);
        } else {
            if (!esta_vazia(pilha)) {
                int j = pocar(pilha); 
                int len = i - j + 1;
                if (j > 0)
                    len += dp[j - 1];

                dp[i] = len;

                if (len > maxLen) {
                    maxLen = len;
                    count = 1;
                } else if (len == maxLen) {
                    count++;
                }
            }
        }
    }

        if (maxLen == 0)
            printf("0 1\n");
        else
            printf("%d %d\n", maxLen, count);


    return 0;
}