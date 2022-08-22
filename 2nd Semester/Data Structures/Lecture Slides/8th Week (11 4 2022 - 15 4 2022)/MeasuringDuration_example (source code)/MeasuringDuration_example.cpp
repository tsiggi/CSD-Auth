#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

/**
The clock() function in C++ returns the approximate processor time
that is consumed by the program.

In order to compute the processor time, the difference between values returned
by two different calls to clock(), one at the start and other at the end of the
program is used. To convert the value to seconds, it needs to be divided by a
macro CLOCKS_PER_SEC.

The clock() time may advance faster or slower than the actual wall clock. It
depends on how the operating system allocates the resources for the process.

If the processor is shared by other processes, the clock() time may advance
slower than the wall clock. While if the current process is executed in a
multithreaded system, the clock() time may advance faster than wall clock.

https://www.programiz.com/cpp-programming/library-function/ctime/clock

 */

int main(int argc, char const *argv[]) {

  float x, y;
  clock_t time_req;

  // Using pow function
  time_req = clock(); 
  //clock(): returns the number of clock ticks elapsed since the program was launched
  
  for (int i = 0; i < 1000000000; i++) {
    y = log(pow(i, 5));
  }
  time_req = clock() - time_req;
  cout << "Using pow function, it took " << (float)time_req / CLOCKS_PER_SEC
       << " seconds" << endl;

  // Without pow function
  time_req = clock();
  for (int i = 0; i < 10000000; i++) {
    y = log(i * i * i * i * i);
  }
  time_req = clock() - time_req;
  cout << "Without using pow function, it took "
       << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

  return 0;
}
