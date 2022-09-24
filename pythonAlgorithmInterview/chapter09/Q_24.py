class MyQueue(object):

    def __init__(self):
        self.input = []
        #output이 실질적으로 데이터를 pop하는 곳
        self.output = []

    def push(self, x):
        self.input.append(x)

    def pop(self):
        self.peek()
        return self.output.pop()

    def peek(self):
        #output이 없으면 현재 뺄 데이터가 없으므로,
        #input의 데이터를 pop 하면서 output을 만들어줘야됨
        #이때, input도 pop이 되므로 output을 생성할 때 올바른 값들이 들어옴
        #나는 input을 pop하지 않고, 배열의 역순을 사용해서 output을 만들어줬음
        #그래서 input의 값이 삭제는 안되고 추가만 되가지고 매번 output을 peek하면 동일한 데이터가 나왔음
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        return self.output[-1]

    def empty(self):
        return self.input == [] and self.output ==[]