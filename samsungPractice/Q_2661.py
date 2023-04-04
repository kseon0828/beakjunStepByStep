n = int(input())
s = []

def back_tracking(idx):
    #s에 추가된 수가 좋은 수열에 위반되지 않는지 검사하는 부분
    for i in range(1, (idx//2) + 1):
        if s[-i:] == s[-2*i:-i]: return -1

    #idx가 n과 같다면 출력하고 return
    if idx == n:
        for i in range(n): print(s[i], end = '')
        return 0

    #idx가 n보다 작다면 1,2,3을 s에 추가하여
    #back_tracking에 넣으므로 좋은 수열인지 검사
    #만약에 좋은 수열이 아니면, s에서 pop
    for i in range(1, 4):
        s.append(i)
        if back_tracking(idx + 1) == 0:
            return 0
        s.pop()


back_tracking(0)