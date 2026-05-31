#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void cleanup(void* arg)
{
    long id = (long)arg;

    printf("Thread %ld is terminating\n", id);
}

void* thread_func(void* arg)
{
    long id = (long)arg;

    pthread_cleanup_push(cleanup, (void*)id);

    while (1)
    {
        printf("Thread %ld working...\n", id);

        sleep(1);

        pthread_testcancel();
    }

    pthread_cleanup_pop(1);

    return NULL;
}

int main()
{
    pthread_t threads[4];

    for (long i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL,
                       thread_func, (void*)i);
    }

    sleep(2);

    printf("\nCancelling threads...\n\n");

    for (int i = 0; i < 4; i++)
    {
        pthread_cancel(threads[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}