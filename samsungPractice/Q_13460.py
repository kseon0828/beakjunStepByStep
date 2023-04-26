from collections import deque

n, m = map(int, input().split())

graph = []

#빨간공, 파란공의 위치 지정
for i in range(n):
    graph.append(list(input()))
    for j in range(m):
        if graph[i][j] == 'R':
            rx = i
            ry = j
        elif graph[i][j] == 'B':
            bx = i
            by = j

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(rx, ry, bx, by):
    q= deque()
    q.append((rx, ry, bx, by))
    cnt = 0 #움직임 count
    visited = [] #방문한 좌표

    visited.append((rx, ry, bx, by))

    while q: #큐가 존재할 때까지 bfs 실행
        for _ in range(len(q)):
            rx, ry, bx, by = q.popleft() #큐 맨앞에 존재하는 요소 탐색 시작
            if cnt > 10:
                print("-1")
                return
            if graph[rx][ry]== 'O':
                print(cnt)
                return
            for i in range(4): #4방향 탐색
                nrx, nry = rx, ry #4방향 탐색을 위해 다음 rx, ry 위치를 대입할 변수 생성
                while True: # #이나 O 만날 때 까지 계속 한 방향으로 이동
                    nrx += dx[i]
                    nry += dy[i]
                    if graph[nrx][nry] == '#':
                        nrx -= dx[i]
                        nry -= dy[i]
                        break
                    if graph[nrx][nry] == 'O': #출구 만나면 break, 바로 return 안하는 이유는 파란색 구슬도 확인을 해야 하므로, break하여 que에 넣어서 다음 탐색에서 return하여 탈출하게 함
                        break

                nbx, nby = bx, by
                while True:
                    nbx += dx[i]
                    nby += dy[i]
                    if graph[nbx][nby] == '#':
                        nbx -= dx[i]
                        nby -= dy[i]
                        break
                    if graph[nbx][nby] == 'O':
                        break

                if graph[nbx][nby] == 'O': #파란색 구슬이 출구를 통과하면, 해당 방향은 contine로 que에 넣지 않고 무효 처리
                    continue

                if nrx == nbx and nry==nby: #두 구슬이 겹친다면, 이동한 거리가 더 많은 구술이 한칸 뒤로 이동
                    if abs(nrx - rx) + abs(nry - ry) > abs(nbx- bx)+abs(nby-by):
                        nrx -= dx[i]
                        nry -= dy[i]
                    else :
                        nbx -= dx[i]
                        nby -= dy[i]

                if (nrx, nry, nbx, nby) not in visited:
                    q.append((nrx, nry, nbx, nby))
                    visited.append((nrx, nry, nbx, nby))
        cnt+= 1
    print(-1)

bfs(rx, ry, bx, by)





