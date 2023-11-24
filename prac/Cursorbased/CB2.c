#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef char String[20];
typedef int List;

typedef struct{
	int StudId;
	String studName;
	char sex;
	String program;
} Student;

typedef struct{
	Student elem;
	int next;
}SType;

typedef struct{
	SType elems[MAX];
	int avail;          
} VirtualHeap;

Student newStudent(int StudId,String studName,char sex,String program);

VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *vh);
void insertFront(VirtualHeap *vh, List *list,Student s);

void displayList(VirtualHeap vh,List list);
void visualizeSpace(VirtualHeap vh);

void deallocSpace(VirtualHeap *vh, int index);
Student removeStudent(VirtualHeap *vh,List *list, String keyword);

int main(){


}

Student newStudent(int StudId,String studName,char sex,String program){

    Student new;

    new.StudId = StudId;
    new.sex = sex;

    strcpy(new.program, program);
    strcpy(new.studName, studName);

    return new;

}

VirtualHeap newVirtualHeap(){

    VirtualHeap VH;

    int x, LIM = MAX -1; 

    for(x = 1; x <= LIM; x ++){
        VH.elems[x-1].elem = newStudent(0, " ", ' ', " ");
        VH.elems[x-1].next = x;
    }

    VH.elems[LIM].next = -1;
    VH.avail = 0;

    return VH; 
}

int allocSpace(VirtualHeap *vh){

    int retval = vh->avail; 

    if(vh->avail != -1){
        vh->avail = vh->elems[vh->avail].next;
    }

    return retval; //returns the available index, condition updates for the next
}

void insertFront(VirtualHeap *vh, List *list,Student s){

    int first = allocSpace(vh); //allocspace returns the index that is available

    if(vh->avail != -1){
      
        vh->elems[first].elem = s;
        vh->elems[first].next = vh->avail;

        //no need to change avail bc it is updated in allocspace
    }
    
}

void displayList(VirtualHeap vh,List list);
void visualizeSpace(VirtualHeap vh);

void deallocSpace(VirtualHeap *vh, int index){

    //marks the given index as not av

}
Student removeStudent(VirtualHeap *vh,List *list, String keyword);