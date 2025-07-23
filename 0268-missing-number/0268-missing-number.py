class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        expected = sum(nums)
        l = len(nums)
        actual = int(l * (l+1) / 2)
        return actual - expected