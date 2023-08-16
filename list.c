#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Node *node_construct(Node *next, Node *prev, data_type data){

    Node *node = (Node*) malloc(sizeof(Node));
    
    node->next = next;
    node->prev = prev;
    node->value = data;

    return node;
}

List *list_construct(){

    List *list = (List*) malloc(sizeof(List));

    list->head = NULL;
    list->last = NULL;
    list->size = 0;
    
    return list;
}

int isEmpty(List *l){
    return l->size == 0;
}

void list_push_back(List *l, data_type data){

    if(isEmpty(l))
        l->last = l->head = node_construct(NULL, NULL, data);
    else
        l->last = l->last->next = node_construct(NULL, l->last, data);
        
    l->size++;
}

void list_push_front(List *l, data_type data){

    if(isEmpty(l))
        l->last = l->head = node_construct(NULL, NULL, data);
    else
        l->head = l->head->prev = node_construct(l->head, NULL, data);
        
    l->size++;
}

data_type list_pop_back(List *l){

        if(l->size == 1){
        data_type data = l->last->value;
        free(l->last);
        l->head = l->last = NULL;
        l->size--;
        return data;
    }
    
    data_type data = l->last->value;
    Node *aux = l->last;

    l->last = l->last->prev;
    l->last->next = NULL;

    l->size--;
    free(aux);
    return data;
}

data_type list_pop_front(List *l){

    if(l->size == 1){
        data_type data = l->head->value;
        free(l->head);
        l->head = l->last = NULL;
        l->size--;
        return data;
    }
    
    data_type data = l->head->value;
    Node *aux = l->head;

    l->head = l->head->next;
    l->last->prev = NULL;

    l->size--;
    free(aux);
    return data;
}

void list_destroy(List *l){    
    free(l);
}