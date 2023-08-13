#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ID_LEN 20

typedef struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned int birthYear : 11;
    unsigned int birthMonth : 4;
    unsigned int birthDay : 5;
    char gender;
}Person;

typedef struct People {
    Person* arr_people;
    int size;
    int capacity;
}People;

People people;

void* initArray(size_t capacity){
    people.size = 0;
    people.capacity = capacity;
    people.arr_people = malloc(sizeof(Person) * capacity);
}

int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender){
    if(people.size + 1 > people.capacity){
        return -1;
    }

    strcpy(people.arr_people[people.size].name, name);
    people.arr_people[people.size].birthYear = birthYear;
    people.arr_people[people.size].birthDay = birthDay;
    people.arr_people[people.size].gender = gender;
    srand(time(NULL));
    strcpy(people.arr_people[people.size].id, name);
    people.size++;
    return 0;
}

int removePerson(char *id){
    for(int i = 0; i < people.size; i++){
        if(people.arr_people[i].id == id){
            for(int j = i; j < people.size - 1; j++){
                people.arr_people[j] = people.arr_people[j];
            }
            people.size--;
            return 0;
        }
    }
    return -1;
}

void readPerson(){
    char name[100];
    unsigned short birthYear;
    unsigned char birthDay;
    char gender;

    printf("Name: ");
    scanf("%s", name);
    printf("Birth year: ");
    scanf("%hu", &birthYear);
    printf("Birth day: ");
    scanf("%c", &birthDay);
    printf("Gender: ");
    scanf("%c", &gender);

    addPerson(name, birthYear, birthDay, gender);
}

int printPerson(char *id){
    for(int i = 0; i < people.size; i++){
        if(people.arr_people[i].id == id){
            printf("Name: %s\n", people.arr_people[i].name);
            printf("Birth year: %u\n", people.arr_people[i].birthYear);
            printf("Birth day: %c\n", people.arr_people[i].birthDay);
            printf("Gender: %c\n", people.arr_people[i].gender);
            return 0;
        }
    }
    return -1;
}


int main(void){

    return 0;
}