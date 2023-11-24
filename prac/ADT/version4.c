#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct studRec{
    char FN[25], LN[25], MI;
    char course[25];
    int year;
    int studID; 
}*studRec, studRecord;

typedef struct studList{
    studRec ElemPtr; 
    int count;
}*studList, studentLists; 

void initList(studList *L);
void insertFirst(studList *L, studRecord new);
void insertLast(studList *L, studRecord new);
void insertSorted(studList *L, studRecord new);
void deleteFirst(studList *L);
void deleteLast(studList *L);
void deletePos(studList *L, int pos);
studRecord *retrieve(studList L, int pos);
void display(studList L);

int main(){

    studList L; 
    FILE *fp;
    studList buffer;

    int x;

    initList(&L);
    fp = fopen("STUDREC.dat", "wb+");

    if(fp == NULL){
        printf("ERROR WRITING FILE");
        return 1;
    }

    studRecord S[]={
					{"Victorienne", "Tiu", 'C', "BSCS", 2, 2},
					{"Rev Pollux", "Martinez", 'B', "BSCS", 2, 3},
					{"Mary Chevel", "Modesto", 'P', "BSCS", 2, 1},
					{"Estelito", "Buenavista", 'Y', "BSCS", 2, 5},
				};
    studRecord new[] = {{"Bryan Ignatius", "Sanchez", 'P', "BSPHY", 3, 4}};

    insertFirst(&L, S[0]);
    display(L);

    insertLast(&L, S[3]);
    display(L);

    insertSorted(&L, S[1]);
    display(L);

    insertFirst(&L, S[2]);
    display(L);
    
    // fwrite(&L, sizeof(struct studList), 1, fp);
    // rewind(fp);
    // fread(&buffer, sizeof(struct studList), 1, fp);

    // printf("FROM FILE:::");
    // display(buffer);
    // rewind(fp);

    // printf("NRUIJJJJJJJJJ");
    // fclose(fp);

    // fp = fopen("STUDREC.dat", "wb+");

    deleteFirst(&L);
    
    insertSorted(&L, new[0]);

    deleteLast(&L);

    insertSorted(&L, S[3]);

    deletePos(&L, 2);

    fwrite(&L, sizeof(struct studList), 1, fp);
    rewind(fp);
    fread(&buffer, sizeof(struct studList), 1, fp);

    printf("FROM FILE:::");
    display(buffer);

    studRecord* arr;
    arr = (studRecord*)retrieve(L, 1);
    printf("LN of student at index 2: %s", arr->LN);
    
    free(L);
}

void initList(studList *L){

    (*L) = (studList)malloc(sizeof(struct studList));
    (*L)->count = 0;

    studRec arr = (studRec)malloc(sizeof(studRecord)*MAX);
    (*L)->ElemPtr = arr;

}
void insertFirst(studList *L, studRecord new){

    int y; 
    if((*L)->count < MAX){

        for(y = (*L)->count; y >= 0; y--){
            (*L)->ElemPtr[y].studID = (*L)->ElemPtr[y-1].studID;
            strcpy((*L)->ElemPtr[y].FN, (*L)->ElemPtr[y-1].FN);
            strcpy((*L)->ElemPtr[y].LN, (*L)->ElemPtr[y-1].LN);
            strcpy((*L)->ElemPtr[y].course, (*L)->ElemPtr[y-1].course);
            (*L)->ElemPtr[y].MI = (*L)->ElemPtr[y-1].MI;
            (*L)->ElemPtr[y].year = (*L)->ElemPtr[y-1].year;
        }

        (*L)->ElemPtr[0].studID = new.studID;
        strcpy((*L)->ElemPtr[0].FN, new.FN);
        strcpy((*L)->ElemPtr[0].LN, new.LN);
        strcpy((*L)->ElemPtr[0].course, new.course);
        (*L)->ElemPtr[0].MI = new.MI;
        (*L)->ElemPtr[0].year = new.year;

        (*L)->count++;
    }
}

