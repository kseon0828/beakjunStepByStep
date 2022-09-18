class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(self, head):
    node, prev = head, None

    while node:
        #next는 일종의 temp
        #prev가 node.next로, node.next가 node로, node가 prev로 되어 역순으로 뒤집음
        next, node.next = node.next, prev
        prev, node = node, next

    return prev

#연결 리스트를 파이썬의 리스트로 변경
def toList(self, node):
    list = []
    while node:
        list.append(node.val)
        node = node.next
    return list

#파이썬 리스트를 연결 리스트로 변경
def toReversedLinkedList(self, result):
    prev = None
    for r in result:
        node = ListNode(r)
        node.next = prev
        prev = node
    return node

def addTwoNumbers(self, l1, l2):
    a = self.toList(self.reverseList(l1))
    b = self.toList(self.reverseList(l2))

    resultStr = int(''.join(str(e) for e in a)) + int(''.join(str(e) for e in b))

    return self.toReversedLinkedList(str(resultStr))