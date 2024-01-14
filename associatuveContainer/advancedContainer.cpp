#include <iostream>
#include <map>


using namespace std;

void practiceMultiMap() {
  multimap<int, int> myMMap;
  myMMap.insert(make_pair(3, 3));
  myMMap.insert({3, 12});
  cout << myMMap.count(3) << endl;
}
