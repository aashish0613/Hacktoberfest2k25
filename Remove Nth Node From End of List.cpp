class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
ListNode *fast=head,*slow=head;
for(int i=0;i<n;i++){
fast=fast->next;
}
if(fast==NULL){
head=head->next;
delete slow,fast;
}else{
while(fast->next!=NULL){
fast=fast->next;
slow=slow->next;
}
ListNode *temp=slow->next;
slow->next=slow->next->next;
delete temp,slow,fast;
}
return head;
}
};
