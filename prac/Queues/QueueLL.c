#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char FN[25], LN[25], MI;
    int studID; 
    int year;
    char course[25];
}studRec;

typedef struct nodeType{
	studRec elem;
	struct nodeType *next;
}*nodePtr;

typedef struct{
	nodePtr front, rear;
}Queue;

void initQueue(Queue *Q);
void Display(Queue Q);
void Enqueue(Queue *Q, studRec x);
void Dequeue(Queue *Q);
studRec Front(Queue Q);

int main()
{
	
	return 0;
}

void initQueue(Queue *Q){

    Q->front = NULL; 
    Q->rear = NULL; 
}

void Display(Queue Q);

void Enqueue(Queue *Q, studRec x){

    nodePtr new = (nodePtr)malloc(sizeof(struct nodeType));

    if(new != NULL){
        new->elem = x;
        new->next = NULL; 

        if(Q->front == NULL){
            Q->front = new;
            Q->rear = new; 
        }else{
            Q->rear->next = new;
            Q->rear = new; 
        }
    }

}
void Dequeue(Queue *Q){

    nodePtr *trav = Q->front;

    if(Q->front != NULL){
        trav = Q->front;
        Q->front = Q->front->next;

        free(trav);
    }
}

studRec Front(Queue Q){

    studRec x; 

    x = Q.front->elem;

    return x; 
}
