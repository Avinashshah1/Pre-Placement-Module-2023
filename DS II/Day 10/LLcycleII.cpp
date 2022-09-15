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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)
            return nullptr;
        ListNode *p,*q;
        p=head;
        q=head;
        do{
            p=p->next;
            if(p)
                p=p->next;
            q=q->next;
        }while((p && q) && (p!=q));
        
        if(p==nullptr || q==nullptr)
            return nullptr;
        
        unordered_set<ListNode*> temp;
        ListNode *a=head;
        while(a){
            if(temp.find(a)!=temp.end())
                return a;
            temp.insert(a);
            a=a->next;
        }
        return nullptr;
    }
};