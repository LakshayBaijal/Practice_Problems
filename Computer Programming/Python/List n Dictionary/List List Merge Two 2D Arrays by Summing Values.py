class Solution(object):
    def mergeArrays(self, nums1, nums2):
        """
        :type nums1: List[List[int]]
        :type nums2: List[List[int]]
        :rtype: List[List[int]]
        """
        
        n = len(nums1)
        m = len(nums2)
        i = 0
        j = 0

        ans = []
        while i < n and j < m:
            if nums1[i][0] == nums2[j][0]:
               ans.append([nums1[i][0],nums1[i][1] + nums2[j][1]])

               i += 1
               j += 1

            elif nums1[i][0] < nums2[j][0]:
                ans.append([nums1[i][0],nums1[i][1]])
                i += 1 
            else:
                ans.append([nums2[j][0],nums2[j][1]])
                j += 1

        while i < n:
            ans.append([nums1[i][0],nums1[i][1]])
            i+=1
        while j < m:
            ans.append([nums2[j][0],nums2[j][1]])
            j+=1

        return ans
