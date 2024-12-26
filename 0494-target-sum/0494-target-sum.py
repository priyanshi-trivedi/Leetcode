class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        # If (target + total_sum) is odd or negative, return 0
        if (target + total_sum) % 2 != 0 or (target + total_sum) < 0:
            return 0
        
        P = (target + total_sum) // 2
        dp = [0] * (P + 1)
        dp[0] = 1  # There's one way to form sum 0
        
        for num in nums:
            for j in range(P, num - 1, -1):
                dp[j] += dp[j - num]
        
        return dp[P]    
        