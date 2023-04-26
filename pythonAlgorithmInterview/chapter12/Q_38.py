import collections


class Solution(object):
    def findItinerary(self, tickets):
        #디폴트 값이 list인 딕셔너리 생성
        graph = collections.defaultdict(list)

        #tickets을 정렬하고, graph 딕셔너리에 추가함
        for a, b in sorted(tickets):
            graph[a].append(b)

        route = []

        def dfs(a):
            #graph의 a키 값이 존재할 때까지
            while graph[a]:
                #graph의 a의 맨 앞 값을 dfs 재귀 인자로 넣고, 호출
                dfs(graph[a].pop(0))
            #더 이상 호출될 재귀가 없으면, 하나씩 추가됨
            route.append(a)

        dfs('JFK')
        #뒤집어 주는 이유는 재귀가 없을 때까지 진행되고 난 후에 추가되는 것이므로
        return route[::-1]