class Solution:
    def kthCharacter(self, k: int) -> str:
        def helper(k):
            if k == 1:
                return 'a'
            
            # Find the length of previous word before doubling
            length = 1
            while length * 2 < k:
                length *= 2

            if k <= length:
                return helper(k)
            else:
                ch = helper(k - length)
                # shift it by +1 (wrap around after 'z')
                return chr((ord(ch) - ord('a') + 1) % 26 + ord('a'))

        return helper(k)

        