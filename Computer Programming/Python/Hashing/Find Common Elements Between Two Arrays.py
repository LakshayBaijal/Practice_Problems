class Solution(object):
    def findIntersectionValues(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        mp1 = {}
        mp2 = {}

        n = len(nums1)
        m = len(nums2)

        for i in range(n):
            if nums1[i] in mp1:
                mp1[nums1[i]] += 1
            else:
                mp1[nums1[i]] = 1

        
        for i in range(m):
            if nums2[i] in mp2:
                mp2[nums2[i]] += 1

            else:
                mp2[nums2[i]] = 1

        
        count1 = 0
        count2 = 0

        for i in range(m):
            if nums2[i] in mp1:
                count2 += 1

        for i in range(n):
            if nums1[i] in mp2:
                count1 += 1

        return [count1,count2]
