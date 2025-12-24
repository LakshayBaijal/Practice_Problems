class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        mp = {}
        n = len(nums)

        for i in range(n):
            if nums[i] in mp:
                mp[nums[i]] += 1
            else:
                mp[nums[i]] = 1


        ans = set()

        for i in range(n):
            if mp[nums[i]] == 2:
                ans.add(nums[i])
    
        return list(ans)
