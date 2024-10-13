/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    // Merge two sorted linked lists
    ListNode *MergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(0); // Temporary dummy node
        ListNode *curr = temp;            // Pointer to build the merged list

        // Merge while both lists have elements
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Append remaining elements if one list is exhausted
        if (l1 != nullptr)
        {
            curr->next = l1;
        }
        if (l2 != nullptr)
        {
            curr->next = l2;
        }

        return temp->next; // Return the merged list, skipping dummy node
    }

public:
    // Sort the linked list using merge sort
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head; // Base case: if list is empty or has one element
        }

        // Use two pointers to find the middle of the list
        ListNode *temp = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow one step and fast two steps to split the list into two halves
        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr; // Split the list into two halves

        // Recursively sort the two halves
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        // Merge the sorted halves
        return MergeList(l1, l2);
    }
};
