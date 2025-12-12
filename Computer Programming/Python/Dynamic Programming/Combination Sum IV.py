class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        n = len(nums)

        dp = []
        for i in range(n):
            row = []
            for j in range(target+1):
                row.append(-1)
            dp.append(row)

        ans = self.function(dp,nums,n-1,target)
        return ans

    def function(self,dp,nums,index,target):
        if target == 0:
            return 1
        if target < 0:
            return 0
        if index < 0:
            return 0

        if dp[index][target] != -1:
            return dp[index][target]

        n = len(nums)
        pick = self.function(dp,nums,n-1,target - nums[index])
        notpick = self.function(dp,nums,index-1,target)
        
        dp[index][target] = pick + notpick

        return dp[index][target]


         
