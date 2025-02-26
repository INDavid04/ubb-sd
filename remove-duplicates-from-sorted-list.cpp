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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current, *n;
        current = head;
        if (current == NULL || current -> next == NULL) {
            return head;
        }
        n = current -> next;
        while (current -> next != NULL) {
            if (current -> val == n -> val) {
                current -> next = n -> next;
                delete n;
                n = current -> next; // n este cel pe care vreau sa il sterg si current este cel pe care sunt
            } else {
                current = n;
                n = n -> next;
            }
        }
        return head;
    }
};
