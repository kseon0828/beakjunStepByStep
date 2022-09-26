import collections


class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap(object):

    def __init__(self):
        self.size = 1000
        #ListNode를 담게 될 table 생성
        self.table = collections.defaultdict(ListNode)

    def put(self, key, value):
        index = key%self.size
        #table의 해당 index에 값이 없으면 삽입
        #존재하지 않는 인덱스의 경우 defauldict를 사용했기 때문에 빈 ListNode를 생성함
        #따라서 None인지 확인을 해야함
        if self.table[index].value is None:
            self.table[index] = ListNode(key, value)
            return

        #해시 충돌이 난 경우 개별 체이닝 방식으로 해결
        p = self.table[index]
        while p:
            if p.key == key:
                p.value = value
                return
            if p.next is None:
                break
            p = p.next
        p.next = ListNode(key, value)

    def get(self, key):
        index = key%self.size
        #해당 인덱스에 값이 존재하지 않으면 -1
        if self.table[index].value is None:
            return -1
        p = self.table[index]
        while p:
            if p.key == key:
                return p.value
            p = p.next
        return -1

    def remove(self, key):
        index = key%self.size
        #인덱스에 값이 없는 경우 끝
        if self.table[index].value is None:
            return
        p = self.table[index]
        #첫번째 노드 삭제
        if p.key==key:
            self.table[index] = ListNode() if p.next is None else p.next
            return
        #연결 리스트 노드 삭제
        prev = p
        while p:
            if p.key == key:
                prev.next = p.next
                return
            prev, p = p, p.next