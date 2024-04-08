// system_clock::now
#include <iostream>
#include <ctime>
#include <ratio>
#include <thread>
#include <chrono>

int main ()
{
  using namespace std::chrono;

  time_t tt;
  system_clock::time_point today = system_clock::now();
  tt = system_clock::to_time_t ( today );
  printf("start tt = %ld \n", tt);
  tt += 10;
  bool flag = true;
  time_t now;
  int i = 10;
  while (flag) {
        time(&now);
        if (now > tt) {
            flag = false;
        } else {
            std::this_thread::sleep_for (std::chrono::seconds(1));
            printf("%d \n", i--);
        }
  }
  printf("now tt = %ld \n", now);
  return 0;
}
