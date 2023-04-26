class Solution(object):
    def combinationSum(self, candidates, target):
        result = []

        #csum 처음에 target 값을 주므로, candidates[i]를 빼면서 csum이 0이 되는 조합을 result에 추가
        def dfs(csum, index, path):
            if csum < 0:
                return
            if csum == 0:
                result.append(path)
                return

            for i in range(index, len(candidates)):
                dfs(csum-candidates[i], i, path + [candidates[i]])

        dfs(target, 0, [])
        return result