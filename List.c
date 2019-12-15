//
// Created by iogos on 13/12/2019.
//

#include "List.h"

void push_in(node** head, int data){
    node *n1 = malloc(sizeof(node));
    n1->data = data;
    n1->next = *head;
    *head = n1;

    //return n1;
}

void pop_out(node** head){
    node* aux = *head;

    *head = aux->next;

    free(aux);
}

void append(node** head, int data){
    node* n1 = malloc(sizeof(node));
    node *temp = *head;

    n1->data = data;
    n1->next = NULL;

    if(temp == NULL){
        *head = n1;
    }else{
        while(temp != NULL){
            if(temp->next == NULL){
                temp->next = n1;
                break;
            }
            temp = temp->next;
        }
    }

}

int rmv_node(node** head, int data){
    node* toBeRmv = find_node(*head, data);
    node* temp2 = *head;

    if(toBeRmv == NULL)
        return 0;

    while(temp2->next != toBeRmv){
        temp2 = temp2->next;
    }

    temp2->next = toBeRmv->next;

    free(toBeRmv);

    return 1;

}

void printList(node* head){
    node* temp = head;

    while(temp != NULL){
        printf("%d-", temp->data);
        temp = temp->next;
    }
}

node* find_node(node* head, int data){
    node* temp = head;

    while(temp->next != NULL){
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }

    return NULL;
}
void invert_list(node** head){
    node* previous = NULL;
    node* current;
    node* next = NULL;

    current = *head;

    while(current != NULL){
        next = current->next;

        current->next = previous;

        previous = current;
        current = next;
    }

    *head = previous;

    //return head;
}

node* invert_list_stack(node* head){
    node* current = head;
    node* temp = NULL;

    while(current != NULL){
        node* aux = malloc(sizeof(node));
        aux->data = current->data;
        aux->next = temp;
        temp = aux;
        current = current->next;
    }

    //*head = temp;

    return temp;
}

void clear(node** head){
    node* temp = *head;
    node* aux = NULL;

    while(temp !=NULL){
        aux = temp;
        temp = temp->next;
        free(aux);
    }

    *head = NULL;

    //puts("Exluido com sucesso");
}
