class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;

        ListNode* result = nullptr;
        ListNode* back = nullptr;

        while (l1 || l2) {

            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            // First node
            if (!result) {
                result = newNode;
                back = newNode;
            }
            else {
                back->next = newNode;
                back = newNode;
            }

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        // Remaining carry
        if (carry) {
            back->next = new ListNode(carry);
        }

        return result;
    }
};