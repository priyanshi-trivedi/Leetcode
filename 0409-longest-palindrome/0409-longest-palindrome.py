class Solution:
    def longestPalindrome(self, s: str) -> int:
        return sum(v // 2 * 2 for v in Counter(s).values()) + (1 if any(v % 2 for v in Counter(s).values()) else 0)
        