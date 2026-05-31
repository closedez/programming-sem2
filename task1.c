#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Child thread: line %d\n", i);
    }

    return NULL;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, thread_func, NULL);

    for (int i = 1; i <= 5; i++)
    {
        printf("Main thread: line %d\n", i);
    }

    pthread_join(tid, NULL);

    return 0;
}