#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *y) : val(x), next(y), prev(nullptr) {}
    ListNode(int x, ListNode *y, ListNode *z) : val(x), next(y), prev(z) {}
};

template<typename T>
class LinkedList
{
    public:
        void showList(T *head)
        {
            while (head) {
                std::cout << head->val << " -> ";
                head = head->next;
            }
            std::cout << "Null ";
        }

        T* addNodeBeg(T *head, int value)
        {
            if (!head) {
                head->val = value; 
            }
            T *node = new T(value);
            node->next = head;
            head->prev = node;

            head = node;
            return head;
        }

        T* reverse(T *head)
        {
            if (!head || !head->next) {
                std::cout << "List is not available for reversal"; 
            }
            T *temp = nullptr, *cur = head;
            
            while (cur) {
                temp = cur->prev;
                cur->prev = cur->next;
                cur->next = temp;
                head = cur;
                cur = cur->prev;
            }

            return head;
        }

        void removeNthFromEnd(T *&head, int n) 
        {
            if (!head || !n) {
                return; 
            }

            T *cur = head, *temp, *prev = nullptr;

            if (n == 1) {
                head = cur->next;
                delete cur;
                return;
            }
            
            for (int i = 0; i < n-1; i++) {
                if (cur == nullptr) {
                    return;
                }

                prev = cur;
                cur = cur->next;
            }
            
            temp = cur->next;

            delete cur;

            prev->next = temp;
        }

        void reverseMiddle(T *&head, int left, int right)
        {
            // Check for base cases
            if (!head || !head->next || left == right) {
                return;
            }
            
            // set a dummy variable as a new node and init a prev variable to increment
            T *cur = head, *dummy = new T(), *prev;

            // set the head as the next node for the dummy variable
            dummy->next = head;

            // declare the previous node (to be incremented as the dummy node)
            prev = dummy;
            
            // increment prev to the node prior to where we want to reverse
            for (int i = 0; i < left-1; i++) {
                prev = cur->next;
            }
            
            // set the starting node
            cur = prev->next;

            // increment according to the space you want to reverse (right-left)
            for (int i = 0; i < right-left; i++) {
                // create new temp variable to store the next node
                T *temp = prev->next;

                // reverse starting node with the following node 
                prev->next = cur->next;

                // increment the current node
                cur->next = cur->next->next;

                // increment the previous node
                prev->next->next = temp;
            }
            


            // return the head of the linked list
            head = dummy->next;
            delete dummy;

        }

        bool isPalandrome(T *head)
        {
            // base cases
            if (!head || !head->next) {
                return false; 
            }
            
            T *fast = head, *slow = head, *prev = nullptr;
            // move slow pointer to the middle and fast pointer to the end of the linked list
            while (fast && fast->next) 
            {
               fast = fast->next->next;
               slow = slow->next;
            }

            if (fast != nullptr && fast->next == nullptr) {
                slow = slow->next;
            }
            
            // reverse from middle to end of linked list
            while (slow->next)
            {
                T *temp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = temp;
            } 
            
            if (slow != nullptr) {
                slow->next = prev;
            }

            fast = head;
            // compare one end of the linked list to the other end
            while (slow && fast) {
                if (fast->val != slow->val) {
                    return false; 
                }
                slow = slow->next;
                fast = fast->next;
            }

            return true;
        }
};


int main()
{
    LinkedList<ListNode> sol;
    ListNode *head = new ListNode(1);
    ListNode *a = sol.addNodeBeg(head, 2);
    ListNode *b = sol.addNodeBeg(a, 2);
    ListNode *c = sol.addNodeBeg(b, 1);

   // sol.reverseMiddle(c, 1, 2);

    sol.removeNthFromEnd(c, 1);
    sol.showList(c);
   // bool pal = sol.isPalandrome(c);
    //std::cout << pal << '\n' << std::endl;
    
    return 0;
}

// temp <-> cur <-> 2 <-> 3 <-> null
