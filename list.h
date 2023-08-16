#ifndef _LIST_H_
#define _LIST_H_

typedef int data_type;

typedef struct Node
{
    data_type value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *last;
    int size;
} List;

Node *node_construct(Node *next, Node *prev, data_type data);

List *list_construct();

int isEmpty(List *l);

// insere um elemento ao final 
void list_push_back(List *l, data_type data);

void list_push_front(List *l, data_type data);

// remove e retorna o último elemento
data_type list_pop_back(List *l);

data_type list_pop_front(List *l);

void list_destroy(List *l);

#endif