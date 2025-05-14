class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n=len(nums)
        expected=set(range(1,n+1))
        present=set(nums)
        missing_number=list(expected-present)
        return missing_number
        