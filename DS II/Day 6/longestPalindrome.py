from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = Counter(s)
        
        size = 0
        odd = False
        for v in freq.values():
            if v % 2 == 0:
                size += v
            else:
                odd = True
                size += v - 1
                    
        return size if not odd else size + 1
                