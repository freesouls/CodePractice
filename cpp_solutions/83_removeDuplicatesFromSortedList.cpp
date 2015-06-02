class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return head;
        }
        
        int cur = head->val;
        ListNode* prev = head;
        ListNode* ptr = head->next;
        int count = 1;
        while(ptr){
            if(ptr->val == cur){
                count++;
            }
            else{
                if (count>1){
                    prev->next = ptr;
                }
                cur = ptr->val;
                count = 1;
                prev = ptr;
            }
            ptr = ptr->next;
        }
        if (count > 1){
            prev->next = ptr;
        }
        return head;
    }
};