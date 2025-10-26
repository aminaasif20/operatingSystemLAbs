/*
------------------------------------------------------------
Name: Amina Asif
Registration No: 23-NTU-CS-1136
Task 4 – Thread Return Values (Factorial)
------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* factorial(void* arg) {
    int n = *(int*)arg;
    unsigned long long* result = malloc(sizeof(unsigned long long));
    *result = 1;

    for (int i = 1; i <= n; i++) {
        *result *= i;
    }

    pthread_exit((void*)result);
}

int main() {
    pthread_t thread;
    int num;
    unsigned long long* fact_result;

    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_create(&thread, NULL, factorial, &num);
    pthread_join(thread, (void**)&fact_result);

    printf("Factorial of %d is %llu\n", num, *fact_result);
    free(fact_result);

    return 0;
}
