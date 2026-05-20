class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        
        mpl = {}
        l = len(p)
        n = len(s)
        for ele in p:
            if ele in mpl:
                mpl[ele] += 1
            else:
                mpl[ele] = 1

        right = 0
        left = 0
        ans = []
        mps = {}
        for right in range(0,n):
            if s[right] in mps:
                mps[s[right]] += 1
            else:
                mps[s[right]] = 1

            if right - left + 1 == l:
                if mpl == mps:
                    ans.append(left)
                mps[s[left]] -= 1
                if mps[s[left]] == 0:
                    del mps[s[left]]
                left += 1



        return ans
