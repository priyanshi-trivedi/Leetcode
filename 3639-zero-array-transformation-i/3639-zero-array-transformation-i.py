class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        count = [0] * (n + 1)
        for l, r in queries:
            count[l] += 1
            if r + 1 < n:
                count[r + 1] -= 1
        for i in range(1, n):
            count[i] += count[i - 1]
        for i in range(n):
            if count[i] < nums[i]:
                return False
        return True

        