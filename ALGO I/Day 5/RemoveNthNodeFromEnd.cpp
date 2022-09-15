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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr)
            return nullptr;
        ListNode *first=head;
        for(int i=0;i<n;i++){
            first=first->next;
        }
        ListNode *second=head,*temp=nullptr;
        while(first!=nullptr){
            first=first->next;
            temp=second;
            second=second->next;
        }
        if(second==head)
            head=second->next;
        else
            temp->next=second->next;
        delete second;
        return head;
        
    }
};