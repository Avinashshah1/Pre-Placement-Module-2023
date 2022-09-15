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
    ListNode* reverseKGroup(ListNode* head, int k) {
     ListNode *r=nullptr,*q=nullptr,*p=head;
     int temp=0;
     ListNode *x=head;
     while(x!=nullptr){
         x=x->next;
         temp++;
     }
     if(temp<k)
         return head;
     int count=0;
     while(count<k){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        count++;
     }
     if(p!=nullptr){
        ListNode* rest_head=reverseKGroup(p,k);
        head->next=rest_head;
     }
     return q;
    }
};