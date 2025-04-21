class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        # Initialize variables to track cumulative sum
        total = 0
        min_val = 0
        max_val = 0
        # Calculate the minimum and maximum prefix sum
        for diff in differences:
            total += diff
            min_val = min(min_val, total)
            max_val = max(max_val, total)
            # Find the valid range for hidden[0] such that
            # all values stay within [lower, upper]
            min_possible_start = lower - min_val
            max_possible_start = upper - max_val
            # Total number of valid starting values
            result = max(0, max_possible_start - min_possible_start + 1)
        return result
        