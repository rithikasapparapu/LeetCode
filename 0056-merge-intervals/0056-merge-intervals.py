class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def fun(lis):
            return lis[0]
        intervals.sort(key=fun)
        i = 0
        while i < len(intervals) - 1:
            if intervals[i][1] >= intervals[i+1][0]:
                intervals[i][0] = min(intervals[i][0], intervals[i+1][0])
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1])
                intervals.remove(intervals[i+1])
            else:
                i += 1
        return intervals