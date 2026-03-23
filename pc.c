#include <stdio.h>

#define N 5

int mutex = 1;
int full = 0;
int empty = N;

int in = 0, out = 0;
int buffer[N];

// Wait (P) operation
void wait(int *s) {
    (*s)--;
}

// Signal (V) operation
void signal(int *s) {
    (*s)++;
}

// Producer
void producer(int item) {
    wait(&empty);
    wait(&mutex);

    buffer[in] = item;
    printf("Produced: %d\n", item);
    in = (in + 1) % N;

    signal(&mutex);
    signal(&full);
}

// Consumer
void consumer() {
    wait(&full);
    wait(&mutex);

    int item = buffer[out];
    printf("Consumed: %d\n", item);
    out = (out + 1) % N;

    signal(&mutex);
    signal(&empty);
}

int main() {
    for (int i = 1; i <= 5; i++) {
        producer(i);
        consumer();
    }
    return 0;
}
