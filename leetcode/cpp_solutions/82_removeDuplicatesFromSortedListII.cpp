class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int cur = head->val;
        ListNode* prev = dummy;
        ListNode* pprev = prev;
        ListNode* ptr = head->next;
        int count = 1;
        while(ptr){
            if(ptr->val == cur){
                count++;
                if(prev->val == cur){
                    pprev->next = NULL;
                    prev = pprev;
                }
            }
            else{
                if (count>1){
                    prev->next = ptr;
                }
                cur = ptr->val;
                count = 1;
                pprev = prev;
                prev = prev->next;
            }
            ptr = ptr->next;
        }
        if (count > 1){
            prev->next = ptr;
        }
        return dummy->next;
    }
};