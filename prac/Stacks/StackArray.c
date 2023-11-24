#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct{
    char FN[25], LN[25], MI;
    int studID; 
    int year;
    char course[25];
}studRec;

typedef struct stack{
	studRec E[SIZE];
	int top;
}*Stack;

typedef enum {TRUE,FALSE}Boolean;

void initStack(Stack *S);
void Push(Stack *S, studRec x);
void Pop(Stack *S);
studRec Top(Stack S);
Boolean isFull(Stack S);
Boolean isEmpty(Stack S);

int main()
{
	Stack S;
 	initStack(&S);
 	int i;

	
	return 0;
}

void initStack(Stack *S){


    (*S) = (Stack)malloc(sizeof(struct stack));
    (*S)->top = SIZE-1;

}

void Push(Stack *S, studRec x){

    if(isFull(*S)){
		(*S)->E[--(*S)->top] = x;
	}
  
}

void Pop(Stack *S){

    if(!isEmpty(*S)){
        (*S)->top++;
    }
    
}

studRec Top(Stack S){

    return S->E[S->top];

}

Boolean isFull(Stack S){

    return (S->top == 0)? TRUE: FALSE;
}

Boolean isEmpty(Stack S){

    return (S->top == SIZE)? TRUE:FALSE;
}
