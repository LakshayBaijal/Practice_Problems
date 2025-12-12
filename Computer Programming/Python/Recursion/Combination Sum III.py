class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        
        ans = []
        current = []

        self.function(ans,current,9,k,n)
        return ans

    def function(self,ans,current,index,k,target):
        if target == 0:
            if k == 0:
                ans.append(list(current))
                return
            else:
                return

        if target < 0:
            return 
        if k < 0:
            return
        if index < 0:
            return

        current.append(index)
        self.function(ans,current,index-1,k-1,target - index)
        current.pop()

        self.function(ans,current,index-1,k,target)

        return

        
