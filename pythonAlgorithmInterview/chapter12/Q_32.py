class Solution(object):
    def dfs(self, grid, i, j):
        if i<0 or i>=len(grid) or\
            j<0 or j>=len(grid[0]) or\
            grid[i][j] != '1':
            return

        #더이상 육지가 아님
        grid[i][j] = '#'

        self.dfs(grid, i+1, j)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i, j-1)

    def numIslands(self, grid):
        if not grid:
            return 0

        #육지 개수 세기
        count = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                #육지라면 육지 탐색 시작
                if grid[i][j]=='1':
                    self.dfs(grid, i, j)
                    #육지 탐색 끝나면 count 증가
                    count += 1
        return count