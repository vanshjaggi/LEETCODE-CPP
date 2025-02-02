class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head){
            return head;
        }
        ListNode *dumpy = new ListNode(0);
        dumpy->next = head;
        ListNode *pre = dumpy;
        ListNode *cur, *nex;

        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        while(count >= k){
            cur = pre->next;
            nex = cur->next;

            for (int i = 1;i<k;i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;

        }
        return dumpy->next;
    }
};