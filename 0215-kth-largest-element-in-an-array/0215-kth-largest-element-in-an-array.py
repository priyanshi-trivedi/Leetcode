class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n=len(nums)
        import heapq
        h=nums[0:k]
        heapq.heapify(h)
        for i in range (k,n):
            heapq.heappush(h,nums[i])
            heapq.heappop(h)
        return(h[0])    
        