class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # Har word ki frequency count karo
        word_count = Counter(words)
        word_len = len(words[0])  # Har word ki length
        num_words = len(words)   # Total words
        concat_len = word_len * num_words  # Concatenated string ki length
        n = len(s)
        
        result = []
        # Har possible index ko check karo
        for i in range(n - concat_len + 1):
            # Current substring
            substring = s[i:i + concat_len]
            # Usko parts mein divide karo
            seen = []
            for j in range(0, concat_len, word_len):
                seen.append(substring[j:j + word_len])
            # Check karo agar yeh `words` ka permutation hai
            if Counter(seen) == word_count:
                result.append(i)
        return result        

        