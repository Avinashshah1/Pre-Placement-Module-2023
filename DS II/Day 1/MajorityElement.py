class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts=dict()
        for i in nums:
            counts[i]=counts.get(i,0)+1
        for i,j in counts.items():
            if j>math.floor(len(nums)/2):
                return i
        