class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        
        if len(original) != m*n:
            return []
        ans = []
        k = 0
        for i in range(m):
            row = []
            for j in range(n):
                row.append(original[k])
                k += 1
            ans.append(row)
        
        return ans
