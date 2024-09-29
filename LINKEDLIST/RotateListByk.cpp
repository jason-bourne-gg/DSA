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
    int getListlength(ListNode *head)
    {
        if (head == nullptr)
            return 0;
        int count = 0;

        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *rotateListRightByOnePlace(ListNode *head, int length)
    {
        // Find the second-to-last node (new tail after rotation)
        ListNode *temp = head;
        for (int i = 1; i < length - 1; i++)
        {
            temp = temp->next;
        }

        // Get the last node (current tail) and set it as the new head
        ListNode *newHead = temp->next; // This is the last node (current tail)
        newHead->next = head;           // Point it to the old head
        temp->next = nullptr;           // Break the link to make temp the new tail

        return newHead; // Return the new head
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr; // Check for empty list
        int len = getListlength(head);
        if (len == 0)
            return head; // Check if length is zero
        k = k % len;     // actual number of rotations
        if (k == 0)
            return head; // No rotation needed

        ListNode *newHead;
        while (k--)
        {
            newHead = rotateListRightByOnePlace(head, len);
            head = newHead; // Update head for the next rotation
        }

        return newHead;
    }
};