class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxLength = 0
        count = 0
        for i, num in enumerate(nums):
            if num == 1:
                count += 1
            else:
                maxLength = max(count, maxLength)
                count = 0
        maxLength = max(count, maxLength)
        return maxLength