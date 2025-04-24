from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        r = len(grid)
        c = len(grid[0])
        s = set()
        count = 0 

        for i in range(r):
            for j in range(c):
                if grid[i][j] == '1':
                    s.add((i, j))

        while s:
            x, y = s.pop()
            q = [(x, y)]
            count += 1
            while q:
                x, y = q.pop()
                if (x+1, y) in s:
                    q.append((x+1, y))
                    s.remove((x+1, y))
                if (x, y+1) in s:
                    q.append((x, y+1))
                    s.remove((x, y+1))
                if (x-1, y) in s:
                    q.append((x-1, y))
                    s.remove((x-1, y))
                if (x, y-1) in s:
                    q.append((x, y-1))
                    s.remove((x, y-1))

        return count
        