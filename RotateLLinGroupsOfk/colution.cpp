#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with getLen and reverseKGroup functions
class Solution {
public:
    int getLen(ListNode* &head) {
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;

        if (k > getLen(head)) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* fwd = nullptr;

        int count = k;
        while (count > 0 ){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count--;
        }

        if (fwd != nullptr) {
            head->next = reverseKGroup(fwd, k);
        }

        return prev;
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    // Print original linked list
    cout << "Original linked list: ";
    printLinkedList(head);
    
    // Reverse the linked list in groups of 2
    int k = 2;
    ListNode* reversedHead = solution.reverseKGroup(head, k);
    
    // Print reversed linked list
    cout << "Reversed linked list in groups of " << k << ": ";
    printLinkedList(reversedHead);

    return 0;
}
