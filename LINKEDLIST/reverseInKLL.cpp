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
public:
    int getLen(ListNode *&head)
    {
        int len = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return head;

        if (k > getLen(head))
        {
            return head;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *fwd = NULL;

        int count = 0;
        while (count < k)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }

        if (fwd != NULL)
        {
            head->next = reverseKGroup(fwd, k);
        }

        return prev;
    }
};