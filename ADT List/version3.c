// list is a structure containing a pointer to a dynamically allocated array and a variable count
// list L = [elemptr -> array, count]
// By Victorienne Tiu 
// Group 6 DSA 

#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct list
{
    int *elemPtr;
    int count;
} List;

List initList(List L);
List insertPos(List L, int new, int pos);
List deletePos(List L, int pos);
int retrieve(List L, int pos);
void display(List L);

int main()
{

    List L;
    int elem;
    initList(L);

    L.count = 4;

    L.elemPtr[0] = 12;
    L.elemPtr[1] = 3;
    L.elemPtr[2] = 4;
    L.elemPtr[3] = 1;

    display(L);
    // printf("\nbefore insertion ");
    // display(&L);

    printf("\nafter inserting index 2");
    insertPos(L, 99, 2);
    display(L);

    printf("\nafter deleting index 0");
    deletePos(L, 0);
    display(L);

    // elem = retrieve(&L, 2);
    printf("\nelement at position 1 is %d", elem = retrieve(L, 1));
    display(L);
}

List initList(List L)
{

    L.elemPtr = (int *)malloc(sizeof(int) * MAX);
    L.count = 0;

    return L;
}

List insertPos(List L, int new, int pos)
{

    int i;

    if (L.count < MAX)
    {

        for (i = L.count; i > pos; i--)
        {
            L.elemPtr[i] = L.elemPtr[i - 1];
        }

        L.elemPtr[pos] = new;
        (L.count)++;
    }

    return L;
}

List deletePos(List L, int pos)
{

    int i;

    if (L.count < MAX)
    {

        for (i = pos; i < L.count; i++)
        {
            L.elemPtr[i] = L.elemPtr[i + 1];
        }

        L.count--;
    }

    return L;
}

int retrieve(List L, int pos)
{

    return (L.count > 0 && L.count > pos) ? L.elemPtr[pos] : -1;
}

void display(List L)
{

    printf("\nList: ");
    for (int i = 0; i < L.count; i++)
    {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}