class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        mp = {}
        n = len(nums)

        for i in range(n):
            if nums[i] in mp:
                return True
            else:
                mp[nums[i]] = 1
        
        return False
