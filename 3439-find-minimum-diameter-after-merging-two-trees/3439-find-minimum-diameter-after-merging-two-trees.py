
class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        def tree_diameter(edges: List[List[int]], n: int) -> int:
            """
            Calculate the diameter of a tree using two BFS traversals.
            """
            # Build adjacency list
            graph = defaultdict(list)
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)

            # BFS to find the farthest node
            def bfs(start: int):
                dist = [-1] * n
                dist[start] = 0
                q = deque([start])
                farthest_node = start
                while q:
                    node = q.popleft()
                    for neighbor in graph[node]:
                        if dist[neighbor] == -1:
                            dist[neighbor] = dist[node] + 1
                            q.append(neighbor)
                            farthest_node = neighbor
                return farthest_node, dist[farthest_node]

            # First BFS to find one endpoint of the diameter
            endpoint1, _ = bfs(0)
            # Second BFS from the found endpoint to calculate the diameter
            _, diameter = bfs(endpoint1)
            return diameter

        # Number of nodes in each tree
        n = len(edges1) + 1
        m = len(edges2) + 1

        # Calculate diameters of both trees
        d1 = tree_diameter(edges1, n)
        d2 = tree_diameter(edges2, m)

        # Calculate minimum possible diameter after merging
        min_diameter = max(d1, d2, (d1 + 1) // 2 + (d2 + 1) // 2 + 1)
        return min_diameter
        