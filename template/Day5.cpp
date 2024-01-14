#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T> std::pair<T, T> my_minmax(T a, T b) {
  if (a < b)
    return {a, b};
  else {
    return {b, a};
  }
}

template <typename T> T getTypeValue() {
  while (true) {
    cout << "enter a" << typeid(T).name() << ':';

    string line;
    T result;
    char extra;
    if (!getline(cin, line))
      throw domain_error("unable to get line from cin");
    istringstream iss(line);
    if (iss >> result && !(iss >> extra))
      return result;
    cout << "invalid format" << endl;
  }
}

template <typename Collection, typename DataType>
int countOccourences(const Collection &list, DataType val) {
  int count = 0;
  for (auto iter = list.begin(); iter != list.end(); iter++) {
    if (*iter == val)
      count++;
  }

  return count;
}

//
/* template <typename InputIterator, typename DataType>
int countOccourences(InputIterator begin, InputIterator end, DataType val) {
  int count = 0;
  for (auto iter = begin; iter != end; iter++) {
    if (*iter == val) count++;
  }

  return count;
}
 */
// templates and functions

template <typename InputIterator, typename UniaryPredicate>
int countOccourences(InputIterator begin, InputIterator end,
                     UniaryPredicate predicate) {
  int count = 0;
  for (auto iter = begin; iter != end; iter++) {
    if (predicate(*iter))
      count++;
    // countOccurences(vec.begin,vec.end,islessthan5(*it));
  }

  return count;
}

/* int main() {
  auto islessthan5 = [](int i) { return i < 2; };
} */