#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;
int count = 0;

void *fun(void *arg)
{
    int id = *(int*)arg;

    sem_wait(&s);   // ENTRY SECTION (lock)

    printf("Thread %d entered CS\n", id);

    int temp = count;      // read shared data
    sleep(1);              // simulate delay
    temp++;
    count = temp;          // update shared data

    printf("Thread %d updated count = %d\n", id, count);

    sem_post(&s);   // EXIT SECTION (unlock)

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    sem_init(&s, 0, 1);

    pthread_create(&t1, NULL, fun, &id1);
    pthread_create(&t2, NULL, fun, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final count = %d\n", count);

    sem_destroy(&s);

    return 0;
}
