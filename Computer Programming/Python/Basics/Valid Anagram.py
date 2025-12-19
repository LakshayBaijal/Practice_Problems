class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        mp1 = {}
        mp2 = {}

        s_size = len(s)
        t_size = len(t)
        for i in range(s_size):
            mp1[s[i]] = mp1.get(s[i], 0) + 1
        
        for j in range(t_size):
            mp2[t[j]] = mp2.get(t[j],0) + 1

        if mp1 == mp2:
            return True
        
        return False
