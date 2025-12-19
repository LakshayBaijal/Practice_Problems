class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        n = len(numbers)

        for i in range(n):
            diff = target - numbers[i]
            if diff in mp:
                index = mp[diff]
                return [index + 1,i + 1]
            mp[numbers[i]] = i
        
        return []
