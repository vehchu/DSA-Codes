typedef struct node{
    int data;
    struct node *next;
} *LIST, lType;

void insertLast(LIST *L, int elem){
    LIST temp, *trav;

    for (trav = L; (*trav) != NULL; trav = &(*trav)->next){}

    temp = (LIST)mall