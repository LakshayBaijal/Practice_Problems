class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """

        n = len(arr)
        mp = {}

        for i in range(n):
            if arr[i] in mp:
                mp[arr[i]] += 1
            else:
                mp[arr[i]] = 1


        freq = set()
        for count in mp.values():
            if count in freq:
                return False
            else:
                freq.add(count)
        
        return True
        
