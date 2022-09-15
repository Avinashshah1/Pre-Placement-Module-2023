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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode;
        int carry=0;
        l3->val=(l1->val + l2->val + carry) % 10;
        carry=l1->val + l2->val + carry > 9 ? (l1->val + l2->val + carry)/10 : 0;
        
        
        l1=l1->next;
        l2=l2->next;
        ListNode *x=l3;
        while(l1 && l2){
            ListNode *p=new ListNode;

            p->val=(l1->val + l2->val + carry) % 10;
            carry=l1->val + l2->val + carry > 9 ? (l1->val + l2->val + carry)/10 : 0;
            
            p->next=nullptr;
            x->next=p;
            l1=l1->next;
            l2=l2->next;
            x=x->next;
        }
        
        while(l1){
            ListNode *p=new ListNode;

            p->val=(l1->val + carry) % 10;
            carry=l1->val + carry > 9 ? (l1->val + carry)/10 : 0;
            
            p->next=nullptr;
            x->next=p;
            l1=l1->next;
            x=x->next;
        }
        
        while(l2){
            ListNode *p=new ListNode;

            p->val=(l2->val + carry) % 10;
            carry=l2->val + carry > 9 ? (l2->val + carry)/10 : 0;
            
            p->next=nullptr;
            x->next=p;
            l2=l2->next;
            x=x->next;
        }
        
        if(carry>0){
            ListNode *p=new ListNode;
            p->val=carry;
            p->next=nullptr;
            x->next=p;
        }
        return l3;
    }
};