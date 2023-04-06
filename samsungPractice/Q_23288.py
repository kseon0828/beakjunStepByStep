#주사위가 처음 시작할 때(1,1)에서 이동 방향은 무조건 동쪽
#그리고 두번째 부터 이동 방향은 A와 B의 비교에 따라 결정
    #이동한 각 칸에서 획득할 수 있는 점수를 계산(칸에 있는 수 * 이동할 수 있는 수)
    #각 칸에서 이동할 수 있는 조건은 이동한 칸의 수와 같은 번호가 몇개가 이어져 있는지

from collections import deque

def score_bfs(x , y):
    queue.append((x, y))
    visited[x][y] = True
    c = 1
    b = graph[x][y]

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and graph[nx][ny] == b:
                    visited[nx][ny] = True
                    queue.append((nx, ny))
                    c += 1

    score = c*b
    return score

def move_dice(x, y, dir_num):
    #주사위 전개도에 대한 부분과
    #A(dice[5]), B(graph[x][y])를 비교해 다음 이동 방향의 좌표 반환하는 부분 필요

    if not 0<= x + dx[dir_num] <n or not 0<= y+dy[dir_num]<m: #범위를 벗어나면, 반대로 이동
        dir_num = (dir_num + 2) %4

    nx = x + dx[dir_num]
    ny = y + dy[dir_num]

    if dir_num == 0:
        dice[2], dice[0], dice[3], dice[5] = dice[0], dice[3], dice[5], dice[2]
    elif dir_num == 1:
        dice[1], dice[5], dice[4], dice[0] = dice[5], dice[4], dice[0], dice[1]
    elif dir_num == 2:
        dice[2], dice[5], dice[3], dice[0] = dice[5], dice[3], dice[0], dice[2]
    else:
        dice[0], dice[4], dice[5],dice[1] = dice[4], dice[5], dice[1], dice[0]

    if dice[5] > graph[nx][ny]:
        dir_num = (dir_num + 1)%4
    elif dice[5] < graph[nx][ny]:
        dir_num = (dir_num + 3)%4


    return nx, ny, dir_num


queue = deque()
#동남서북
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

dice = [1,2,3,4,5,6]

n, m, k = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

total_score = 0

nx, ny, dir_num = 0, 0, 0

for _ in range(k):
    visited = [[False] * m for _ in range(n)]

    #이동 방향에 관한 부분
        #이동 방향 함수에서 이동해야 할 좌표가 나오면, 그 좌표를 가지고 점수 계산하는 함수에 보내기
    nx, ny, dir_num = move_dice(nx, ny, dir_num)

    #점수 계산하는 부분
    total_score += score_bfs(nx, ny)

print(total_score)

