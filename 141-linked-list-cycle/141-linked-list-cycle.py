# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        if head == None or head.next == None:
            return False
        
        slow = head
        fast = head.next
        
        while fast:
            if slow == fast:
                return True
            
            slow = slow.next
            if fast.next == None:
                return False
            else:
                fast = fast.next.next
        
        return False
        