#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY '~'
#define DELETED '!'

typedef char String[20];

typedef struct
{
    String fName;
    char mName;
    String lName;
} StudName;

typedef struct
{
    int id;
    StudName name;
} Student;

typedef struct node
{
    Student elem;
    struct node *next;
} *NODE;

typedef NODE Dictionary[SIZE];

typedef enum {TRUE,FALSE} bool;

void initDict(Dictionary C);
void display(Dictionary C);
void insert(Dictionary C, Student new);
void delete(Dictionary C, Student new);
bool search(Dictionary C, Student elem);
int hash(String elem);

int main()
{
    Dictionary Dict;
    initDict(Dict);

    int x, hashval;

    Student new[] = 
    {   {123424, {"Victorienne", 'C', "Tiu"}},
        {134545, {"Victorine", 'C', "BRUH"}},
        {324523, {"Rev Pollux", 'B', "Martinez"}},
   ko
    };

    
    for(x = 0; x < 5; x++){
        insert(Dict, new[x]);
    }
    delete(Dict, new[1]);
    display(Dict);
}

void initDict(Dictionary C)
{

    int x;
    for (x = 0; x < SIZE; x++)
    {
        C[x] = NULL;
    }
}

void display(Dictionary C)
{
    int x;
    NODE *trav;
    for (x = 0; x < SIZE; x++)
    {
        if(C[x]==NULL){
            printf("\nBUCKET %d EMPTY\n", x);
        }
        else{
        printf("\n-----BUCKET %d-----", x);
        for (trav = &C[x]; *trav != NULL; trav = &(*trav)->next)
        {
            printf("\n%d %s %c %s", (*trav)->elem.id, (*trav)->elem.name.fName, (*trav)->elem.name.mName, (*trav)->elem.name.lName);
        }
        printf("\n");
        }
    }
   
}

void insert(Dictionary C, Student new)
{

    int hashval = hash(new.name.fName);
    printf("RAHHH=%d %s\n", hashval, new.name.fName);

    NODE *trav = &C[hashval];
    NODE temp = malloc(sizeof(struct node)); 
    
    for(; *trav != NULL; trav = &(*trav)->next){}
    
    if(trav != NULL){
        temp->elem = new;
        temp->next = (*trav);
        *trav = temp; 
    }

}

void delete(Dictionary C, Student new){

    int hv = hash(new.name.fName);

    NODE *trav = &C[hv];
    NODE temp = malloc(sizeof(struct node));

    for(; *trav != NULL && (*trav)->elem.id != new.id; trav = &(*trav)->next){}

    if(*trav != NULL && (*trav)->elem.id == new.id){
        temp = (*trav); 
        (*trav) = (*trav)->next;
        free(temp);
    }    

}

bool search(Dictionary C, Student elem){

    int hv = hash(elem.name.fName);

    NODE *trav = &C[hv];
    NODE temp = malloc(sizeof(struct node));

    for(; *trav != NULL && (*trav)->elem.id != elem.id; trav = &(*trav)->next){}

    return ((*trav)->elem.id == elem.id)? TRUE:FALSE; 

}

int hash(String elem){

    char x = elem[0];  

    //printf("breh:%d\n", x);

    return  x % SIZE;
}