// List L is a pointer to a struct (dynamically allocated) that contains a pointer to a dynamically allocated array and variable count
// By Victorienne Tiu 
// Group 6 DSA 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

typedef struct list
{
    int *elemPtr;
    int count;
} ListRef, *List;

void initList(List *L);
void insertPos(List *L, int new, int pos);
void deletePos(List *L, int pos);
int retrieve(List *L, int pos);
void display(List *L);

int main()
{

    List L;
    int elem;
    initList(&L);

    L->count = 4;
    L->elemPtr[0] = 12;
    L->elemPtr[1] = 3;
    L->elemPtr[2] = 4;
    L->elemPtr[3] = 1;

    printf("\nbefore insertion ");
    display(&L);

    printf("\nafter inserting index 2");
    insertPos(&L, 99, 2);
    display(&L);

    printf("\nafter deleting index 0");
    deletePos(&L, 0);
    display(&L);

    // elem = retrieve(&L, 2);
    printf("\nelement at position 2 is %d", elem = retrieve(&L, 2));
}

void initList(List *L)
{

    *L = (List)malloc(sizeof(ListRef));

    if (*L != NULL)
    {
        (*L)->elemPtr = (int*)malloc(sizeof(int)*MAX);
        (*L)->count = 0;
    }
}

void insertPos(List *L, int new, int pos)
{

    int i;

    if ((*L)->count < MAX)
    {

        for (i = (*L)->count; i > pos; i--)
        {
            (*L)->elemPtr[i] = (*L)->elemPtr[i - 1];
        }

        (*L)->elemPtr[pos] = new;
        (*L)->count++;
    }
}

void deletePos(List *L, int pos)
{

    int i;

    if ((*L)->count > 0)
    {

        for (i = pos; i < (*L)->count; i++)
        {
            (*L)->elemPtr[i] = (*L)->elemPtr[i + 1];
        }

        (*L)->count--;
    }
}

int retrieve(List *L, int pos)
{

    return ((*L)->count > 0 && (*L)->count > pos) ? (*L)->elemPtr[pos] : 0;
}

void display(List *L)
{
    printf("\nList: ");
    for (int i = 0; i < (*L)->count; i++)
    {
        printf("%d ", (*L)->elemPtr[i]);
    }
    printf("\n");
}