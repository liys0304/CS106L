#include <iostream>
#include <istream>
#include <limits>
#include <sstream>

using namespace std;

int getInterger() {
  while (true) {
    string line;
    int result;
    char trash;

    if (!getline(cin, line)) throw domain_error(0);
    istringstream iss(line);
    if (iss >> result && !(iss >> trash)) return result;
    iss.clear();
    iss.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

// 返回多个输出值
pair<int, int> findPriceRange(int dist) {
  int min = static_cast<int>(dist * 0.08 + 100);
  int max = static_cast<int>(dist * 0.36 + 750);
  return make_pair(min, max);
}

/* int main() {
  int dist = 65423;
  auto [min, max] = findPriceRange(dist);
  cout << min << "and" << max;
} */