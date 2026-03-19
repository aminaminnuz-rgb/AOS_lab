#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;  // semaphore variable

void *process(void *arg)
{
    int id = *(int *)arg;

    // Entry Section
    sem_wait(&mutex);

    // Critical Section
    printf("Process %d is in Critical Section\n", id);

    // Exit Section
    printf("Process %d is leaving Critical Section\n", id);

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    // Initialize semaphore (1 → binary semaphore / mutex)
    sem_init(&mutex, 0, 1);

    // Create threads
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy semaphore
    sem_destroy(&mutex);

    return 0;
}
