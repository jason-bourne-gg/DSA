class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        // Node* newHead = new Node(head->val);
        map<Node*, Node*> m{{NULL, NULL}}; 
        //stores the original memeory location with new list's memory location
        Node* it = head;

        // setting up the structure of the list
        while(it != NULL) {
            m[it] = new Node(it->val);
            it = it->next;
        }

        // setting up .next and .random in the new list
        it = head;
        Node* newIt;
        while(it != NULL) {
            newIt = m[it];
            newIt->next = m[it->next];
            newIt->random = m[it->random];
            it = it->next;
        }
        return m[head];
    }
};