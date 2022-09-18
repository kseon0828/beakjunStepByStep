class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1:ListNode, l2:ListNode):
        #l1가 l2보다 크다면
        if (not l1) or (l2 and l1.val > l2.val):
            #변수 스왑
            l1, l2 = l2, l1
        #l1이 있다면
        #l1의 다음과 l2를 비교하여 l1의 next를 무엇으로 연결할지 확정
        if l1:
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
