#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* prev;
    int key;
    struct Node* next;
} Node;

Node *nil;

Node *list_search(int key) {
    Node *cur = nil->next;
    while (cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}         

void node_init() {
    nil = (Node*)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

void print_list() {
    Node *cur = nil->next;
    int flag = 0;
    while (cur != nil) {
        if (flag++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
}

void delete_node(Node *n) {
    if (n == nil) return;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
}

void delete_first() {
    delete_node(nil->next);
}

void delete_last() {
    delete_node(nil->prev);
}

void delete_by_key(int key) {
    delete_node(list_search(key));
}

void insert(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->next = nil->next;
    nil->next->prev = n;
    nil->next = n;
    n->prev = nil;
}

int main(int argc, char const *argv[])
{
    node_init();
    int n = 0;
    int key;
    char com[20];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s%d", com, &key);
        if (com[0] == 'i') { insert(key); }
        else if (com[0] == 'd') { 
            if (strlen(com) > 6) {
                if (com[6] == 'F') { 
                    delete_first();
                } else {
                    delete_last();
                }
            } else {
                delete_by_key(key);
            }
        }
    }

    print_list();
    return 0;
}
