class Solution:
    def findScore(self, nums: List[int]) -> int:
         n = len(nums)
         marked = [False] * n  # To keep track of marked elements
         min_heap = []
         # Step 1: Build a min-heap with (value, index) pairs
         for i, num in enumerate(nums):
            heapq.heappush(min_heap, (num, i))
         score = 0
         while min_heap:
            # Step 2: Extract the smallest unmarked element
            val, idx = heapq.heappop(min_heap)
            # Skip if the element is already marked
            if marked[idx]:
                continue
                # Step 3: Add the value to the score
            score += val
            # Step 4: Mark the current element and its neighbors
            marked[idx] = True
            if idx > 0:
                marked[idx - 1] = True
            if idx < n - 1:
                marked[idx + 1] = True
         return score
        