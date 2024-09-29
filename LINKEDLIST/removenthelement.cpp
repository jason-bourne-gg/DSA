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
    int getListLength(ListNode *head)
    {
        if (head == NULL)
            return 0;
        int count = 0;

        while (head != NULL)
        {
            head = head->next;
            count++;
        }
        return count;
    };

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = getListLength(head);

        if (len == 1 && n == 1)
        {
            delete head;
            return nullptr;
        }

        // remove the last element
        if (n == 1)
        {
            ListNode *temp = head;
            for (int i = 1; i < len - 1; i++)
            {
                temp = temp->next;
            };
            temp->next = nullptr;
        }
        else if (n == len)
        { // remove 1st element in list
            ListNode *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else
        { // remove any middle element
            ListNode *temp = head;
            for (int i = 0; i < len - n - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

        return head;
    }
};