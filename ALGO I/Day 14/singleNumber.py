class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        counts={}
        for i in nums:
            counts[i]=counts.get(i,0)+1
        for i in counts:
            if(counts[i]==1):
                return i