#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char nome[50];
    int identificador;
    char outras_caracteristicas[100];
} Aviao;

typedef struct {
    Aviao* elementos;
    int capacidade;
    int topo;
} Pilha;

Pilha* criar_pilha(int capacidade);
void destruir_pilha(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
int pilha_cheia(Pilha* pilha);
void empilhar(Pilha* pilha, Aviao aviao);
Aviao desempilhar(Pilha* pilha);
Aviao topo_pilha(Pilha* pilha);

#endif
