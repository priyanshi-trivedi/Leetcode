class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        memo = {}

        def helper(s1, s2):
            # Check if the result is already computed
            if (s1, s2) in memo:
                return memo[(s1, s2)]

            # Base cases
            if s1 == s2:  # If strings are identical
                memo[(s1, s2)] = True
                return True
            if sorted(s1) != sorted(s2):  # If characters don't match
                memo[(s1, s2)] = False
                return False

            n = len(s1)
            for i in range(1, n):  # Try every split point
                # Case 1: Without swapping
                if helper(s1[:i], s2[:i]) and helper(s1[i:], s2[i:]):
                    memo[(s1, s2)] = True
                    return True
                # Case 2: With swapping
                if helper(s1[:i], s2[-i:]) and helper(s1[i:], s2[:-i]):
                    memo[(s1, s2)] = True
                    return True

            # If no valid scramble found
            memo[(s1, s2)] = False
            return False

        return helper(s1, s2)
        