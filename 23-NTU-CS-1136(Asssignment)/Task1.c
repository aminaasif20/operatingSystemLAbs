/*
------------------------------------------------------------
Name: Amina Asif
Registration No: 23-NTU-CS-1136
Task 1 – Thread Information Display
------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* show_thread_info(void* arg) {
    int thread_num = *(int*)arg; // get thread number
    printf("Thread %d started with ID: %lu\n", thread_num, pthread_self());

    // Random sleep between 1–3 seconds
    int sleep_time = rand() % 3 + 1;
    sleep(sleep_time);

    printf("Thread %d completed after %d seconds.\n", thread_num, sleep_time);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int thread_nums[5];
    srand(time(NULL)); // for random sleep times

    for (int i = 0; i < 5; i++) {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, show_thread_info, &thread_nums[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nAll threads have completed.\n");
    return 0;
}
