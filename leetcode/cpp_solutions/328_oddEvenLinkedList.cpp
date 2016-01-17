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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);

        ListNode* oddPtr = oddDummy;
        ListNode* evenPtr = evenDummy;

        ListNode* cur = head;

        bool isOdd = true;
        while(cur != NULL) {
            ListNode* next = cur->next;
            if (isOdd) {
                oddPtr->next = cur;
                oddPtr = oddPtr->next;
                oddPtr->next = NULL;
                // isOdd = false;
            }
            else {
                evenPtr->next = cur;
                evenPtr = evenPtr->next;
                evenPtr->next = NULL;
                // isOdd = true;
            }
            cur = next;
            isOdd = !isOdd;
        }

        oddPtr->next = evenDummy->next;
        return oddDummy->next;
    }
};


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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = head;
        if (head == NULL) {
            return head;
        }

        ListNode* evenHead = head->next;
        if (evenHead == NULL) {
            return head;
        }

        ListNode* oddPtr = oddHead;
        ListNode* evenPtr = evenHead;

        ListNode* cur = head;

        bool isOdd = true;
        while(cur != NULL) {
            ListNode* next = cur->next;
            if (isOdd) {
                oddPtr->next = cur;
                oddPtr = oddPtr->next;
                oddPtr->next = NULL;
                // isOdd = false;
            }
            else {
                evenPtr->next = cur;
                evenPtr = evenPtr->next;
                evenPtr->next = NULL;
                // isOdd = true;
            }
            cur = next;
            isOdd = !isOdd;
        }

        oddPtr->next = evenHead;

        return oddHead;
    }
};


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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = head;
        if (head == NULL) {
            return head;
        }

        ListNode* evenHead = head->next;
        if (evenHead == NULL) {
            return head;
        }

        ListNode* oddPtr = oddHead;
        ListNode* evenPtr = evenHead;

        ListNode* cur = evenHead->next;
        oddPtr->next = NULL;
        evenPtr->next = NULL;

        bool isOdd = true;
        while(cur != NULL) {
            ListNode* next = cur->next;
            if (isOdd) {
                oddPtr->next = cur;
                oddPtr = oddPtr->next;
                oddPtr->next = NULL;
                // isOdd = false;
            }
            else {
                evenPtr->next = cur;
                evenPtr = evenPtr->next;
                evenPtr->next = NULL;
                // isOdd = true;
            }
            cur = next;
            isOdd = !isOdd;
        }

        oddPtr->next = evenHead;

        return oddHead;
    }
};
