#include <stdio.h>
#define SIZE 10
#define EMPTY '~'
#define DELETED '!'

typedef char CloseDict[SIZE];
typedef enum {TRUE, FALSE}bool;

void initDict(CloseDict C);
void display(CloseDict C);
void insert(CloseDict C, char new);
void delete(CloseDict C, char new);
bool search(CloseDict C, char elem);
int hash(char elem);

int main(){

    CloseDict C;
    initDict(C);
    insert(C, 'A');
    insert(C, 'B');
    insert(C, 'C');
    insert(C, 'A');
    insert(C, 'K');
    insert(C, 'O');
    insert(C, 'E');
    insert(C, 'T');
    display(C);

    printf("\n");
    delete(C, 'K');
    display(C);


}

void initDict(CloseDict C){

    int x; 

    for(x = 0; x < SIZE; x++){
        C[x] = EMPTY; 
    }

}
void display(CloseDict C){

    int x; 

    for(x = 0; x < SIZE; x++){
        printf("%d = %c\n", x, C[x]);
    }
}

void insert(CloseDict C, char new){

    int hashval = hash(new);
    int x; 
    int ctr = 0;

    for(x = (hashval)%SIZE; ctr < SIZE && C[x] != EMPTY && C[x] != DELETED; x = (x+1)%SIZE, ctr++){}

    C[x] = new;

}

void delete(CloseDict C, char new){

    int hashval = hash(new);
    int ctr = 0, x;

    if(C[hashval] != EMPTY && C[hashval] == new){
        C[hashval] = DELETED;
    }
    else{
        for(x = (hashval)%SIZE; ctr < SIZE && C[x] != new; x = (x+1)%SIZE, ctr++){}

        if(C[x] == new){
            C[x] = DELETED;
        }
        else{
            printf("ELEM %c NOT FOUND\n", new);
        }
    }

}

bool search(CloseDict C, char elem){

    int hashval = hash(elem);
    int x; 
    int ctr = 0;

    for(x = (hashval)%SIZE; ctr < SIZE && (C[x] != EMPTY && C[x] != DELETED) && C[x]==elem; x = (x+1)%SIZE, ctr++){}
    
    return(C[x]==elem)? TRUE: FALSE;
}

int hash(char elem){

    int x = elem % 10;

    return x; 
}