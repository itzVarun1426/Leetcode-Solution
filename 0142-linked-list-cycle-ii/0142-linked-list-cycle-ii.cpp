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
    bool IsLoop(ListNode* head , ListNode *&slow , ListNode *&fast) {
        slow = head;
        fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return 1;
            }
        }
        return 0;
    }
    ListNode* detectCycle(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode *slow = NULL, *fast = NULL;
        if (IsLoop(head,slow,fast) == 0)
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