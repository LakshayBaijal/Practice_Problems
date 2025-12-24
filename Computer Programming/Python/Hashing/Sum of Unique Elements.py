class Solution(object):
    def sumOfUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        mp = {}
        n = len(nums)

        for i in range(n):
            if nums[i] in mp:
                mp[nums[i]] += 1

            else:
                mp[nums[i]] = 1
        total = 0
        for i in range(n):
            if mp[nums[i]] == 1:
                total += nums[i]

        return total
