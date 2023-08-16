#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 1000

typedef struct Student {
	char name[16];
	double avg_grade;
}Student;

int main(void){
    Student* students = malloc(sizeof(Student) * COUNT);

    srand(time(NULL));
    for(int i = 0; i < COUNT; i++){
        for(int j = 0; j < 5; j++){
            students[i].name[j] = (rand() % ('z' - 'a' + 1)) + 'a';
        }
        students[i].avg_grade = ((rand() % (600 - 200 + 1)) + 200) / 100.;
    }
    FILE* file = fopen("students.bin", "w");
    fwrite(students, sizeof(Student), COUNT, file);
    rewind(file);
    fread(students, sizeof(Student), COUNT, file);
    double max = students[0].avg_grade;
    int max_id = 0;
    for(int i = 1; i < COUNT; i++){
        if(students[i].avg_grade > max){
            max = students[i].avg_grade;
            max_id = i;
        }
    }
    printf("%s %.2lf\n", students[max_id].name, students[max_id].avg_grade);

    free(students);
    fclose(file);


    return 0;
}
