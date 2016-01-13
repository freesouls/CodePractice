# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        if head is None or head.next is None:
            return True
        
        fast = head
        slow = head
        pre = None
        
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        
        l1 = head
        l2 = pre.next
        pre.next = None
        l2 = self.reverseList(l2)
        
        while l1 and l2:
            if l1.val != l2.val:
                return False
            l1 = l1.next
            l2 = l2.next
        return True
    def reverseList(self, head):
        cur_next = None
        prev = None
        while head:
            cur_next = head.next
            head.next = prev
            prev = head
            head = cur_next
        return prev
