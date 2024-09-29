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

/* CODE TO DELETE ONLY EXTRA DUPLICATES KEEPING ATLEAST 1 DUPLICATE INTACT */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};

/* CODE TO DELETE ALL DUPLICATES */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *current = head;
        ListNode *prev = dummy;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                while (current->next != nullptr && current->val == current->next->val)
                {
                    current = current->next;
                }
                prev->next = current->next;
            }
            else
            {
                prev = prev->next;
            }
            current = current->next;
        }
        return dummy->next;
    }
};