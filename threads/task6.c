#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* sleep_sort(void* arg)
{
    int value = *(int*)arg;

    usleep(value * 100000);

    printf("%d ", value);

    return NULL;
}

int main()
{
    int arr[] = {7, 3, 1, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    pthread_t threads[50];

    for (int i = 0; i < n; i++)
    {
        pthread_create(&threads[i], NULL,
                       sleep_sort, &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}