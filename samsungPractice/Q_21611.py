def count(num, cnt):
    global rm_cnt_list
    if num == 1:
        rm_cnt_list[0] += cnt
    elif num == 2:
        rm_cnt_list[1] += cnt
    else:
        rm_cnt_list[2] += cnt

#  ↑, ↓, ←, → (1,2,3,4)
def blizad(d, s):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    for i in range(1, s + 1):
        nx = shark[0] + dx[d - 1] * i
        ny = shark[1] + dy[d - 1] * i

        # 격자를 넘어가면 continue
        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            break

        # 파괴
        graph[nx][ny] = False

    """
    if d == 1:
        for i in range(1, s+1):
            graph[shark[0]-i][shark[1]] = False
    elif d==2:
        for i in range(1, s+1):
            graph[shark[0]+i][shark[1]] = False
    elif d==3:
        for i in range(1, s+1):
            graph[shark[0]][shark[1]-i] = False
    else:
        for i in range(1, s+1):
            graph[shark[0]][shark[1]+i] = False
    """

def change_to_list(graph):
    list_from_graph = []
    nx, ny = shark[0], shark[1]
    cnt = 1
    d = 0
    flag = 0 #방향 바뀌기 시작
    cnt_flag=0
    for i in range(1, (n*n)):
        nx += dx[d%4]
        ny += dy[d%4]
        if (i - flag) == cnt:
            d+=1
            flag = i
            cnt_flag += 1
            if (cnt_flag %2) == 0:
                cnt += 1
        if graph[nx][ny] != False:
            list_from_graph.append(graph[nx][ny])
    return list_from_graph

def change_to_graph(list):
    new_graph = [[0]*n for _ in range(n)]
    d=0
    flag = 0 #방향 바뀌기 시작
    cnt_flag=0
    cnt = 1
    nx, ny = shark[0], shark[1]
    for i in range(len(list)):
        nx += dx[d%4]
        ny += dy[d%4]
        new_graph[nx][ny] = list[i]
        if(i+1-flag) == cnt:
            d+=1
            flag = i+1
            cnt_flag += 1
            if (cnt_flag %2) == 0:
                cnt += 1
    return new_graph

def explore(list):
    f_num = 0
    pre = list[0]
    idx = 0
    cnt = 1
    for i in range(1, len(list)):
        if pre == list[i]:
            cnt += 1
        else:
            if cnt >= 4:
                cnt = (i-idx)
                count(pre, cnt)
                f_num += cnt
                list[idx:i] = [False for _ in range(i-idx)]
            idx = i
            cnt=1
            pre = list[i]
    return f_num

def group(list):
    group_list = []
    pre = list[0]
    cnt = 1
    for i in range(1, len(list)):
        if pre == list[i]:
            cnt += 1
        else:
            if len(group_list) > (n*n)-1:
                break
            group_list.append(cnt)
            group_list.append(pre)
            pre = list[i]
            cnt = 1
    return group_list


def main():
    global graph
    for i in range(m):
        blizad(bli_list[i][0], bli_list[i][1])
        list = change_to_list(graph)

        while True:
            f_num = explore(list)
            if f_num ==0:
                break
            for i in range(f_num):
                list.remove(False)
        list = group(list)
        graph = change_to_graph(list)

    result = rm_cnt_list[0] + (rm_cnt_list[1]*2) + (rm_cnt_list[2]*3)
    print(result)

if __name__=="__main__":
    rm_cnt_list = [0, 0, 0]
    n, m = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(n)]
    bli_list = [tuple(map(int, input().split())) for _ in range(m)]

    shark = ((n - 1) // 2, (n - 1) // 2)

    # 빈칸을 메꾸기 위해 그래프를 리스트로 변환하여 메꾸자
    #  ←, ↓, →, ↑ (그래프 순회 순서)
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]

    list = []

    main()