#include <algorithm>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;
//                                      * const :this  func takes in a const
//                                      ptr..
const int *const myClassMethod(const int *const &param) const;
/*                             const int: ...to a const int.
const int：  ...to a const
         * const： this function returns a const ptr..
         最后一个const表示这个成员函数不会修改任何成员变量
*/

namespace Lecture {
int count(const vector<int> &v) {
  int cnt = 0;
  for (auto i : v) {
    if (i == 1) {
      ++cnt;
    }
  }
  return cnt;
}
} // namespace Lecture

int main() {
  vector<int> v{3, 1, 3, 4, 1, 5, 7};
  int count = 0;
  for (auto i : v) {
    if (i == 1) {
      count++;
    }
  }
  cout << "manual count: " << count << endl;
  cout << "lecture count: " << Lecture::count(v) << endl;
  cout << "algorithm count: " << std::count(v.begin(), v.end(), 1);
  return 0;
}