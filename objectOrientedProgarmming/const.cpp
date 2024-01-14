#include <vector>

void pointer_int() {
  // read right to left
  // constant pointer to a non-constant int
  int *const p;
  // non-constant pointer to a constant int
  const int *p;
  int const *p;
  // constant pointer to a constant int
  const int *const p;
  int const *const p;
}

void const_iterators() {
  std::vector<int> vec{1, 234};
  const std::vector<int>::iterator it = vec.begin();
  ++it;      // doesnt compile
  *itr = 15; // compiles

  std::vector<int>::const_iterator it = vec.begin();
  *it = 5;       // cant change value of it
  ++it;          // ok, changing vec
  int val = *it; // ok, reading from it
}

/*大部分时候，任何不被修改的参数都应该定义为const
    传const&要比直接传值好，原始数据类型不一定
    成员函数应该有const和非const的迭代器
    从右向左读来理解指针*/