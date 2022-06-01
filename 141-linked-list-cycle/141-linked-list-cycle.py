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
        fast = head
        
        while(fast):
            if slow.next:
                slow = slow.next
            else:
                return False
            
            if fast.next:
                fast = fast.next.next
            else:
                return False
            
            if slow == fast:
                return True
        
        return False
        