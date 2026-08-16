/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* IsLoop(ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return slow;
            }
        }
        return NULL;
    }
    ListNode* detectCycle(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode *slow = NULL, *fast = IsLoop(head);
        if (fast == NULL)
            return NULL;
        else {
            slow = head;
            while (fast != slow) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
};