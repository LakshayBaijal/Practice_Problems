class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        ans = set()
        nums.sort()
        k = 4
        index = len(nums) -1 

        self.function(ans,k,target,nums,index,[])

        return list(ans)

    def function(self,ans,k,target,nums,index,current):
        if k == 0:
            if target == 0:
                ans.add(tuple(current))
                return

        if index < 0:
            return

        current.append(nums[index])
        self.function(ans,k-1,target-nums[index],nums,index-1,current)
        current.pop()
        self.function(ans,k,target,nums,index-1,current)

        return
