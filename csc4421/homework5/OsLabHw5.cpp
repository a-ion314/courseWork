#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<string>
using namespace std;

int x = 19530, check1, check2;

void *subtractFive(void *);
void *divideFive(void *);

int main (int argc, char *argv[]){
pthread_t thread1, thread2;

cout << "X = " << x << endl << endl;

for (int i = 0; i<5; i++){
cout << "Iteraction: " << i+1 << endl;
if (check1=pthread_create(&thread1, NULL, subtractFive, NULL)){
cout << "Thread creation failed: " << i << endl;
}
pthread_join(thread1, NULL);
if(check2=pthread_create(&thread2, NULL, divideFive, NULL)){
cout << "Thread creation failed: " << i << endl;
}
pthread_join(thread2, NULL);

}
    pthread_exit(NULL);

}

void *subtractFive (void *){
x -= 5;
cout << "Thread 1: " << x << endl;
pthread_exit(NULL);
}

void *divideFive (void *){
x /= 5; 
cout << "Thread 2: " << x << endl << endl;
pthread_exit(NULL);
}

