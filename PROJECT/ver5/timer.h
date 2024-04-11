#include <pthread.h>
int start_timer(int, void (*)(void), pthread_mutex_t *mutex);
void stop_timer(void);
int pause_for (unsigned int tmo);
