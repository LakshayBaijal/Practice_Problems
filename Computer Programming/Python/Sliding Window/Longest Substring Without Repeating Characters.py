class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        mp = {}

        n = len(s)
        maximum = 0
        left = 0
        for right in range(n):
            lenght = 0
            
            if s[right] in mp:
                left = max(left, mp[s[right]] + 1)

            mp[s[right]] = right
            
            maximum = max(maximum,right - left + 1)
        
        return maximum
