int getLength(ListNode *head){
int len = 0;
while( head != NULL ){
++len; head = head->next;
}
return len;
}

ListNode * reorderList(ListNode *head, int len){
    if(len == 0)
        return NULL;
    if( len == 1 )
        return head;
    if( len == 2 )
        return head->next;
    ListNode * tail = reorderList(head->next, len-2);
    ListNode * tmp = tail->next;
    tail->next = tail->next->next;
    tmp->next = head->next;
    head->next = tmp;
    return tail;
}

void reorderList(ListNode *head) {  //recursive
    ListNode  * tail = NULL;
    tail = reorderList(head, getLength(head));
}