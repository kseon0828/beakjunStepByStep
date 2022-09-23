class Solution:
    def isVaild(self, s):
        stack = []

        #s에서 우괄호를 만나면 스택에서 pop 했을 때, 좌괄호가 나와야 하므로
        #우괄호 : 좌괄호 이렇게 매핑이 되어야 함
        mapping_tabel = {
            ')':'(',
            '}':'{',
            ']':'['
        }

        for char in s:
            #좌괄호인 경우 stack에 push 되어야 함 (, {, [
            #따라서 좌괄호인지 판단하는 것은 mapping_tabel에 키로 존재하지 않으면 됨
            if char not in mapping_tabel:
                stack.append(char)
            #위에 if를 통과하면 좌괄호가 아닌 경우임
            #따라서 우괄호의 경우 stack을 pop 해서 맞는 짝꿍이면 true
            #짝꿍이 아니거나 stack에 아무것도 존재하지 않을 때 false 반환
            elif not stack or mapping_tabel[char] != stack.pop():
                return False
            #위의 과정을 다 거치고 stack이 비어있으면 괄호가 유효함
        return len(stack)==0

s = Solution
print(s.isVaild(s, "()"))