#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct node{
    int data;
    struct node *next;
} *LIST, lType;

void initialize(LIST *L);
void insertFirst(LIST *L, int elem);
void insertLast(LIST *L, int elem);
void insertSorted(LIST *L, int elem); /* Let the list be sorted by ascending order. Insert the element in the proper order */
LIST retrieve(LIST L, int position); /* return the node on the specified position on the list. If not found, return the last element */
LIST deleteNode(LIST *L, int elem); /* return the node of the deleted element. If element is not found, return NULL */
void deleteFirstOccur(LIST *A, char new);

int main(){


}

void initialize(LIST *L){

    (*L) = NULL;

}

void insertFirst(LIST *L, int elem){

    LIST temp, *trav;
    temp = malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = (*L);
    (*L) = temp; 
}

void insertLast(LIST *L, int elem){
    LIST temp, *trav;

    for (trav = L; (*trav) != NULL; trav = &(*trav)->next){}

    temp = (LIST)malloc(sizeof(lType));

    if(temp!=NULL){
        temp->data = elem; 
        temp->next =*trav;

        *trav = temp;
    }

}

void insertSorted(LIST *L, int elem){
    LIST temp, *trav;
    temp = (LIST)malloc(sizeof(lType));

    for (trav = L; (*trav) != NULL && (*trav)->data < elem; trav = &(*trav)->next){}

    if(temp!=NULL){
        temp->data = elem; 
        temp->next =*trav;

        *trav = temp;
    }

}

LIST retrieve(LIST L, int elem){
    LIST trav;
    LIST occur;

    //single occur
    for (trav = L; trav != NULL && trav->data != elem; trav = trav->next){}
    return (trav != NULL) ? trav : NULL;

    //multiple occur
    for (trav = L; trav != NULL; trav = trav->next){
        if(trav->data == elem){
            occur = trav;
        }
    }
    return occur; 
}

void deleteFirstOccur(LIST *A, char new){
	
	LIST *trav, temp;
	

	if((*A)!=NULL){
		for(trav = *A; trav != NULL && (*trav)->next->data != new; trav = (*A)->next){}
			
			temp = (*trav);
			(*trav)->next = temp->next->next;
		}		
	
}