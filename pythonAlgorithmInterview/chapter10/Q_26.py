class ListNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class MyCircularDeque(object):

    def __init__(self, k):
        """
        :type k: int
        """
        #head와 tail 투포인터로 두개의 리스트 노드 생성
        self.head, self.tail = ListNode(None), ListNode(None)
        #데크 사이즈 k 지정, 현재 데크 길이 0
        self.k, self.len = k, 0
        #head와 tail 연결
        self.head.right, self.tail.left = self.tail, self.head

    def _add(self, node, new):
        #node를 기준으로 오른쪽에 삽입
        n = node.right
        node.right = new
        new.left, new.right = node, n
        n.left = new

    def _del(self, node):
        #node 기준으로 오른쪽 삭제
        n = node.right.right
        node.right = n
        n.left = node

    def insertFront(self, value):
        #데크가 꽉 찼을 경우 false 반환
        if self.len == self.k:
            return False
        #삽입 시 len 추가
        self.len += 1
        self._add(self.head, ListNode(value))
        return True

    def insertLast(self, value):
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.tail.left, ListNode(value))
        return True


    def deleteFront(self):
        if self.len == 0:
            return False
        self.len -=1
        self._del(self.head)
        return True

    def deleteLast(self):
        if self.len == 0:
            return False
        self.len -=1
        self._del(self.tail.left.left)
        return True

    def getFront(self):
        if self.len:
            return self.head.right.val
        else:
            return -1

    def getRear(self):
        if self.len:
            return self.tail.left.val
        else:
            return -1

    def isEmpty(self):
        return self.len == 0

    def isFull(self):
        return self.len == self.k
