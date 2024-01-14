#include <iostream>
#include <sstream>


using namespace std;

int stringToInterger(const string& str) {
  istringstream iss(str);

  int result;
  iss >> result;
  if (iss.fail()) throw domain_error(0);

  char remain;
  iss >> remain;
  if (!iss.fail()) throw domain_error(0);
  return result;
}

int main() {
  const string str = "l4";
  int val = stringToInterger(str);
  cout << val << endl;
}