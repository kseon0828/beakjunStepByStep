n, m = map(int, input().split())

res = float('inf')
home=[]
chicken = []

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        if(row[j]==1): home.append((i,j))
        elif(row[j]==2) : chicken.append((i,j))

checked = [False]*(len(chicken)+1)

def dfs(idx, cnt):
    #idx는 chicken리스트에서 어느 치킨집이 선택되었는지 표시하는 것
    global res, chicken, m
    if idx >len(chicken):
        return
    if cnt == m:
        total_distance = 0
        #cnt가 m이면, 치킨 거리 계산
        for r1, c1 in home:
            distance = float('inf')
            for i, pos in enumerate(chicken):
                #집으로 부터 가장 가까운 치킨 집이 무엇인지 구해야 하므로,
                #checked가 true면 현재 dfs에 픽된 3개의 치킨 집 중 하나라는 소리
                #따라서 3개의 치킨 집 중에서 가장 현재 집이랑 거리 가장 짧은 것으로 distance를 갱신하여 total에 더함
                if checked[i]:
                    r2, c2 = pos
                    distance = min(distance, abs(r1-r2)+abs(c1-c2))
            total_distance += distance
        res = min(res, total_distance)

    checked[idx] = True
    dfs(idx+1, cnt+1)
    checked[idx] = False
    dfs(idx+1, cnt)

dfs(0, 0)

print(res)
