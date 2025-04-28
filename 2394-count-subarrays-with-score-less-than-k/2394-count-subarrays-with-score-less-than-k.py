class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        count = 0
        start = 0
        window_sum = 0
        
        for end in range(len(nums)):
            window_sum += nums[end]
            
            # Jab tak score >= k hai, window ko chhota karo
            while window_sum * (end - start + 1) >= k and start <= end:
                window_sum -= nums[start]
                start += 1
            
            # Abhi tak jo valid window hai, usme (end - start + 1) subarrays banenge
            count += (end - start + 1)
        
        return count