# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        carry = 0
        dummy = ListNode(-1)
        head = dummy
        while l1 and l2:
            tmp = l1.val + l2.val + carry
            carry = tmp/10
            head.next = ListNode(tmp%10)
            head = head.next
            l1 = l1.next
            l2 = l2.next

        #if l1 and not l2:
        while l1:
            tmp = l1.val + carry
            carry = tmp/10
            head.next = ListNode(tmp%10)
            head = head.next
            l1 = l1.next

        # if l2 and not l1:
        while l2:
            tmp = l2.val + carry
            carry = tmp/10
            head.next = ListNode(tmp%10)
            head = head.next
            l2 = l2.next

        if carry == 1:
            head.next = ListNode(1)
        return dummy.next
