//
// Created by iogos on 13/12/2019.
//

#ifndef EDCLASS_LIST_H
#define EDCLASS_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push_in(node** head, int data);

void pop_out(node** head);

int rmv_node(node** head, int data);

void append(node** head, int data);

void printList(node* head);

node* find_node(node* head, int data);

void invert_list(node** head);

node* invert_list_stack(node* head);

void clear(node** head);



#endif //EDCLASS_LIST_H
