#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char text;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    Node* curr;
} List;

Node* create_node(char text) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        exit(0);
    }
    n->text = text;
    n->next = NULL;
    return n;
}

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->curr = NULL;
    return list;
}

void insert(List* list, char text) {
    Node* newNode = create_node(text);

    if (list->curr == NULL) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->tail == NULL) {
            list->tail = newNode;
        }
        list->curr = newNode;
    } else {
        newNode->next = list->curr->next;
        list->curr->next = newNode;
        if (list->curr == list->tail) {
            list->tail = newNode;
        }
        list->curr = newNode;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void Text(char* c) {
    List* list = create_list();
    Node* home = NULL;

    int len = strlen(c);
    for (int i = 0; i < len; ++i) {
        if (c[i] == '[') {
            list->curr = NULL;
            home = NULL;
        } else if (c[i] == ']') {
            list->curr = list->tail;
        } else {
            if (list->curr == NULL && home != NULL) {
                list->curr = home;
            }
            insert(list, c[i]);
            if (list->curr == list->head) {
                home = list->curr;
            }
        }
    }

    Node* node = list->head;
    while (node != NULL) {
        printf("%c", node->text);
        node = node->next;
    }

    freeList(list->head);
    free(list);
}

int main() {
    char line[100001];
    while (scanf("%s", line)!= EOF) {
        Text(line);
        printf("\n");
    }

    return 0;
}