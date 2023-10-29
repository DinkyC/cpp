#include <iostream>

struct Node 
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};


class Solution
{
    public:
       void showList(Node *head)
        {
            if (head == nullptr) {
                return;
            }
            while (head) {
                std::cout << head->val << " -> ";
                head = head->next;
            }
            std::cout << " Null";
        }

        Node* reverse(Node *head)
        {
            Node *prev = nullptr, *forward;
            while (head) {
               forward = head->next;
               head->next = prev;
               prev = head;
               head =  forward;
            }

            return prev;
        }

        Node* reverseMid(Node *head, int l, int r)
        {
            Node *dummy = new Node(), *temp, *prev = dummy, *cur;

            dummy->next = head;
            
            for (int i = 0; i < l-1 ; i++) {
                prev = prev->next;
            }

            cur = prev->next;
            for (int i = 0; i < r-l; i++) {
                temp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;
            }


            return dummy->next; 
        }
};

// 1->2->3->4->5->null

int main()
{
    Solution sol;
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    
    a->next = b;
    b->next = c;
    c->next = d;

    Node *newhead = sol.reverseMid(a, 2, 3);

    sol.showList(newhead);

    return 0;
}
