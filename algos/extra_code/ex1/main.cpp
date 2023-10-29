#include <algorithm>
#include <iostream>
#include <memory>

template <typename T> class LinkedList {
private:
  struct Node {
    T val;
    Node *next;
    Node *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(T x) : val(x), next(nullptr), prev(nullptr) {}
    Node(T x, Node *y) : val(x), next(y), prev(nullptr) {}
    Node(T x, Node *y, Node *z) : val(x), next(y), prev(z) {}
  };

  size_t size = 0;
  Node *head = nullptr;

public:
  ~LinkedList() {
    while (head) {
      Node *prev = head;
      head = head->next;
      delete prev;
    }
  }

  void printSize() { std::cout << size << '\n'; }

  void printList() {
    if (head == nullptr) {
      std::cout << "No LinkedList"
                << "\n";
    }
    Node *cur = head;
    while (cur) {
      std::cout << cur->val << " -> ";
      cur = cur->next;
    }

    std::cout << " NULL ";
  }

  Node *deleteNode(T n) {
    auto *cur = head;
    auto *prev = new Node(nullptr);

    for (int i = 0; i < n - 1; i++) {
      prev = cur;
      cur = cur->next;
    }

    prev->next = cur->next;
    (*cur).reset(); // delete memory

    --size;
    return head;
  }

  void addNodeBeg(T value) {
    auto new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      ++size;
      return;
    }

    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    ++size;
  }

  void addNodeEnd(T value) {
    if (head == nullptr) {
      head = new Node(value);
    }

    auto *new_node = new Node(value), *cur = head;

    while (cur->next) {
      cur = cur->next;
    }

    cur->next = new_node;
    new_node->prev = cur;

    ++size;
  }

  void addNodeN(T value, T n) {
    if (head == nullptr) {
      head = new Node(value);
      return;
    } else if (n < 0) {
      return;
    }

    auto *cur = head, *new_node = new Node(value);

    for (int i = 0; i < n - 1; i++) {
      if (cur == nullptr) {
        break;
      }
      cur = cur->next;
    }

    new_node->next = cur->next;
    cur->next = new_node;

    ++size;
  }

  void reverse() {
    auto *prev = new Node(nullptr);

    while (head) {
      auto forward = head->next;
      head->next = prev;
      prev = head;
      head = forward;
    }

    head = prev;
  }

  Node *reverseMid(T l, T r) {
    auto *dummy = new Node(), *cur = head;
    Node *prev = nullptr;

    dummy->next = head;
    prev = dummy;

    for (int i = 0; i < l; i++) {
      prev = prev->next;
    }

    cur = prev->next;
    for (int i = 0; i < r - l; i++) {
      // save the current node
      auto temp = prev->next;
      // reverse the current node with the next node
      prev->next = cur->next;
      // move the current node forward
      cur->next = cur->next->next;
      // move the previous node forward
      prev->next->next = temp;
    }

    return dummy->next;
  }

  bool isPalandrome() {
    // base cases
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    // initialize necessary variables
    auto *fast = head, *slow = head;
    Node *prev = nullptr, *temp = nullptr;
    // iterate fast until slow is in the middle
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // if fast is a nullptr or fast->next is a nullptr then mov slow to the true
    // center
    if (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
    }

    // while slow and slow->next is not nullptr
    while (slow && slow->next) {
      // save the next node
      temp = slow->next;
      // set the next node to the previous value
      slow->next = prev;
      // set the previous value to the current value
      prev = slow;
      // move the slow pointer (current node) forward
      slow = temp;
    }

    // if the slow node is not a nullptr else tie together the back half of the
    // list
    if (slow != nullptr) {
      slow->next = prev;
    }

    // check values from the front and back half
    fast = head;
    while (fast && slow) {
      if (fast->val != slow->val) {
        return false;
      }

      fast = fast->next;
      slow = slow->next;
    }

    return true;
  }
};

int main() {
  LinkedList<int> list;

  list.addNodeBeg(2);
  list.addNodeBeg(3);
  list.addNodeBeg(4);
  list.printList();
  list.printSize();

  return 0;
}
