class Solution:
	def threeSum(self, nums: List[int]) -> List[List[int]]:

		ans = []
		nums.sort()

		for i in range(len(nums)):
			if i > 0 and nums[i] == nums[i-1]:
				continue

			left = i + 1
			right = len(nums) - 1

			while left < right:

				if nums[left] + nums[right] + nums[i] == 0:
					ans.append([nums[i], nums[left], nums[right]])
					left += 1
					while nums[left] == nums[left-1] and left < right:
						left += 1

				elif nums[left] + nums[right] + nums[i] < 0:
					left += 1
				else:
					right -= 1

		return ans