#include <iostream>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mtx;
int sharedResource = 0;

void* increment(void* arg) {
    int threadNum = *(int*)arg;
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mtx);
        ++sharedResource;
        std::cout << "Thread " << threadNum << " incremented counter to " << sharedResource << std::endl;
        pthread_mutex_unlock(&mtx);
        sleep(1);
    }
    return nullptr;
}

int main() {
    pthread_t t1, t2;
    int thread1 = 1, thread2 = 2;

    pthread_mutex_init(&mtx, nullptr);

    pthread_create(&t1, nullptr, increment, &thread1);
    pthread_create(&t2, nullptr, increment, &thread2);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    pthread_mutex_destroy(&mtx);
    std::cout << "Final counter value: " << sharedResource << std::endl;

    return 0;
}
