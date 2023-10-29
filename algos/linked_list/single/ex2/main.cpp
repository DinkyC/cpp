#include <iostream>

/*
 * Given the head of a singly linked list and two integers left and right 
 * where left <= right, reverse the nodes of the list from position left 
 * to position right, and return the reversed list.
 * 
 * Input: head = [1,2,3,4,5],
 *
 * left = 2, right = 4
 *
 * Output: [1,4,3,2,5]
 *
 */

// Definition of a singly linked list

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseLList(ListNode *head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *forward = head -> next;
            head -> next = prev;
            prev = head;
            head = forward;
       } 

        return prev;
    }

    ListNode* reverseBetween(ListNode *head, int left, int right) {
        // Base cases
        if (!head || head -> next == nullptr || left == right) {
            return head; 
        }

        // Create a null dummy node
        ListNode *dummy = new ListNode(0), *prev = dummy, *current;
        dummy -> next = head;

        for (int i=0;i < left-1 ;i++) {
            prev = prev -> next;
        }
        
        current = prev -> next;

        for (int i=0; i < right - left; i++) {
            ListNode *temp = prev -> next;
            prev -> next = current -> next;
            current -> next = current -> next -> next;
            prev -> next -> next = temp; 
        }
        
        return dummy -> next;

        delete dummy;
    }

    /*
     * head = [1,2,2,1]
     * reversed = [1,2,2,1]
     * return = true 
     */

    bool isPalindrome(ListNode* head) {
        // Base cases
        if (!head || head -> next == nullptr) {
            return false; 
        }
        
        // initialize values
        ListNode *fast = head, *slow = head, *prev, *temp;

        // move slow pointer to the middle and fast pointer to the end
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // reverse from the middle
        prev = nullptr;
        while (slow) {
        
        }



        return true;
    }
};

int main()
{
    Solution sol;

    ListNode* b = new ListNode(2, nullptr);
    ListNode* c =  new ListNode(3, b);
    ListNode* d = new ListNode(4, c);
    ListNode* head = new ListNode(5, d);
    
    int left { 2 };
    int right { 4 };

    ListNode *current = sol.reverseBetween(head, left, right);

    while (current != nullptr) {
        std::cout << current -> val << " -> "; 
        if (current -> next == nullptr) {
            std::cout << "Null";
        }
        current = current -> next;
    
    }

    delete b;
    delete c;
    delete d;
    delete head;

    return 0;
}
