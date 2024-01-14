#include <string>
#include <vector>

using std::string;
using std::vector;
vector<int> operator+(const vector<int> &vec, int elem) {
  vector<int> copy = vec;
  copy += element;
  return copy;
}
// 如果只是简单复制，vec在生命周期结束后会销毁，而copy中的*elem也会丢失

class StringVector {
public:
  StringVector();
  ~StringVector();

private:
  string elems[];
  int logicalSize;
  int allocatedSize;
};

// copy constructor
StringVector::StringVector(const StringVector &other) noexcept
    : logicalSize(other.logicalSize), allocatedSize(other.allocatedSize) {
  elems = new std::string[allocatedSize];
  std::copy(other.begin(), other.end(), begin());
}

// copy assignment
StringVector &StringVector::operator=(const StringVector &other) {
  if (this != &other) {

    delete[] elems;
    logicalSize = other.logicalSize;
    allocatedSize = other.allocatedSize;
    elems = new string[allocatedSize];
    std::copy(other.begin(), other.end(), begin());
  }

  return *this;
}