void insertLast(studList *L, studRecord new){

    int last; 

    if((*L)->count < MAX){
        last = (*L)->count++;
        (*L)->ElemPtr[last].studID = new.studID;
        strcpy((*L)->ElemPtr[last].FN, new.FN);
        strcpy((*L)->ElemPtr[last].LN, new.LN);
        strcpy((*L)->ElemPtr[last].course, new.course);
        (*L)->ElemPtr[last].MI = new.MI; 
        (*L)->ElemPtr[last].year = new.year;
    }
}

void insertSorted(studList *L, studRecord new){

    int x, y; 
    
    if((*L)->count < MAX){

        for(x = 0; x < (*L)->count && new.studID > (*L)->ElemPtr[x].studID; x++){}
        
        for(y = (*L)->count; y > x; y--){
            (*L)->ElemPtr[y].studID = (*L)->ElemPtr[y-1].studID;
            strcpy((*L)->ElemPtr[y].FN, (*L)->ElemPtr[y-1].FN);
            strcpy((*L)->ElemPtr[y].LN, (*L)->ElemPtr[y-1].LN);
            strcpy((*L)->ElemPtr[y].course, (*L)->ElemPtr[y-1].course);
            (*L)->ElemPtr[y].MI = (*L)->ElemPtr[y-1].MI;
            (*L)->ElemPtr[y].year = (*L)->ElemPtr[y-1].year;
        }

        (*L)->ElemPtr[x].studID = new.studID;
        strcpy((*L)->ElemPtr[x].FN, new.FN);
        strcpy((*L)->ElemPtr[x].LN, new.LN);
        strcpy((*L)->ElemPtr[x].course, new.course);
        (*L)->ElemPtr[x].MI = new.MI;
        (*L)->ElemPtr[x].year = new.year;

        (*L)->count++;

    }
}

void deleteFirst(studList *L){

    int y; 

    for(y = 1; y < (*L)->count; y++){
        (*L)->ElemPtr[y-1].studID = (*L)->ElemPtr[y].studID;
        strcpy((*L)->ElemPtr[y-1].FN, (*L)->ElemPtr[y].FN);
        strcpy((*L)->ElemPtr[y-1].LN, (*L)->ElemPtr[y].LN);
        strcpy((*L)->ElemPtr[y-1].course, (*L)->ElemPtr[y].course);
        (*L)->ElemPtr[y-1].MI = (*L)->ElemPtr[y].MI;
        (*L)->ElemPtr[y-1].year = (*L)->ElemPtr[y].year;
    }
    
    (*L)->count--;
}
void deleteLast(studList *L){
    
    (*L)->count--;
}

void deletePos(studList *L, int pos){

    int y; 

    for(y = pos+1; y < (*L)->count; y++){
        (*L)->ElemPtr[y-1].studID = (*L)->ElemPtr[y].studID;
        strcpy((*L)->ElemPtr[y-1].FN, (*L)->ElemPtr[y].FN);
        strcpy((*L)->ElemPtr[y-1].LN, (*L)->ElemPtr[y].LN);
        strcpy((*L)->ElemPtr[y-1].course, (*L)->ElemPtr[y].course);
        (*L)->ElemPtr[y-1].MI = (*L)->ElemPtr[y].MI;
        (*L)->ElemPtr[y-1].year = (*L)->ElemPtr[y].year;
    }
(*L)->count--;
}

studRecord *retrieve(studList L, int pos){

    studRecord *new = (studRecord*)malloc(sizeof(studRecord));

    new->studID = L->ElemPtr[pos].studID;
    new->MI = L->ElemPtr[pos].MI;
    new->year = L->ElemPtr[pos].year;

    strcpy(new->FN, L->ElemPtr[pos].FN);
    strcpy(new->LN, L->ElemPtr[pos].LN);
    strcpy(new->course, L->ElemPtr[pos].course);

    return new; 

}

void display(studList L){

    int y; 
    printf("\nCOUNT= %d\n",  L->count);
    for(y = 0; y < L->count; y++){
        printf("%d \t%d\t%s %c %s\t%s\t%d\n", y,L->ElemPtr[y].studID, L->ElemPtr[y].FN, L->ElemPtr[y].MI, L->ElemPtr[y].LN, L->ElemPtr[y].course, L->ElemPtr[y].year);
    }
}