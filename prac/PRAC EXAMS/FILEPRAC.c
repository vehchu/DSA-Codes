#include <stdio.h>

// B] Data Structure Definition
typedef struct {
    char FN[24]; // firstname
    char MI;      // middle initial
    char LN[16];  // lastname
} Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8]; // BSCS, BSIS, BSIT
    int yrLevel;
} Studtype;

// C] Function Prototypes
void displayHeader();
void displayStudent(Studtype S);
void readFile();

void displayStudent(Studtype S) {
    printf("%-10d", S.ID);
    printf("%-16s", S.name.LN);
    printf("%-24s", S.name.FN);
    printf("%-3c", S.name.MI);
    printf("%-8s", S.course);
    printf("%5d", S.yrLevel);
    printf("\n");
}

void readFile() {
    FILE *file;
    Studtype student;

    file = fopen("student.dat", "r");
     
    if (file == NULL) {
        printf("Error opening file student.dat");
        return;
    }

    int count = 0;
    while (fread(&student, sizeof(Studtype), 1, file)) {
        displayStudent(student);
        count++;
        if (count % 20 == 0) {
            // Pause after every 20 recordso
            system("pause");
        }
    }

    fclose(file);
}

int main() {
    // Call the readFile function
    readFile();
    return 0;
}
