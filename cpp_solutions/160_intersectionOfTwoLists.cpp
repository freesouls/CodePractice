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
    // the speed if the same as getIntersection2()
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* B = headB, *A = headA;
        int lenB = 0, lenA = 0;
        while(B){
            lenB++;
            B = B->next;
        }
        while(A){
            lenA++;
            A = A->next;
        }
        B = headB, A = headA;
        if (lenA < lenB){
            for(int i = 0; i < lenB-lenA; i++){
                B = B->next;
            }
        }
        else{
            for(int i = 0; i < lenA-lenB; i++){
                A = A->next;
            }
        }
        while(A != NULL){
            if (A == B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* B = headB, *A = headA;
        ListNode* tail_A = NULL, *tail_B = NULL;
        while(1){
            if (A == NULL){
                A = headB;
            }
            if (B == NULL){
                B = headA;
            }
            if (A->next == NULL){
                tail_A = A;
            }
            if (B->next == NULL){
                tail_B = B;
            }
            
            if (tail_A != NULL && tail_B != NULL && tail_A != tail_B){
                return NULL;
            }
            
            if (A == B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
        
        return NULL; // never 
    }
    
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        unordered_set<ListNode*> q;
        ListNode* B = headB, *A = headA;
        while(A != NULL){
            q.insert(A);
            A = A->next;
        }
        while(B != NULL){
            unordered_set<ListNode*>::iterator it = q.find(B);
            if (it != q.end()){
                return *it;
            }
            B = B->next;
        }
        return NULL;
    }
};