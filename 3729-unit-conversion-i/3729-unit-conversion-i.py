from collections import deque
from typing import List

class Solution:
    def baseUnitConversions(self, conversions: List[List[int]]) -> List[int]:
        n = len(conversions)
        adj = [[] for _ in range(n+1)]
        dis = [1] * (n+1)
        
        for s, e, w in conversions:
            adj[s].append((e, w))
        
        q = deque()
        q.append(0)
        
        while q:
            x = q.popleft()
            for y, w in adj[x]:
                dis[y] = (dis[x] * w) % (10**9 + 7)
                q.append(y)
        
        return dis