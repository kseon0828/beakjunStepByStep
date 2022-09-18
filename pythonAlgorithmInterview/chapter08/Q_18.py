class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def oddEvenList(self, head):
        odd = head
        even = head.next
        # 짝수 맨앞을 홀수 맨 뒤의 next와 연결시키기 위해 미리 만들어둠
        even_head = head.next

        while even and even.next:
            odd.next, even.next = odd.next.next, even.next.next
            odd, even = odd.next, even.next

        odd.next = even_head
        return head