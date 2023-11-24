#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct studRec{
    char FN[25], LN[25], MI;
    char course[25];
    int year;
    int studID; 
}studRec;

typedef struct{
    studRec student;
    int next; 
}studentList; 

typedef struct{
    studentList Nodes[MAX];
    int avail; /* kast availavble node*/
}VirtualHeap; 

typedef int List; 

void display(VirtualHeap VH, List L);
void initializeVH(VirtualHeap *VH);
void insertLast(VirtualHeap *VH, List *L, studRec new);
void addNode(VirtualHeap *VH, List *L, studRec new);
void freeNode(VirtualHeap *VH, List *L);

int main(){

    VirtualHeap VH; 
    List L = -1;

    initializeVH(&VH);

    studRec s1, s2, s3, s4, s5;

    strcpy(s1.FN, "Rev");
    strcpy(s1.LN, "Martinez");
    s1.MI = 'B';
    strcpy(s1.course, "BS CS");
    s1.studID = 1;
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

    insertLast(&VH, &L, s1);
    //display(VH, L);

    insertLast(&VH, &L, s3);
    insertLast(&VH, &L, s2);
    insertLast(&VH, &L, s5);

    //display(VH, L);

    addNode(&VH, &L, s4);
   
    freeNode(&VH, &L); display(VH, L);
}


void initializeVH(VirtualHeap *VH){

    int x; 
    int LIM = MAX-1;

    for(x = 1; x <= LIM; x++){
        (*VH).Nodes[x-1].next = x;
    }

     (*VH).Nodes[LIM].next = -1;

     (*VH).avail = 0; //set first available node to first
    

}

void display(VirtualHeap VH, List L){

    int x = L;

    if( x != -1 ){

        for(; x != -1 ; x = VH.Nodes[x].next){
             printf("%-3d %s %-2c %s \t\t%-5s %10d \tLINK = %d\n", 
                VH.Nodes[x].student.studID,
                VH.Nodes[x].student.FN, 
                VH.Nodes[x].student.MI, 
                VH.Nodes[x].student.LN, 
                VH.Nodes[x].student.course, 
                VH.Nodes[x].student.year, 
                x);
        }

    }
    else{
        printf("FULL");
    }


}

void insertLast(VirtualHeap *VH, List *L, studRec new){

    int *x = L; 
    int temp = (*VH).avail;

    for(; *x != -1 ; x = &(*VH).Nodes[*x].next){}

    if((*VH).avail != -1  && *x == -1){
        (*VH).Nodes[temp].student.MI = new.MI;
        (*VH).Nodes[temp].student.studID = new.studID;
        (*VH).Nodes[temp].student.year = new.year;
        strcpy((*VH).Nodes[temp].student.FN, new.FN);
        strcpy((*VH).Nodes[temp].student.LN, new.LN);
        strcpy((*VH).Nodes[temp].student.course, new.course);

        (*VH).avail = (*VH).Nodes[(*VH).avail].next;
        (*VH).Nodes[temp].next = *x;
        *x = temp;
        
    }

}
void addNode(VirtualHeap *VH, List *L, studRec new){

    List temp;

    temp = VH->avail;

    (*VH).Nodes[temp].student.MI = new.MI;
    (*VH).Nodes[temp].student.studID = new.studID;
    (*VH).Nodes[temp].student.year = new.year;
    strcpy((*VH).Nodes[temp].student.FN, new.FN);
    strcpy((*VH).Nodes[temp].student.LN, new.LN);
    strcpy((*VH).Nodes[temp].student.course, new.course);

    VH->avail = VH->Nodes[VH->avail].next;
    VH->Nodes[temp].next = *L;
    *L = temp;

}

void freeNode(VirtualHeap *VH, List *L){

    //frees up last node;

    // int *x = L; 

    // for (; *x != -1; x = &VH->Nodes[*x].next){}
    
    // if(*x == -1){
    //     VH->Nodes[*x].next = VH->avail;
    //     VH->avail = *x;
    // }
    
    int *trav = L, temp;
	if(*L!=-1){
		
		temp = (*trav);
		(*trav)= (*VH).Nodes[temp].next;
		(*VH).Nodes[temp].next = (*VH).avail;
		(*VH).avail = temp;
		
		
	}
}