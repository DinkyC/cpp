#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode() : val(0), next(nullptr), prev(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  ListNode(int x, ListNode *y) : val(x), next(y), prev(nullptr) {}
  ListNode(int x, ListNode *y, ListNode *z) : val(x), next(y), prev(z) {}
};

template <typename T> class LinkedList {
public:
  bool isCycle(T *&head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    T *fast = head, *slow = head;
    while (fast != nullptr && slow != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  LinkedList<ListNode> list;

  ListNode *d = new ListNode(4);
  ListNode *c = new ListNode(3, d);
  ListNode *b = new ListNode(2, c);
  ListNode *a = new ListNode(1, b);

  // ListNode *z = new ListNode(2);
  // ListNode *g = new ListNode(3, z);

  b->prev = a;
  c->prev = b;
  d->prev = c;
  // create cycle
  d->next = b;

  bool result = list.isCycle(a);

  std::cout << "The result is: " << result << '\n';

  delete a;
  delete b;
  delete c;
  delete d;
}
