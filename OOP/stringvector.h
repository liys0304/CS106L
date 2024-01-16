#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <algorithm>
#include <iostream>
#include <string>


class StrVector {
public:
  using iterator = std::string *;
  using const_iterator = const std::string *;
  using size_type = size_t;

  const size_type kInitialSize = 2;
  StrVector() noexcept;
  StrVector(size_type n, const std::string &val) noexcept;
  StrVector(const StrVector &other) noexcept;
  StrVector operator=(const StrVector &rhs) noexcept;
  StrVector(StrVector &&other) noexcept;
  StrVector &operator=(StrVector &&rhs) noexcept;
  ~StrVector() noexcept;

  size_type size() const;
  bool empty() const;
}