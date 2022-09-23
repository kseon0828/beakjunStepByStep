def dailyTemperatuer(T):
    #기온이 더 높은 날이 없을 수 있으므로, 디폴트 0
    answer = [0]*len(T)

    #stack에는 더 높은 온도를 찾지 못한 데이터의 인덱스가 들어감
    stack = []

    #배열을 순차적으로 진행
    for i, cur in enumerate(T):
        #스택 안에 값이 존재하고 현재 값이 스택에 존재하는 데이터 보다 클 때
        #스택은 pop이 되고, 스택과 현재 데이터의 인덱스 차이가 더워지기 기다린 며칠임
        while stack and cur>T[stack[-1]]:
            last = stack.pop()
            #스택에서 나온 인덱스에 기다린 일 수 저장
            answer[last]=i-last
        #위의 과정이 끝나면 스택으로 들어가 더 높은 온도가 있기까지 스택에 존재
        stack.append(i)
    return answer

print(dailyTemperatuer([73, 74, 75, 71, 69, 72, 76, 73]))