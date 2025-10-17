#include <stdio.h>
#include <pthread.h>

void* print_number(void* arg)
{
    float num = *(float*)arg; // Cast void* back to float*
    printf("Thread received number: %f\n", num);
    printf("Square: %f\n", num * num);
    return NULL;
}

int main()
{
    pthread_t thread_id;
    float cgpa = 3.67;

    printf("Creating thread with argument: %f\n", cgpa);

    // Pass address of 'cgpa' to thread
    pthread_create(&thread_id, NULL, print_number, &cgpa);
    pthread_join(thread_id, NULL);

    printf("Main thread done.\n");
    return 0;
}
