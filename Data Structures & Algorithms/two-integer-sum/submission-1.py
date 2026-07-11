class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for i, num in enumerate(nums):
            val = target - num
            if val in mp:
                return [mp[val], i]
            mp[num] = i
        return []