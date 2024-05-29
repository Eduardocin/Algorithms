#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int li;
    int ri;
    int index;
} Pessoa;

typedef struct node {
    Pessoa pessoa;
    struct node* next;
} Node;

typedef struct fila {
    int size;
    Node* front;
    Node* rear;
} Fila;

Node* create_node(Pessoa pessoa, Node* nextval) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->pessoa = pessoa;
    n->next = nextval;
    return n;
}

Fila* create_queue() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Fila* q, Pessoa pessoa) {
    Node* newNode = create_node(pessoa, NULL);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

Pessoa dequeue(Fila* q) {
    if (q->size == 0) exit(0);
    Node* temp = q->front;
    Pessoa it = temp->pessoa;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return it;
}

int isQueueEmpty(Fila* q) {
    return q->size == 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);

        Pessoa* pessoas = (Pessoa*)malloc(n * sizeof(Pessoa));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pessoas[i].li, &pessoas[i].ri);
            pessoas[i].index = i;
        }

        int atual = 1; // Inicializa o tempo atual como 1
        int* posicao = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            posicao[i] = 0;
        }

        Fila* fila = create_queue();

        for (int i = 0; i < n; i++) {
            enqueue(fila, pessoas[i]);
        }

        while (!isQueueEmpty(fila)) {
            Pessoa frontPessoa = dequeue(fila);

            if (atual < frontPessoa.li) {
                atual = frontPessoa.li;
            }

            if (atual <= frontPessoa.ri) {
                posicao[frontPessoa.index] = atual;
                atual++;
            } else {
                posicao[frontPessoa.index] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", posicao[i]);
        }
        printf("\n");

        free(fila);
        free(pessoas);
        free(posicao);
    }

    return 0;
}