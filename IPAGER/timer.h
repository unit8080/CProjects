#include <pthread.h>
#include <stdint.h>
int start_timer(uint64_t, void (*)(void));
void stop_timer(void);
int schedTimer (uint64_t tmo);
void ipager_activity_loop (void);
