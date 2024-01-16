#include <iostream>

void rawPtrFn() {
  // Node* n = new Node;
  std::unique_ptr<Node> n(new Node); // cannot be copied
  // do stuff with n
  // delete n;
}
/*uniquely owns its resource and deletes it when the object is destroyed*/

void sharePtr() {
  std::shared_ptr<int> p1(new int);
  std::shared_ptr<int> p2 = p1;
}
// resource can be stored by any number of shared_ptrs
// deleted when none of them point to it