/*
------------------------------------------------------------
Name: Amina Asif
Registration No: 23-NTU-CS-1136
Task 5 – Struct-Based Thread Communication
------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

int deanCount = 0;
pthread_mutex_t lock;

void* check_student(void* arg) {
    Student* s = (Student*)arg;
    printf("\nStudent ID: %d\nName: %s\nGPA: %.2f\n", s->student_id, s->name, s->gpa);

    if (s->gpa >= 3.5) {
        printf("Status: Eligible for Dean’s List ✅\n");
        pthread_mutex_lock(&lock);
        deanCount++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("Status: Not eligible ❌\n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    Student students[3] = {
        {101, "Amina Asif", 3.8},
        {102, "Ali Raza", 3.2},
        {103, "Sara Khan", 3.6}
    };

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, check_student, &students[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nTotal students on Dean’s List: %d\n", deanCount);
    pthread_mutex_destroy(&lock);
    return 0;
}
