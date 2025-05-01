class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start=-1
        end=-1
        for i in range(0,len(nums)):
            if nums[i]==target:
                if start==-1:
                    start=i
                end=i
        return [start,end]
        