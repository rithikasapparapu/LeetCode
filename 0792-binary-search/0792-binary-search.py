class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # nums = [-1,0,3,5,9,12], target = 9
        low = 0
        high = len(nums)-1

        while low <= high:
            mid = low + ((high - low) // 2)
            if nums[mid] > target:
                high = mid - 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                return mid
        return -1