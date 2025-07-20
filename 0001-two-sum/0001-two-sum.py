class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # nums.sort()
        # i = 0
        # j = len(nums) - 1
        # while i < j:
        #     if nums[i] + nums[j] == target:
        #         return [i, j]
        #     elif nums[i] + nums[j] < target:
        #         i += 1
        #     else:
        #         j -= 1
        # -----------------------------------------------------------------
        # nums = [2,7,11,15, 11, 7, 12, 7]
        # dic = {
        #     2: [1, [0]],
        #     7: [3, [1, 5, 7]],
        #     11: [2, [2, 4]],
        #     15: [1, [3]],
        #     12: [1, [6]],
        # }
        dic = {}
        i = 0
        for num in nums:
            if dic.get(num) is None:
                dic[num] = [1,[i]]
            else:
                dic[num][0] += 1
                dic[num][1].append(i)
            i += 1
        print(dic)
        for num in nums:
            if target - num != num:
                if dic.get(target - num) is not None:
                    return [dic[num][1][0],dic[target-num][1][0]]
            else:
                if dic[num][0] > 1:
                    return dic[num][1]
        
                

        