class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        low = 0
        high = 0
        lowest = prices[0]
        highest = prices[0]
        profit = highest - lowest
        while high < len(prices) -1 and low < len(prices) - 1:
            if prices[high + 1] > highest:
                high += 1
                highest = prices[high]
                if highest - lowest > profit:
                    profit = highest - lowest
            elif prices[high + 1] < lowest:
                low = high + 1
                high = high + 1
                lowest = prices[low]
                highest = prices[high]
            else:
                high += 1
        return profit
        