class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        ans = set()
        lenght = len(nums)
        
        for i in range(lenght):
            j = i + 1
            while  j < lenght:
                sumij = nums[i] + nums[j]
                difference = target - sumij
                k = j + 1
                w = lenght - 1
                while k < w:
                    if difference == nums[k] + nums[w]:
                        ans.add((nums[i],nums[j],nums[k],nums[w]))
                        k += 1
                        w -= 1
                    if difference < nums[k] + nums[w]:
                        w -= 1
                    if difference > nums[k] + nums[w]:
                        k += 1
                j += 1
        
        return list(ans)
