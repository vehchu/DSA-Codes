typedef char String[30];

typedef struct{
	int date;
	int month;
	int year;
}MyDate;

typedef struct{
	String fName;
	String mName;
	String lName;		
}StudName;

typedef struct{
	String id;
	StudName name;
	char sex;
	MyDate bday;
	String program;
	int year;
	
}Student;

typedef struct node{
	Student elems;  //make it into student ADT //seperate the names first,last,middle //make ID into char[] and identify what year by what the number of the first 2 char of ID //EXAMPLE if 22xxxxxxxx firstyear
	struct node *next;
}SType,*Ptr;//ask sir about this why we need 2pointers // I know its the same as linked list but still libog sabton

typedef struct{
	Ptr* elem;
	int count;
	int max;//init as 26
}Dictionary;

MyDate newDate(int date, int month,int year);
StudName newName(String fName,String mName,String lName);
Student newStud(String id,StudName name,char sex,MyDate bday,String program,int year);

void initDict(Dictionary *D,int size);
unsigned int Hash(String lName,int size); //last name first letter //also pass max;
void display(Dictionary D);

void insertTable(Dictionary *D,Student stud); //insert sorted //last name if not firstname if not ID
void deleteTable(Dictionary *D,String lName,int id);//declare the deleted as deleted and empty as empty// to not insert in deleted slot
void searchTable(Dictionary *D);
//void resizeTable //to resize the table after 70% is used;