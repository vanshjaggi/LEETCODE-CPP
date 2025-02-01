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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode *prev = &dummy, *cur = head;

        while(cur && cur->next){
            ListNode *middleconnection = cur->next->next;
            ListNode *second = cur->next;
            second->next = cur;
            cur->next = middleconnection;
            prev->next = second;

            prev = cur;
            cur = middleconnection;
        }
        return dummy.next;
    }
};