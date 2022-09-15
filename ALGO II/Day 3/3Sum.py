class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 2:
            return []
        returnl = []
        dic = {}
        hmset = {}
        for n in nums:
            if n in dic:
                dic[n] += 1
            else:
                dic[n] = 1
        for n in dic:
            for i in dic:
                if -n-i in dic:
                    if n == i and i == -n-i and dic[n] >= 3:
                        returnl.append([n,n,n])
                        dic[n] = 1
                    elif n == i and i != -n-i and dic[n] >= 2:
                        returnl.append([n,n,-2*n])
                        dic[n] = 1
                    elif n < i and i < -n-i:
                        if not (n,i,-n-i) in hmset:
                            hmset[(n,i,-n-i)] = 1
                            returnl.append([n,i,-n-i])
        return returnl