class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        nums.sort()
        ans = set()
        target = 0

        for i in range(len(nums)):
            
            target = - nums[i]
            k = len(nums) - 1
            j = i + 1
            while j < k:
                if target == nums[j] + nums[k]:
                    ans.add((nums[i],nums[j],nums[k]))
                    j += 1
                    k -= 1

                elif target < nums[j] + nums[k]:
                    k -= 1
                else:
                    j += 1

        return list(ans) 

        

