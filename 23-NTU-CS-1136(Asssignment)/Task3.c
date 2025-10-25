/*
------------------------------------------------------------
Name: Amina Asif
Registration No: 23-NTU-CS-1136
Task 3 – Number Info Thread
------------------------------------------------------------
*/
#include <stdio.h>
#include <pthread.h>
void* number_info(void* arg){
    int number =*(int*)arg;
    printf("\nNumber is : %d\n",number);
    printf("\nNumber is : %d\n",number*number);
    printf("\nNumber is : %d\n",number*number*number);

}

int main(){
    pthread_t thread;
    int number;
    printf("Enter a Number:");
    scanf("%d",&number);
    //create thread
    pthread_create(&thread,NULL,number_info,&number);
    //wait for thread to finish
    pthread_join(thread,NULL);
    return 0;
}