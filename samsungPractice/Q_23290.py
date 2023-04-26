#모든 물고기 복제(기존 그래프 복제하는 과정)
#물고기 이동
    #상어 있는 칸, 물고기 냄새 있는 칸, 범위 벗어나는 칸 이동 불가
#상어 이동
    #제외되는 물고기 수 많은 칸으로 이동
    #이동 경로가 많으면, ↑, →, ↓, ← 이 순서로
    #제외되는 물고기는 물고기 냄새 남김
#2번 전 물고기 냄새 사라지고
#복제 마법
    #기존 물고기 + 복제된 물고기

import copy

def move_fish():
    result = [list([] for _ in range(4)) for _ in range(4)]
    for x in range(4):
        for y in range(4):
            while temp[x][y]: #물고기가 존재하면
                d = temp[x][y].pop() #물고기의 방향 확인
                for i in range(d, d-8, -1) :#반시계 방향으로 한바퀴 돌때까지 탐색
                    i %= 8
                    nx = x + f_dx[i]
                    ny = y + f_dy[i]
                    if (nx, ny) != shark and 0<= nx<4 and 0<=ny<4 and not smell_graph[nx][ny]:
                        result[nx][ny].append(i)
                        break
                else: #for-else문, break로 빠져나오지 않을 때 실행되는 부분
                    result[x][y].append(d) #이동하지 않으면, 원래 위치에 원래 상태로
    return result

def dfs(x, y, dep, cnt, visit):
    global max_eat, shark, eat

    if dep == 3:
        if max_eat < cnt:
            max_eat = cnt
            shark = (x, y)
            eat = visit[:]
        return

    for i in range(4):
        nx = x + s_dx[i]
        ny = y + s_dy[i]

        if 0 <= nx <4 and 0<=ny<4:
            if (nx, ny) not in visit: #방문한 경험이 없으면, temp에 있는 물고기의 수만큼 cnt에 저장
                visit.append((nx, ny))
                dfs(nx, ny, dep+1, cnt+ len(temp[nx][ny]), visit)
                visit.pop()
            else:
                dfs(nx, ny, dep+1, cnt, visit)

m, s = map(int, input().split())
fish_info_list = [list(map(int, input().split())) for _ in range(m)]
shark = tuple(map(lambda x:int(x)-1, input().split()))

#물고기 정보(위치와 방향)를 fish_graph에 넣기
fish_graph = [list([[] for _ in range(4)]) for _ in range(4)]
for x, y, d in fish_info_list:
    fish_graph[x-1][y-1].append(d-1)

smell_graph = [[0]*4 for _ in range(4)]

#물고기 이동 방향
#←, ↖, ↑, ↗, →, ↘, ↓, ↙
f_dx = [0, -1, -1, -1, 0, 1, 1, 1]
f_dy = [-1, -1, 0, 1, 1, 1, 0, -1]
s_dx = [-1, 0, 1, 0]
s_dy = [0, -1, 0, 1]


for _ in range(s):
    max_eat = -1 #반복할 때 마다 상어가 먹은 최대 수
    eat = [] #물고기 냄새를 기록하기 위해 상어가 방문한 곳의 좌표를 담는 리스트

    temp = copy.deepcopy(fish_graph)
    temp = move_fish() #물고기가 이동한 그래프를 temp에 저장

    dfs(shark[0], shark[1], 0, 0, []) #마지막 argument에 [] 리스트 보내는 이유는 dfs에서 [] 초기화하면, 변경된 리스트가 불리지 않고 계속 빈 리스트만 추가

    #eat은 잡아 먹힌 물고기 좌표의 list
    for x, y in eat:
        if temp[x][y]:
            temp[x][y] = []
            smell_graph[x][y] = 3 #3번을 돌아야 냄새가 없어짐

    for i in range(4):
        for j in range(4):
            if smell_graph[i][j]:
                smell_graph[i][j] -= 1

    #복제하기
    for i in range(4):
        for j in range(4):
            fish_graph[i][j] += temp[i][j] #이동한 물고기 그래프 temp를 원본 fish에 추가하기

fish_cnt = 0
for i in range(4):
    for j in range(4):
        fish_cnt += len(fish_graph[i][j])

print(fish_cnt)