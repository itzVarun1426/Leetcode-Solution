class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* back = dummy;
        ListNode* tempL1 = l1;
        ListNode* tempL2 = l2;

        while (tempL1 || tempL2 || carry) {
            int tempSum = carry;
            if(tempL1){
                tempSum+= tempL1->val;
                tempL1 = tempL1->next;
            }
            if(tempL2){
                tempSum+= tempL2->val;
                tempL2 = tempL2->next;
            }
            ListNode* newNode = new ListNode(tempSum%10);
            carry = tempSum/10;
            back->next = newNode;
            back = back->next; 
        }
        return dummy->next;

    }
};