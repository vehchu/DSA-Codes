// By Victorienne Tiu 
// Group 6 DSA 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

typedef struct list
{
    int data[MAX];
    int count;
} ListRef, *List;

void initList(List *L);
void insertPos(List *L, int new, int pos);
void deletePost(List *L, int pos);
int retrieve(List *L, int pos);
void display(List *L);

int main()
{

    List L;
    int elem;
    initList(&L);

    L->count = 4;
    L->data[0] = 12;
    L->data[1] = 3;
    L->data[2] = 4;
    L->data[3] = 1;

    printf("\nbefore insertion ");
    display(&L);

    printf("\nafter inserting index 2");
    insertPos(&L, 99, 2);
    display(&L);

    printf("\nafter deleting index 1");
    deletePost(&L, 1);
    display(&L);

    // elem = retrieve(&L, 2);
    printf("\nelement at position 1 is %d", elem = retrieve(&L, 1));
}

void initList(List *L)
{

    *L = (List)malloc(sizeof(ListRef));

    if (*L != NULL)
    {
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
            (*L)->data[i] = (*L)->data[i - 1];
        }

        (*L)->data[pos] = new;
        (*L)->count++;
    }
}

void deletePost(List *L, int pos)
{

    int i;

    if ((*L)->count > 0)
    {

        for (i = pos; i < (*L)->count; i++)
        {
            (*L)->data[i] = (*L)->data[i + 1];
        }

        (*L)->count--;
    }
}

int retrieve(List *L, int pos)
{

    return ((*L)->count > 0 && (*L)->count > pos) ? (*L)->data[pos] : 0;
}

void display(List *L)
{
    printf("\nList: ");
    for (int i = 0; i < (*L)->count; i++)
    {
        printf("%d ", (*L)->data[i]);
    }
    printf("\n");
}