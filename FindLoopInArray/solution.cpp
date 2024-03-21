#include <iostream>
#include <unordered_set> // For cycle creation
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class with hasCycle function
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

// Helper function to create a linked list with or without cycle
ListNode* createLinkedList(bool hasCycle) {
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;

    // Create a linked list with a cycle
    if (hasCycle) {
        for (int i = 2; i <= 5; ++i) {
            curr->next = new ListNode(i);
            curr = curr->next;
            if (i == 3) cycleNode = curr; // Store the node where the cycle begins
        }
        curr->next = cycleNode; // Create a cycle
    }
    // Create a linked list without a cycle
    else {
        for (int i = 2; i <= 5; ++i) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    Solution solution;
    // Test with a linked list without a cycle
    ListNode* headWithoutCycle = createLinkedList(false);
    cout << "Linked list without cycle: " << (solution.hasCycle(headWithoutCycle) ? "Has cycle" : "No cycle") << endl;

    // Test with a linked list with a cycle
    ListNode* headWithCycle = createLinkedList(true);
    cout << "Linked list with cycle: " << (solution.hasCycle(headWithCycle) ? "Has cycle" : "No cycle") << endl;

    return 0;
}
