#백 트래킹으로 벽을 세우고
#level(벽 개수)이 3일 때, bfs로 바이러스 퍼트리면서 좌표에서 0들 세기
from collections import deque
import copy
queue = deque()

n,m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

#상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

result = 0

def bfs(origin_graph):
    graph = copy.deepcopy(origin_graph)

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2:
                queue.append((i, j))

                while queue:
                    x, y = queue.popleft()

                    for d in range(4):
                        nx = x + dx[d]
                        ny = y + dy[d]

                        if 0> nx or nx >= n or 0>ny or ny >= m or graph[nx][ny] ==1: continue
                        if graph[nx][ny] == 0:
                            graph[nx][ny] = 2
                            queue.append((nx, ny))

    global result
    cnt = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                cnt += 1

    result = max(result, cnt)


def back_tracking(level):
    if level == 3:
        #벽이 3개 다 만들어졌으면, bfs(바이러스 퍼트리기) 시작
        bfs(graph)
        return

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                back_tracking(level+1)
                graph[i][j] = 0

back_tracking(0)
print(result)