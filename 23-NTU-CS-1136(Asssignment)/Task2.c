/*
------------------------------------------------------------
Name: Amina Asif
Registration No: 23-NTU-CS-1136
Task 2 – Personalized Greeting Thread
------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>

void* greeting(void* arg) {
    char* name = (char*)arg;
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Main thread: Waiting for greeting...\n");
    pthread_create(&thread, NULL, greeting, name);
    pthread_join(thread, NULL);

    printf("Main thread: Greeting completed.\n");
    return 0;
}
