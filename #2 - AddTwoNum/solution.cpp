class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = l1->val + l2->val;
        int add = val / 10;
        ListNode* res = new ListNode(val % 10);
        ListNode *cur = res, *rear;
        l1 = l1->next;
        l2 = l2->next;
        bool lnull = !(l1), rnull = !(l2);

        while (!lnull || !rnull) {
            int lval = 0, rval = 0;
            if (!lnull) {
                lval = l1->val;
                l1 = l1->next;
                lnull = !(l1);
            }
            if (!rnull) {
                rval = l2->val;
                l2 = l2->next;
                rnull = !(l2);
            }
            val = lval + rval + add;
            add = val / 10;

            rear = new ListNode(val % 10);
            cur->next = rear;
            cur = rear;
        }
        if (add != 0) {
            rear = new ListNode(add);
            cur->next = rear;
        }

        return res;
    }
};