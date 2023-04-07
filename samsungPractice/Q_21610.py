n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
m_list = [tuple(map(int, input().split())) for _ in range(m)]
cloud = [(n-1, 0), (n-1, 1), (n-2, 0), (n-2, 1)]

#←, ↖, ↑, ↗, →, ↘, ↓, ↙
dx = ("empty", 0, -1, -1, -1, 0, 1, 1, 1)
dy = ("empty", -1, -1, 0, 1, 1, 1, 0, -1)

# ↖, ↗, ↘, ↙
ddx = (-1, -1, 1, 1)
ddy = (-1, 1, 1, -1)

for d, s in m_list:
    new_cloud_list = []

    # 구름 이동시키기
    for x, y in cloud:
        nx = (x + dx[d] * s)%n
        ny = (y + dy[d] * s)%n

        # 구름이 있는 곳 1씩 증가
        graph[nx][ny] += 1
        new_cloud_list.append((nx, ny))

    # 물복사버스 마법
    for x, y in new_cloud_list:
        for i in range(4):
            nx = x + ddx[i]
            ny = y + ddy[i]

            if 0 > nx or nx >= n or 0 > ny or ny >= n : continue
            elif graph[nx][ny] > 0:
                graph[x][y] += 1

    cloud.clear()
    for i in range(n):
        for j in range(n):
            if graph[i][j] < 2 or (i, j) in new_cloud_list: continue
            graph[i][j] -= 2
            cloud.append((i, j))

result = 0
for i in range(n):
    for j in range(n):
        result += graph[i][j]

print(result)