import numpy as np;
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        size = len(nums)

        mp = {}
        for i in range(size):
            diff = target - nums[i]
            if diff in mp:
                return [mp[diff],i]

            mp[nums[i]] = i
        return {}
