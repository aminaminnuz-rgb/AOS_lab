#include <stdio.h>

int readcount = 0;
int mutex = 1;   // for readcount protection
int wrt = 1;     // for writer access

// Reader function
void reader(int id) {
    // Entry section
    mutex--;
    readcount++;

    if (readcount == 1)
        wrt--;   // first reader blocks writer

    mutex++;

    // Critical section
    printf("Reader %d is reading\n", id);

    // Exit section
    mutex--;
    readcount--;

    if (readcount == 0)
        wrt++;   // last reader allows writer

    mutex++;
}

// Writer function
void writer(int id) {
    // Entry section
    wrt--;

    // Critical section
    printf("Writer %d is writing\n", id);

    // Exit section
    wrt++;
}

int main() {
    int i;

    // Simulate execution
    for (i = 1; i <= 3; i++) {
        reader(i);
    }

    for (i = 1; i <= 2; i++) {
        writer(i);
    }

    return 0;
}
