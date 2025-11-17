#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static pthread_mutex_t lockA = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lockB = PTHREAD_MUTEX_INITIALIZER;

void *func1(void *arg) {
  printf("hello, I am thread A.\n");
  pthread_mutex_lock(&lockA);
  printf("thread A just locked A.\n");
  pthread_mutex_lock(&lockB);
  printf("thread A just locked B.\n");
  pthread_mutex_unlock(&lockB);
  pthread_mutex_unlock(&lockA);
  printf("thread A just unlocked both locks.\n");
  pthread_exit(0);
}

void *func2(void *arg) {
  printf("hello, I am thread B.\n");
  pthread_mutex_lock(&lockB);
  printf("thread B just locked B.\n");
  pthread_mutex_lock(&lockA);
  printf("thread B just locked A.\n");
  pthread_mutex_unlock(&lockA);
  pthread_mutex_unlock(&lockB);
  printf("thread B just unlocked both locks.\n");
  pthread_exit(0);
}

int main(void) {
  pthread_t threadA, threadB;
  pthread_create(&threadA, NULL, func1, NULL);
  pthread_create(&threadB, NULL, func2, NULL);
  pthread_join(threadA, NULL);
  pthread_join(threadB, NULL);
  printf("done");
  return 0;
}
