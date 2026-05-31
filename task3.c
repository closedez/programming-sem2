#include <stdio.h>
#include <pthread.h>

typedef struct
{
    char* messages[5];
} ThreadData;

void* thread_func(void* arg)
{
    ThreadData* data = (ThreadData*)arg;

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", data->messages[i]);
    }

    return NULL;
}

int main()
{
    pthread_t threads[4];

    ThreadData data[4] =
    {
        {{"Thread 1: A", "Thread 1: B", "Thread 1: C",
          "Thread 1: D", "Thread 1: E"}},

        {{"Thread 2: One", "Thread 2: Two", "Thread 2: Three",
          "Thread 2: Four", "Thread 2: Five"}},

        {{"Thread 3: Red", "Thread 3: Green", "Thread 3: Blue",
          "Thread 3: White", "Thread 3: Black"}},

        {{"Thread 4: Cat", "Thread 4: Dog", "Thread 4: Fox",
          "Thread 4: Wolf", "Thread 4: Bear"}}
    };

    for (int i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}