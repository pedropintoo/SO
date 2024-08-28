#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

sem_t mutex;
sem_t turnstile;
sem_t turnstile2;

int count;

int N;

void * fun1(void * s)
{   
    int i = 0;
    while (++i < 100) {
        printf("[%d] - Message :%s\n",i,(char *)s);

        // Random delay
        srand(time(NULL));
        double randomTime = (double)(rand() %5 + 1) / 5; // Range 1-5, or use rand() % 4 + 1 for 1-4
        sleep(randomTime);

        sem_wait(&turnstile2);
        sem_post(&turnstile2);

        sem_wait(&mutex);
        count++;
        if (count == N) {
            sem_post(&turnstile);
            sem_wait(&turnstile2);
        }
        sem_post(&mutex);

        sem_wait(&turnstile);
        sem_post(&turnstile);

        printf("[%d] - After sleep..:%s\n",i,(char *)s);

        sem_wait(&mutex);
        count--;
        if (count == 0) {
            sem_wait(&turnstile);
            sem_post(&turnstile2);
        }
        sem_post(&mutex);
    }
}

int main()
{   
    N = 10;
	pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	sem_init(&mutex,0,1);
    sem_init(&turnstile,0,0);
    sem_init(&turnstile2,0,1);

	pthread_create(&t1,0,fun1,"thread1");
	pthread_create(&t2,0,fun1,"thread2");
    pthread_create(&t3,0,fun1,"thread3");
    pthread_create(&t4,0,fun1,"thread4");
    pthread_create(&t5,0,fun1,"thread5");
	pthread_create(&t6,0,fun1,"thread6");
    pthread_create(&t7,0,fun1,"thread7");
    pthread_create(&t8,0,fun1,"thread8");
    pthread_create(&t9,0,fun1,"thread9");
	pthread_create(&t10,0,fun1,"thread10");


	pthread_join(t1,0);
	pthread_join(t2,0);
    pthread_join(t3,0);
    pthread_join(t4,0);
    pthread_join(t5,0);
	pthread_join(t6,0);
    pthread_join(t7,0);
    pthread_join(t8,0);
    pthread_join(t9,0);
	pthread_join(t10,0);

}