class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        pq = []

        for num in nums:
            heapq.heappush(pq,-num)

        for i in range(0,k-1):
            heapq.heappop(pq)

        return - heapq.heappop(pq)
