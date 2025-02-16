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
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *curr=head->next->next;
        ListNode *prev=head;
        head=head->next;
        head->next=prev;
        while(curr!=nullptr && curr->next!=nullptr){
            prev->next=curr->next;
            prev=curr;
            ListNode *temp=curr->next->next;
            curr->next->next=curr;
            curr=temp;
        }
        prev->next=curr;
        return head;
        
    }
};