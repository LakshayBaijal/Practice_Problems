class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        n = len(candidates)
        ans = []
        current = []
        self.function(ans,candidates,current,n-1,target)

        return ans

    def function(self,ans,candidates,current,index,target):
        if target < 0:
            return
        if target == 0:
            ans.append(list(current))
            return

        if index < 0:
            return

        current.append(candidates[index])
        self.function(ans,candidates,current,index,target - candidates[index])
        current.pop()

        self.function(ans,candidates,current,index-1,target)
        return
