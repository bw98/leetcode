#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


struct cmp { 
    bool operator() (const ListNode* a, const ListNode* b) 
    {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, cmp> pQueue;
        
        ListNode* lnode;
        for (auto c : lists) {
            lnode = c;
            while (lnode) {
                pQueue.push (lnode);
                lnode = lnode->next;
           }
        }
        
        if (pQueue.empty()) return NULL;
            
        ListNode *head, *p, *q;
        head = p = pQueue.top(); pQueue.pop();
        head->next =  p->next = NULL; //initialize first node of new linklist
        while (!pQueue.empty()) {           
            q = pQueue.top(); pQueue.pop();
            q->next = NULL; //broken pointer which was set previously
            p->next = q;
            p = q;
        }
        return head;
    }
};

int main (void) {
    ListNode *p1 = new ListNode(-1);
    ListNode *p2 = new ListNode(-1);
    ListNode *p3 = new ListNode(-1);
    ListNode *q1 = new ListNode(-2);
    ListNode *q2 = new ListNode(-2);
    ListNode *q3 = new ListNode(-1);
    p1->next = p2;
    p2->next = p3;
    q1->next = q2;
    q2->next = q3;
    vector<ListNode*> lists = {p1, q1};
    Solution *sample = new Solution();
    ListNode* new_sorted_list = sample->mergeKLists(lists);
    while (new_sorted_list) {
        cout << new_sorted_list->val << " ";
        new_sorted_list = new_sorted_list->next;
    }
    cout << endl;
}

