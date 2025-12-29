class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        right = len(height) - 1
        left = 0

        area = 0

        while left < right:
            minimum = min(height[left],height[right])
            area = max(minimum * (right - left), area)

            if height[left] > height[right]:
                right -= 1
            else:
                left += 1

        return area

