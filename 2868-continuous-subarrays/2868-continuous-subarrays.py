from sortedcontainers import SortedList
from typing import List

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        sorted_window = SortedList()
        left = 0
        count = 0

        for right in range(len(nums)):
            # Add the current number to the sorted window
            sorted_window.add(nums[right])
            
            # Check if the window is valid
            while sorted_window[-1] - sorted_window[0] > 2:
                sorted_window.remove(nums[left])
                left += 1
            
            # Count subarrays ending at `right`
            count += (right - left + 1)
        
        return count
