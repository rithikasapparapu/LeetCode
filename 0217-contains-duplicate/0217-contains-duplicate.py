class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # for num in nums:
        #     if nums.count(num) > 1:
        #         return True
        # return False
        nums.sort()
        i = 1
        while i < len(nums):
            if nums[i-1] == nums[i]:
                return True
            i += 1
        return False
        