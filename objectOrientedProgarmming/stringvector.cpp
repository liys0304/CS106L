#include "stringvector.h"

using std::cout;
using std::endl;

StrVector::StrVector() noexcept : logicalSize(0), allocatedSize(kInitialSize) {
  std::cout << "hello from the default constructor!" << endl;
  elems = new std::string[allocatedSize];
}

StrVector::StrVector(size_type n, const std::string &val) noexcept
    : logicalSize(n), allocatedSize(2 * n) {
  cout << "hello from the fill constructor!" << endl;
  elems = new std::string[allocatedSize];
  std::fill(beigin(), end(), val);
}

StringVector::StringVector(const StringVector &other) noexcept
    : logicalSize(other.logicalSize), allocatedSize(other.allocatedSize) {
  cout << "hello from the copy constructor!" << endl;
  elems = new std::string[allocatedSize];
  std::copy(other.begin(), other.end(), begin());
}

StringVector &StringVector::operator=(const StringVector &other) {
  cout << "hello from the copy assignment operator!" << endl;
  if (this != &other) {

    delete[] elems;
    logicalSize = other.logicalSize;
    allocatedSize = other.allocatedSize;
    elems = new string[allocatedSize];
    std::copy(other.begin(), other.end(), begin());
  }
  return *this;
}

StrVector::StrVector(StrVector &&other) noexcept
    : elems(std::move(other.elems)), logicalSize(std::move(other.logicalSize)),
      allocatedSize(std::move(other.allocatedSize)) {
  cout << "hello from the move constructor!" << endl;
  other.elems = nullptr;
}

StrVector::StrVector::operator=(StrVector &&rhs) noexcept {
  cout << "hello from the move assignment operator!" << endl;
  if (this != &rhs) {
    delete[] elems;
    logicalSize = std::move(rhs.logicalSize);
    allocatedSize = std::move(rhs.allocatedSize);
    elems = std::move(rhs.elems); // move会把值变为右值
    rhs.elems = nullptr;
  }
  return *this;
}