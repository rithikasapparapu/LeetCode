class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        high = 0
        lowest = prices[0]
        highest = prices[0]
        profit = highest - lowest
        while high < len(prices)-1:
            if prices[high + 1] > highest:
                high += 1
                highest = prices[high]
                if highest - lowest > profit:
                    profit = highest - lowest
            elif prices[high + 1] < lowest:
                high += 1
                lowest = prices[high]
                highest = prices[high]
            else:
                high += 1
        return profit
        