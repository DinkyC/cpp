#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode() : val(0), next(nullptr), prev(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  ListNode(int x, ListNode *pNext) : val(x), next(pNext), prev(nullptr) {}
};

class LinkedList {
public:
  ListNode *addFromBeg(int, ListNode *head);
  void addFromKey(ListNode **head, int key, int value);
  void showList(ListNode *head);
  ListNode *reverseList(ListNode *head);
  ListNode *reverseMiddle(ListNode *head, int right, int left);
  void addFromEnd(ListNode *head, int value);
};

ListNode *LinkedList::reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  while (head != nullptr) {
    ListNode *nextnode = head->next;
    head->next = prev;
    prev = head;
    head = nextnode;
  }

  return prev;
}

ListNode *LinkedList::reverseMiddle(ListNode *head, int right, int left) {
  ListNode *dummy = new ListNode(), *cur;
  dummy->next = head;
  ListNode *prev = dummy;

  // base cases
  if (!head || head->next == nullptr || right == left) {
    return head;
  }

  for (int i = 0; i < left - 1; i++) {
    prev = prev->next;
  }

  cur = prev->next;

  for (int i = 0; i < right - left; i++) {
    ListNode *temp = prev->next;
    prev->next = cur->next;
    cur->next = cur->next->next;
    prev->next->next = temp;
  }

  return dummy->next;

  delete dummy;
}

ListNode *LinkedList::addFromBeg(int value, ListNode *head = nullptr) {
  if (head == nullptr) {
    ListNode *newdata = new ListNode(value);
    return newdata;
  }
  ListNode *newdata = new ListNode(value);
  newdata->next = head;
  head = newdata;

  return head;
  delete newdata;
}

void LinkedList::addFromKey(ListNode **head, int key, int val) {
  if (head == nullptr) {
    std::cout << "no head" << std::endl;
    return;
  }

  ListNode *newdata = new ListNode();
  newdata->val = val;
  newdata->next = nullptr;

  if (key == 0) {
    newdata->next = *head;
    *head = newdata;
    return;
  }

  ListNode *cur = *head;
  for (int i = 0; i < key - 1 && cur != nullptr; i++) {
    cur = cur->next;
  }

  newdata->next = cur->next;
  cur->next = newdata;
}

void LinkedList::showList(ListNode *head) {
  ListNode *temp = head;
  while (temp != nullptr) {
    std::cout << temp->val << " -> ";
    temp = temp->next;
    if (temp == nullptr)
      std::cout << "NULL\n";
  }
}

void LinkedList::addFromEnd(ListNode *head, int value) {
  // base cases
  if (head == nullptr) {
    return;
  }

  ListNode *cur = head;
  ListNode *dummy = new ListNode();
  dummy->val = value;

  while (cur != nullptr && cur->next != nullptr) {
    cur = cur->next;
  }

  cur->next = dummy;
}

int main() {
  LinkedList list;

  ListNode *a = list.addFromBeg(10);
  ListNode *b = list.addFromBeg(20, a);
  ListNode *c = list.addFromBeg(30, b);
  ListNode *d = list.addFromBeg(40, c);

  list.addFromKey(&d, 2, 15);
  list.addFromEnd(d, 7);

  // ListNode *reversed = list.reverseMiddle(e, 3, 2);

  list.showList(d);
  return 0;
}
