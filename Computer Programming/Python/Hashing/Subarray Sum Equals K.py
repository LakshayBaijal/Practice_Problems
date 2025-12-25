class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mp = {}

        prefix = {}
        n = len(nums)
        prefix[0] = nums[0]
        for i in range(1,n):
            prefix[i] = prefix[i-1] + nums[i] 
        
        mp[0] = 1
        count = 0
        for i in range(n):
            diff = prefix[i] - k

            if diff in mp:
                count += mp[diff]

            if prefix[i] in mp:
                mp[prefix[i]] += 1
            else:
                mp[prefix[i]] = 1
        
        return count
