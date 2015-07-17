# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        prev = None
        cur_next = None
        cur = head;
        while(cur):
            cur_next = cur.next
            cur.next = prev
            prev = cur
            cur = cur_next
        return prev
        
        