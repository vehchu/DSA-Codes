#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct{
    char FN[25], LN[25], MI;
    int studID; 
    int year;
    char course[25];
}studRec;

typedef struct studList{
    studRec students[MAX];
    int count;
}*studList; 

void initList(studList *L);
void insertFirst(studList*L, studRec new);
void insertLast(studList *L, studRec new);
void insertPos(studList *L, studRec new, int pos);
void deleteFirst(studList *L);
void deleteLast(studList *L);
void deletePos(studList *L, int pos);
studRec *retrieve(studList L, int pos);
void display(studList L);

int main(){

    studList L; 
    initList(&L);

    studRec s1, s2, s3, s4, s5;

    strcpy(s1.FN, "Rev");
    strcpy(s1.LN, "Martinez");
    s1.MI = 'B';
    strcpy(s1.course, "BS CS");
    s1.studID = 001;
    s1.year = 2;

    strcpy(s2.FN, "Victorienne");
    strcpy(s2.LN, "Tiu");
    s2.MI = 'C';
    s2.studID = 2;
    s2.year = 2;
    strcpy(s2.course, "BS CS");

    strcpy(s3.FN, "Mary");
    strcpy(s3.LN, "Modesto");
    s3.MI = 'C';
    s3.studID = 3;
    s3.year = 2;
    strcpy(s3.course, "BS IT");

    strcpy(s4.FN, "Bryan");
    strcpy(s4.LN, "Sanchez");
    s4.MI = 'C';
    s4.studID = 4;
    s4.year = 2;
    strcpy(s4.course, "BS CS");

    strcpy(s5.FN, "Lawrence");
    strcpy(s5.LN, "Tulod");
    s5.MI = 'C';
    s5.studID = 5;
    s5.year = 2;
    strcpy(s5.course, "BS IT");

    insertFirst(&L, s1);
    display(L);

    insertLast(&L, s3);
    display(L);

    insertPos(&L, s2, 1);
    display(L);

    insertLast(&L, s4);
    display(L);
    // deletePos(&L, 4);
    // display(L);

    // deleteFirst(&L);
    // display(L);
    // insertFirst(&L, s1);
    // display(L);

    // deleteLast(&L);
    // display(L);

    studRec *a;
    a = (studRec *)retrieve(L, 2);
    printf("%s", a->FN);

    free(L);
    free(a);

}

void initList(studList *L){
    *L = (studList)malloc(sizeof(struct studList));
    (*L)->count = 0;

}

void insertFirst(studList *L, studRec new){

    int x; 
    (*L)->count++;
    int ctr = (*L)->count;

    if(ctr < MAX){
        for(x = ctr; x > 0; x--){
            strcpy((*L)->students[x].FN, (*L)->students[x-1].FN);
            strcpy((*L)->students[x].LN, (*L)->students[x-1].LN);
            strcpy((*L)->students[x].course, (*L)->students[x-1].course);
            (*L)->students[x].year = (*L)->students[x-1].year;
            (*L)->students[x].MI = (*L)->students[x-1].MI;
            (*L)->students[x].studID = (*L)->students[x-1].studID;
        }
    }
    
    strcpy((*L)->students[0].FN, new.FN);
    strcpy((*L)->students[0].LN, new.LN);
    strcpy((*L)->students[0].course, new.course);
    (*L)->students[0].year = new.year;
    (*L)->students[0].MI = new.MI;
    (*L)->students[0].studID = new.studID;

}

void insertLast(studList *L, studRec new){

    if((*L)->count <= MAX){
        int ctr = (*L)->count++;
        //printf("CT:%d", ctr);
        strcpy((*L)->students[ctr].FN, new.FN);
        strcpy((*L)->students[ctr].LN, new.LN);
        strcpy((*L)->students[ctr].course, new.course);
        (*L)->students[ctr].year = new.year;
        (*L)->students[ctr].MI = new.MI;
        (*L)->students[ctr].studID = new.studID;
       // printf("\n%d\n", ctr);
    }

}

void insertPos(studList *L, studRec new, int pos){

    int x; 
    (*L)->count++;
    int ctr = (*L)->count;

    if((*L)->count < MAX ){
        for(x = ctr; x > pos; x--){
            strcpy((*L)->students[x].FN, (*L)->students[x-1].FN);
            strcpy((*L)->students[x].LN, (*L)->students[x-1].LN);
            strcpy((*L)->students[x].course, (*L)->students[x-1].course);
            (*L)->students[x].year = (*L)->students[x-1].year;
            (*L)->students[x].MI = (*L)->students[x-1].MI;
            (*L)->students[x].studID = (*L)->students[x-1].studID;
        }
    }
    
        strcpy((*L)->students[pos].FN, new.FN);
        strcpy((*L)->students[pos].LN, new.LN);
        strcpy((*L)->students[pos].course, new.course);
        (*L)->students[pos].year = new.year;
        (*L)->students[pos].MI = new.MI;
        (*L)->students[pos].studID = new.studID;
    

}

void deleteFirst(studList *L){

    int x; 
    int ctr = (*L)->count;

    if((*L)->count != 0){
        for(x = 0; x < ctr; x++){
            strcpy((*L)->students[x].FN, (*L)->students[x+1].FN);
            strcpy((*L)->students[x].LN, (*L)->students[x+1].LN);
            strcpy((*L)->students[x].course, (*L)->students[x+1].course);
            (*L)->students[x].year = (*L)->students[x+1].year;
            (*L)->students[x].MI = (*L)->students[x+1].MI;
            (*L)->students[x].studID = (*L)->students[x+1].studID;
        }
    }

    (*L)->count--;

}

void deleteLast(studList *L){

    (*L)->count--;

}

void deletePos(studList *L, int pos){

    int x; 
    
    if((*L)->count < MAX){
        for(x = pos+1; x < MAX -1; x++){
            strcpy((*L)->students[x-1].FN, (*L)->students[x].FN);
            strcpy((*L)->students[x-1].LN, (*L)->students[x].LN);
            strcpy((*L)->students[x-1].course, (*L)->students[x].course);
            (*L)->students[x-1].year = (*L)->students[x].year;
            (*L)->students[x-1].MI = (*L)->students[x].MI;
            (*L)->students[x-1].studID = (*L)->students[x].studID;
        }
    }
    (*L)->count--;
}

studRec *retrieve(studList L, int pos){

    studRec *new = (studRec*)malloc(sizeof(studRec));

    if(new != NULL){

        if((L)->count >= pos){
            new->year = L->students[pos].year;
            strcpy(new->FN, (L)->students[pos].FN);
            strcpy(new->LN, (L)->students[pos].LN);
            strcpy(new->course, (L)->students[pos].course);
            new->MI = L->students[pos].MI;
            new->year = (L)->students[pos].studID;
        }

    }

    return new; 
}

void display(studList L){

    int x; 
    printf("\nCOUNT = %d\n", L->count);

    for(x = 0; x < L->count; x++){
        printf("%d\t%d\t%15s %c %-10s\t%10s\t%d\n", x, L->students[x].studID,
        L->students[x].FN, L->students[x].MI, L->students[x].LN, L->students[x].course, L->students[x].year );
    }

}