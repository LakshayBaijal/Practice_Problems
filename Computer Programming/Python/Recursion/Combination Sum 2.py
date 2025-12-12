class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()

        n = len(candidates)
        ans = set()
        current = []

        self.function(ans,current,candidates,target,n-1)
        
        return [list(t) for t in ans]

    def function(self,ans,current,candidates,target,index):
        if target == 0:
            ans.add(tuple(current))
            return

        if target < 0:
            return

        if index < 0:
            return

        current.append(candidates[index])
        self.function(ans,current,candidates,target - candidates[index],index-1)
        current.pop()

        self.function(ans,current,candidates,target,index -1)

        return
