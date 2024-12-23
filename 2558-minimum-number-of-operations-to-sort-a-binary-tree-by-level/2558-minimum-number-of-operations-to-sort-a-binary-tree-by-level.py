# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        from collections import deque

        # Helper function to perform BFS and group nodes by levels
        def getLevels(root):
            levels = []
            queue = deque([root])

            while queue:
                level = []
                for _ in range(len(queue)):
                    node = queue.popleft()
                    level.append(node.val)
                    if node.left:
                        queue.append(node.left)
                    if node.right:
                        queue.append(node.right)
                levels.append(level)

            return levels

        # Helper function to calculate minimum swaps to sort an array
        def minSwapsToSort(arr):
            n = len(arr)
            indexed = [(val, idx) for idx, val in enumerate(arr)]
            indexed.sort()
            visited = [False] * n
            swaps = 0

            for i in range(n):
                if visited[i] or indexed[i][1] == i:
                    continue

                # Count the size of the cycle
                cycle_size = 0
                j = i

                while not visited[j]:
                    visited[j] = True
                    j = indexed[j][1]
                    cycle_size += 1

                if cycle_size > 1:
                    swaps += cycle_size - 1

            return swaps

        # Get levels of the tree
        levels = getLevels(root)

        # Calculate total swaps for all levels
        total_swaps = 0
        for level in levels:
            total_swaps += minSwapsToSort(level)

        return total_swaps

        