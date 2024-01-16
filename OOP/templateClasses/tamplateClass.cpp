#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T, class Container = std::vector<T>> class Priority_Q {
public:
  Priority_Q() = default;
  ~Priority_Q() = default;

  T top() const {
    if (_heap.empty()) {
    } // throw error;
    return _heap[0];
  }

  void pop() {
    if (!_heap.empty()) {
      std::pop_heap(_heap.begin(), _heap.end());
      _heap.pop_back();
      --_count;
    }
  }

  void push(T val) {
    _heap.push_back(val);
    std::push_heap(_heap.begin(), _heap.end());
    ++count;
  }

  friend std::ostream &operator<<(std::ostream &os, const Priority_Q) {
    os << "{";
    for (int i = 0, len = pq._count; i < len; ++i) {
      if (i > 0)
        os << ",";
      os << pq._heap[i][0];
    }
    return os << "}";
  }

private:
  vector<T> _heap;
  size_t _count{0};
};