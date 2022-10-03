class Solution(object):
    def permute(self, nums):
        result = []
        #prev 한 쌍이 들어갈 곳
        prev_elements =[]

        def dfs(elements):
            if len(elements)==0:
                result.append(prev_elements[:])

            for e in elements:
                next_elements = elements[:]
                next_elements.remove(e)

                #재귀 들어가기 전에 prev에 추가함
                prev_elements.append(e)
                dfs(next_elements)
                #리프노드를 만나면 재귀에서 계속 계속 탈출함
                #재귀에 나올 때마다 prev에서 pop 되가지고
                #최종적으로 빈 prev 리스트가 됨
                prev_elements.pop()

        dfs(nums)
        return result