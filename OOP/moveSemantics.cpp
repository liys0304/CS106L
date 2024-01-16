#include <string>
#include <vector>

using namespace std;

// push_back and emplace_back

struct President {
  string name;
  string country;
  int age;
}

void test()
{
  vector<President> elections;
  elections.emplace_back("Nelson Mandela", "South Africa", 1994);

  vector<President> reElections;
  reElections.push_back(President("Franklin Delano", "the USA", 1936));
}

// lval and rval

int val = 2;
int *ptr = 0x02248837;
vector<int> v1{1, 2, 3};

auto &ptr2 = ptr;           // ptr2是左值引用
auto &&v4 = v1 + v2;        // v4是右值引用
auto &ptr3 = &val;          // 错误，不能用左值引用绑定右值引用
auto &&val2 = val;          // 错误，不能用右值引用绑定左值引用
const auto &ptr3 = ptr + 5; // 可以绑定const左值引用到右值引用

void nocos_Lref(vector<int> &v);
void const_Lref(const vector<int> &v);
void nocos_Rref(vector<int> &&v);

vector<int> v1 = v2 + v3; // v1 is lval
nocos_Lref(v1);           // ok,lval ref binds to lval
nocos_Rref(v1);           // error, rval ref no bind to l-v
nocos_Lref(v2 + v3);      // error, lval ref no bind to r-v
const_Rref(v2 + v3);      // ok, const l-ref binds to r-v
nocos_Rref(v2 + v3);      // ok, r-val ref binds to r-v

// 左值对象不是一次性的，可以拷贝不可移动
// 右值对象是一次性的，可以拷贝可以移动

template <typename T> void swap(T &table1, T &table2) {
  T temp = std::move(table1);
  table1 = std::move(table2);
  table2 = std::move(temp);
}