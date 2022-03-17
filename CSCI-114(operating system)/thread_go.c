#include<stdio.h>
#include<threads.h>
#define NTHREADS 10
static pthread_t threads[NTHREADS];
static void go(int n);
int main(int argc, char **argv)
{
    int i;
    long exitValue;
    int* res;
    for(i=0;i<NTHREADS;i++)
    {
        thrd_create(&(threads[i]),&go,i);
    }
    for(i=0;i<NTHREADS;i++)
    {
        exitValue = thrd_join(threads[i],res);
        printf("Thread %d returned with %ld\n",i,exitValue);
    }
    printf("Main thread done.\n");
    return 0;
}
void go(int n)
{
    printf("Hello from thread %d\n",n);
    thrd_exit(100+n);
}