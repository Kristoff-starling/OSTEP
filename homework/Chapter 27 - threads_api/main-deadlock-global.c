#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "common_threads.h"

pthread_mutex_t g = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {
	usleep(1);
    Pthread_mutex_lock(&g);
    if ((long long) arg == 0) {
		Pthread_mutex_lock(&m1);
		Pthread_mutex_lock(&m2);
    } else {
		Pthread_mutex_lock(&m2);
		Pthread_mutex_lock(&m1);
    }
	Pthread_mutex_unlock(&m1);
    Pthread_mutex_unlock(&m2);
    Pthread_mutex_unlock(&g);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
	for (int t = 1; t <= 10000; t++)
	{
		Pthread_create(&p1, NULL, worker, (void *) (long long) 0);
		Pthread_create(&p2, NULL, worker, (void *) (long long) 1);
		Pthread_join(p1, NULL);
		Pthread_join(p2, NULL);
		printf("%dth trial completed.\n", t);
	}
    return 0;
}
