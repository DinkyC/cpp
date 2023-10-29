/* 

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

*/

#include <bits/stdc++.h> // all of the standard library
#include <cstddef>
#include <iostream>
#include <memory>
                         
struct ListNode // intialize a list with nodes -- Intialized to null 
{
    int val;
    std::unique_ptr<ListNode> next;
    ListNode *prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {} 
};

class linkedList
{
    public:

        // Insert at the beginning
        void push(std::unique_ptr<ListNode>& head, int int_data) // needs to be a double pointer because the address is getting changed for the head
        {
            std::unique_ptr<ListNode> new_node = std::make_unique<ListNode>(int_data); // allocate memory
            
            new_node -> next = std::move(head); // dereferencing head ptr
            ListNode* cur = head.get();
            new_node -> prev = cur;

            head = std::move(new_node);
        }

        // Insert at the end 
        void append(std::unique_ptr<ListNode>& head, int int_data)
        {
            std::unique_ptr<ListNode> new_node = std::make_unique<ListNode>(int_data);

            new_node -> next = std::move(nullptr);

            if (!head) // If the head is a nullptr, then list it as empty
            {
                head = std::move(new_node);
                return;
            }

            ListNode *cur = head.get(); // use a raw pointer to traverse the linked list
            while (cur -> next){
                cur = cur -> next.get();
            }
            new_node->prev = cur;
            cur -> next = std::move(new_node); // only use move when you are ready for assignment
        }
        
        void deleteNode(std::unique_ptr<ListNode>& head, int key)
        {
            if (!head)
                return;

            // If head node holds the key to be deleted
            if (head->val == key)
            {
                head = std::move(head->next);
                return;
            }

            // Search for the key to be deleted and keep track of the previous node
            std::unique_ptr<ListNode>* current = &head;
            ListNode* prev = nullptr;
            while (*current && (*current)->val != key)
            {
                prev = current->get();
                current = &((*current)->next);
            }

            // If key was not present in the list
            if (!*current)
                return;

            // Unlink the node from the list
            if (prev)
            {
                prev->next = std::move((*current)->next);
            }
        }

        bool hasCycle(std::unique_ptr<ListNode>& head)
        {
            if (!head)
                return false;

            ListNode* fast = head.get();
            ListNode* slow = head.get();

            while (fast != nullptr && fast->next != nullptr) 
            {
                fast = (fast->next) ? fast->next->next.get() : nullptr;
                slow = slow->next.get();

                if (fast == slow)
                    return true;
            }

            return false;
        }


        void display(const std::unique_ptr<ListNode>& node)
        {
            ListNode* cur = node.get();
            // This is under the assumption that it is a single linked list
            while (cur != nullptr){
                std::cout << cur -> val << " --> "; // While the linked list is not empty access the data 
                cur = cur -> next.get();
            }

            if (cur == nullptr){
                std::cout << "null" << std::endl; 
            }
        }
};

int main()
{
    linkedList node;

    std::unique_ptr<ListNode> head = nullptr;

    node.push(head, 19);

    node.push(head, 20);
    
    node.append(head, 30);

    node.append(head, 40);

    node.deleteNode(head, 40);

    node.display(head);

    if (node.hasCycle(head))
        std::cout << "True" << std::endl;

    return 0;
}
