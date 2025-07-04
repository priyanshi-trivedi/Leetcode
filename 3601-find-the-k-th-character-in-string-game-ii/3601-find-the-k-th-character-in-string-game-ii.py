class Solution:
    def kthCharacter(self, k: int, operations: list[int]) -> str:
        length = [1]  # Initial string length after each operation
        for op in operations:
            length.append(length[-1] * 2)

        shift = 0  # how many times the character has been incremented

        # Work backwards to trace where k came from
        for i in reversed(range(len(operations))):
            op = operations[i]
            prev_len = length[i]

            if k <= prev_len:
                continue  # it came from the first half
            else:
                k -= prev_len  # adjust position to first half
                if op == 1:
                    shift += 1  # this part was built using next()

        # Initial character is always 'a'
        result_char = chr((ord('a') - ord('a') + shift) % 26 + ord('a'))
        return result_char
