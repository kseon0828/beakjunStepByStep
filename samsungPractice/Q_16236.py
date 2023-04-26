from collections import deque

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [[0]*n for _ in range(n)]
distance = [[0]*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if graph[i][j] == 9:
            sx = i
            sy = j
            break

queue = deque()

dx = [-0, 0, -1, 1]
dy = [-1, 1, 0, 0]

shark_weight = 2

def bfs(x, y):
    global eat_time
    queue.append((x, y))
    visited[x][y] = 1
    tmp =[]

    while queue:
        x, y = queue.popleft()
        nx = x + dx[i]
        ny = y + dy[i]

        if nx<0 or nx>= n or ny<0 or ny>=n:
            continue

        if visited[nx][ny] ==0:
            if graph[nx][ny] <= shark_weight: #상어가 지나갈 수 있는 조건
                queue.append((nx, ny))
                visited[nx][ny] = 1
                distance[nx][ny] = distance[x][y] + 1
                if  graph[nx][ny] < shark_weight and graph[nx][ny] != 0: #물고기를 먹을 수 있는 조건
                    tmp.append((nx, ny, distance[nx][ny]))



    return sorted(tmp,key=lambda x: (-x[2],-x[0],-x[1]))

cnt = 0 #상어가 잡아 먹은 물고기 수를 count하는 것으로, 상어 크기와 같아지면 상어 크기를 하나 늘리는 역할
result = 0 #물고기 잡아먹는데 걸리는 시간

while True:
    bite_fish = bfs(sx, sy)

    if len(bite_fish) == 0: # bfs한 결과가 없다는 것은 더이상 잡아 먹을 물고기가 없다는 뜻
        break

    nx, ny, dist = bite_fish.pop()

    result += dist
    graph[sx][sy], graph[nx][ny] = 0, 0
    #원래 상어가 있던 위치(sx, sy)와 앞으로 이동할 상어 위치(nx, ny)는 0으로 초기화
    #상어가 있었던 곳이고, 상어가 갈 곳이므로 따라서 해당 위치에 다시 방문할 수 있게 0으로 바꿈

    x, y = nx, ny
    cnt += 1

    if cnt == shark_weight:
        shark_weight += 1
        cnt = 0

print(result)