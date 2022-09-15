class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        p = list(map(list,list(set(permutations(nums)))))
        return p
        