class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ""
        l = 0
        r = 1
        while r < len(s):
            if s[r] == " ":
                ans += s[l:r][::-1]
                ans += s[r]
                r += 1
                l = r
                r += 1
            else:
                r += 1
        ans += s[l:r][::-1]
        return ans