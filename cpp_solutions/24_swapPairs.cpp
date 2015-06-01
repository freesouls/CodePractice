class Solution {
public:
     ListNode* swapPairs(ListNode* head) {
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        if (head == NULL){
            return NULL;
        }

        ListNode* p3 = new struct ListNode(0);
        p3->next = head;
        p1 = head;
        ListNode* pre = p3;
        while(p1 != NULL){
            p2 = p1->next;
            if(p2 == NULL){
                break;
            }
            ListNode* tmp = p2->next;
            p1->next = tmp;
            p2->next = p1;
            pre->next = p2;
            pre = p1;
            p1 = tmp;
        }
        
        return p3->next;
    }
};