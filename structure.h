#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Engineer {
    char lastName[50];
    char firstName[50];
    char thirdName[50];
    char gender[10];
    char occupation[50];
    int birthDate;
};

struct Engineer engineer_storage[MAX_SIZE];
int num_engineers = 0;

void readEngineers(char* filename) {
    FILE* file = fopen_s(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    while (!feof(file) && num_engineers < MAX_SIZE) {
        struct Engineer* engineer = &engineer_storage[num_engineers];
        fscanf_s(file, "%s %s %s %s %s %d",
            engineer->lastName, engineer->firstName, engineer->thirdName,
            engineer->gender, engineer->occupation, &engineer->birthDate);
        num_engineers++;
    }

    fclose(file);
}

void printEngineers() {
    int current_year = 2023; 
    int retirement_age_male = 65;
    int retirement_age_female = 60;

    for (int i = 0; i < num_engineers; i++) {
        struct Engineer* engineer = &engineer_storage[i];

        if ((strcmp(engineer->gender, "мужчина") == 0 &&
            (current_year - engineer->birthDate >= retirement_age_male)) ||
            (strcmp(engineer->gender, "женщина") == 0 &&
                (current_year - engineer->birthDate >= retirement_age_female))) {
            printf(" %s\n", engineer->lastName);
            printf(" %s\n", engineer->firstName);
            printf(" %s\n", engineer->thirdName);
            printf(" %s\n", engineer->gender);
            printf(" %s\n", engineer->occupation);
            printf(" %d\n", engineer->birthDate);
            printf("-------------------------\n");
        }
    }
}