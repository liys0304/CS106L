#include <iostream>

using std::cout;
using std::endl;

class Drink {
private:
  std::string flavor;

public:
  Drink() = default;
  Drink(std::string flavor) : flavor(flavor) {}

  virtual void make() = 0;
  virtual ~Drink() = default;
};

class Tea : public Drink {
private:
  /* data */
public:
  Tea() = default;
  Tea(std::string flavor) : Drink(flavor) {}
  virtual ~Tea() = default;

  void make() {
    cout << "made tea from the tea class!" << endl;
    // go get a cup
    //  pour tea in
  }
};

int main() {

  Tea t("red");
  t.make();
  return 0;
}
