class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        odd = []
        even = []

        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                even.append(nums[i]) 
            
            if nums[i] % 2 != 0:
                odd.append(nums[i])

        even += odd

        return even
