class Solution(object):
    longest = 0

    def diameterOfBinaryTree(self, root):
        def dfs(node):
            if not node:
                return -1
            left = dfs(node.left)
            right = dfs(node.right)

            self.longest = max(self.longest, left+right+2) #거리(현재 노드와 왼쪽, 오른쪽 자식 노드와의 거리)
            return max(left, right) + 1 #상태값(왼쪽(or 오른쪽)리프 노드에서 현재 노드까지 거리)

        dfs(root)
        return self.longest

