#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const size_t kNumThreads = 10;
std::mutex mtx;

void greet(int id) {
  std::lock_guard<std::mutex> lg(mtx);
  cout << "hello there! my name is " << id << endl;
}

int main() {
  cout << "greetings from my threads.." << endl;

  vector<std::thread> threads;
  for (size_t i = 0; i < kNumThreads; ++i) {
    threads.push_back(std::thread(greet, i));
    threads[i].join();
  }

  for (std::thread &t : threads) {
    // t.join();
  }

  // thread1.join(); // check whether its finished
  // thread2.join();

  cout << "all greetings done!" << endl;

  return 0;
}