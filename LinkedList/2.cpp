//Runtime: 45 ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1, *p2, *p3, *t3, *l3Head;
        p1 = l1;
        p2 = l2;
        l3Head = NULL;
        while((p1!=NULL) && (p2!=NULL)) {
            p3 = new ListNode(p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
            if(l3Head == NULL) {
                t3 = l3Head = p3;
            }
            else{
                t3->next = p3;
                t3 = p3;
            }
        }
        while(p1 != NULL) {
            p3 = new ListNode(p1->val);
            t3->next = p3;
            t3 = p3;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            p3 = new ListNode(p2->val);
            t3->next = p3;
            t3 = p3;
            p2 = p2->next;
        }
        
        p3 = l3Head;         
        while(p3 != NULL) {
            if(p3->val >= 10) {
                p3->val = p3->val % 10;
                if(p3->next == NULL) {
                    p3->next = new ListNode(1);
                }
                else {
                   p3->next->val = p3->next->val + 1;
                }
            }
            p3 = p3->next;
        }
        
        return l3Head;
    }
};
