class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        mp = {}
        prefix = {}
        prefix[0] = nums[0]
        n = len(nums)
        
        for i in range(1,n):
            prefix[i] = prefix[i-1] + nums[i]
        
        mp[0] = 1
        count = 0
        for i in range(n):
            mod = ((prefix[i] % k) + k) % k

            if mod in mp:
                count += mp[mod]
            
            if mod in mp:
                mp[mod] += 1
            else:
                mp[mod] = 1
        
        return count


