class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        n = len(nums)

        closest = nums[0] + nums[1] + nums[2]

        for i in range(n):
            j = i + 1
            k = n - 1

            while j < k:
                curr_sum = nums[i] + nums[j] + nums[k]

                # update closest
                if abs(curr_sum - target) < abs(closest - target):
                    closest = curr_sum

                # exact match
                if curr_sum == target:
                    return target
                elif curr_sum < target:
                    j += 1
                else:
                    k -= 1

        return closest
