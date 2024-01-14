#include <map>
#include <set>
#include <vector>

// vec.at()没有溢出检查
// stack 和 queue 类都是双端队列实现的，双端队列在首端插入时效率更高
// map/set：关键字按序排序，范围查值更快
// unordered map/set :访问单独值更快

// map[key] 若不存在会自动添加，map.get()只会查找是否存在

std::set<int> mySet;
std::set<int>::iterator iter = mySet.begin();

int numOccurences(std::vector<int>& cont, int elemenToCount) {
  int counter = 0;
  std::vector<int>::iterator iter;
  for (iter = cont.begin(); iter != cont.end(); ++iter) {
    if (*iter == elemenToCount) ++counter;
  }
  return counter;
}

// int val = *iter;

int main() { return 0; }