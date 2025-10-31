// Amina Asif
// 23-NTU-CS-1136 SE (A)

// Write a C program that creates 4 threads. Each thread should: 
// 1.  Receive a unique number N as an argument (use values: 10, 20, 30, 40)
// 2.  Calculate the sum of numbers from 1 to N
// 3.  Print the thread number and calculated sum
// 4.  Return the sum through thread's return value
// Main thread should:
//   Create all 4 threads and pass arguments Wait for all threads to complete
//  Collect all return values
//  Calculate and print the total of all sums

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* CalcutaleSum(void* arg){
    int N=*(int*)arg;  //dereference the argumnet to get the number
    int* sum=malloc(sizeof(int));  //allocate memory to store the sum
    *sum=0;
    for(int i=1;i<=N;i++){
        *sum+=i; //calculate the sum
    }
    printf("Thread Number: %d\n",N); //print the thread number
    printf("Sum from 1 to %d is: %d\n",N,*sum); //print the calculates sum one-by-one
    pthread_exit((void*)sum);//rturn the sum as arguemnt to main thread
}

int main(){
pthread_t threads[4]; //array of threads
int numbers[4]={10,20,30,40};
for(int i=0;i<4;i++){
    pthread_create(&threads[i],NULL, CalcutaleSum,&numbers[i]); //create threads 
}
    int totalSum = 0; //variable to store total sum
for (int i = 0; i < 4; i++) {
        int* threadSum;
        pthread_join(threads[i], (void**)&threadSum);//wait for each thread to complete 
        totalSum += *threadSum;   //Add each thread's result
        free(threadSum);          //Free memory allocated in thread
    }

    printf("\nTotal sum of all threads = %d\n", totalSum); //print the total sum
    return 0;
}