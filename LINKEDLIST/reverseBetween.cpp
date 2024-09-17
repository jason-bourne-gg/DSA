class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        // Create a dummy node to handle edge cases like reversing from head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        // Step 1: Move `prev` to the node just before `left`-th position
        for (int i = 1; i < left; ++i)
        {
            prev = prev->next;
        }

        // Step 2: Start reversing from the `left`-th node
        ListNode *curr = prev->next;
        ListNode *next = NULL;

        // Reverse the sublist between `left` and `right`
        for (int i = 0; i < right - left; ++i)
        {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next; // The new head of the list
    }
};
