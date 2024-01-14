#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> vec{1, 3, 4, 5, 6};
  int limit = 5;
  int num_times_called;
  auto isLessThanLimit = [limit, &num_times_called](auto val) -> bool {
    ++num_times_called;
    return val < limit;
  };
  /*  auto func1 = [ =, &teas ](parameters) -> return -value { body; };
  capture all by value, except teas is by reference
      auto func2 = [&, banned ](parameters) -> return -value { body; };
  capture all by reference, except banned is by value */
}

struct Course {
  std::string name;
  double rating;
};

int tested() {
  auto compareRating = [](const Course &c1, const Course &c2) {
    return c1.rating > c2.rating;
  };
  // std::sort(course.begin(), course.end(), compareRating);
  // std::nth_element 在区间上求第K小的元素
  // std::stable_partition() 划分枢轴
}

void algorithm_stable_partition() {
  std::vector<Course> course;
  std::string department = "CS";
  auto isDep = [](auto element) {
    return element.name.size() > 2 && element.name.substr(0, 2) == "CS";
  };
  std::stable_partition(course.begin(), course.end(), isDep);
}

// homework
template <typename ForwardIt, typename UniPred>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UniPred pred) {
  auto high = last;
  auto low = first;
  auto pivot = *high;
  while (high > low && pred(*low))
    low++;
  *high = *low;
  while (high > low && !pred(*high))
    high--;
  *low = *high;
  *low = *pivot;
  return low;
}