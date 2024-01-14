#include <iostream>
#include <string>

class StringVector {
public:
  StringVector();
  ~StringVector();

private:
};

StringVector::operator+(const StringVector &other) {
  StringVector result = *this;
  for (const std::string &s : other) {
    result.push_back(s);
  }
  return result;
}
// 如果重载运算符需要非成员函数来定义，则需要在类中定义friend
// 由于cpp的语法，例如[],(),->,=必须重载必须定义为成员函数
// 例如<<必须定义为非成员函数
// 单目运算符需要定义为成员函数
// 不修改操作数的双目运算符定义为非成员函数
// 修改操作数的需要定义为成员函数 例如+=