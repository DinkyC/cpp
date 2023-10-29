#include <iostream>

template<typename T>
struct ListNode 
{
    T val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *pNext) : val(x), next(pNext), prev(nullptr) {}
    ListNode(int x, ListNode *pNext, ListNode *pPrev) : val(x), next(pNext), prev(pPrev) {}
};

template<typename T>
class LinkedList {
    public:
        void showList(ListNode<T> *head)
        {
            if (head == nullptr) {
                return; 
            }

            ListNode<T> *cur = head;
            while (cur != nullptr) {
                std::cout << cur->val << " -> ";
                cur = cur->next;
                if (cur == nullptr) {
                    std::cout << " NULL" << std::endl;
                }
            }
        }

        void insertEnd(ListNode<T> *&head, int data)
        {
            ListNode<T> *newdata = new ListNode<T>(data);

            if (head == nullptr) {
                head = newdata;
            }

            ListNode<T> *cur = head;
            while (cur->next != nullptr) {
                cur = cur -> next;
            }
            newdata->next = nullptr;  
            cur->next = newdata;
            newdata->prev = cur;
        }
        
        void deleteNodeBeg(ListNode<T> **head)
        {
           ListNode<T> *cur = *head;
           *head = (*head)->next;
           delete cur;
        }

        void deleteNode(ListNode<T> **head, int key)
        {
            ListNode<T> *cur = *head;
            ListNode<T> **prev = head;

            if (key == 1) {
                *head = (*head)->next;
                (*head)->prev = nullptr;
                delete cur;
                return;
            }

            for (int i=0; i < key-1; i++) {
                prev = &(cur->next);
                cur = cur -> next;
            }

            *prev = cur -> next;
            if (cur->next != nullptr) {
                cur->next->prev = cur->next;
            } 

            delete cur;
            
        }

        void deleteList(ListNode<T> **head)
        {
            ListNode<T> *temp = *head;
            while (*head) {
                *head = (*head)->next;
                delete temp;
                temp = *head;
            }
            std::cout << "\ndeleted whole list!" << std::endl;
        }

        ListNode<T>* reverse(ListNode<T> *head)
        {
            if (!head || !head->next) {
                std::cout << "No list available to reverse. Please add (more nodes)\n"; 
            }
            
            ListNode<T> *cur = head, *temp = nullptr;
            
            while (cur) {
                temp = cur->prev;
                cur->prev = cur->next;
                cur->next = temp;
                head = cur;
                cur = cur->prev;
            }
            
            return head;
        }

        ListNode<T>* reverseFromKey(ListNode<T> *head, int left, int right)
        {
            ListNode<T> *dummy = nullptr, *cur = head, *prev = nullptr;

            return dummy->next;
        }

        bool isPalindrome(ListNode<T> *head)
        {
            // base cases
            if(head == nullptr || head->next == nullptr) {
                return false;
            }

            // Initialize fast and slow pointer
            ListNode<T> *fast = head, *slow = head, *prev, *temp;
            
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
           
            // Move slow directly in the middle
            if (fast != nullptr && fast->next == nullptr) {
                slow = slow->next; 
            }

            // reverse from the middle
            temp = nullptr;
            prev = nullptr;
            while (slow && slow->next) {
                temp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = temp;
            }

            // Tie everything together
            if (slow != nullptr) {
                slow->next = prev;
            }
            
            // Check if both of the sides are equal
            fast = head;
            while (slow && fast) {
                if (slow->val != fast->val) {
                    return false;
                }
                slow = slow->next;
                fast = fast->next;
            }
            // compare against each side
            return true;
        }
};  

int main()
{
    LinkedList<int> list;

    ListNode<int> *a = new ListNode<int>(1);
    list.insertEnd(a, 2);
    list.insertEnd(a, 2);
    list.insertEnd(a, 1);
    //list.insertEnd(a, 4);

   /*  list.deleteNode(&a, 5); */
   /*  list.deleteNodeBeg(&a); */
   // ListNode<int> *new_head = list.reverse(a);
    list.showList(a);
    
    bool answer =list.isPalindrome(a);
    std::cout << "\n" << answer << std::endl;

    list.deleteList(&a);
}
