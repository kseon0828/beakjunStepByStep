from collections import deque

n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]

dx = [0,0,-1,1]
dy = [-1,1,0,0]

queue = deque()

#bfs 함수 구현
def bfs(x, y):
    queue.append((x,y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            #1일때 진행하는 것이 아니라 0일때를 확인하는 이유는
            #해당 좌표에 거리를 저장하기 때문에
            #1이 아니라 2,3,4가 들어가면 조건에 충족하지 못할 수 있음
            if graph[nx][ny] ==0:
                continue

            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] +1
                queue.append((nx, ny))

    return graph[n-1][m-1]

print(bfs(0, 0))