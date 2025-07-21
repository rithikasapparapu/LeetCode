class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join([char for char in s if char.isalnum()]).lower()
        i = 0
        while i < len(s)//2:
            if s[i] != s[len(s)-i-1]:
                return False
            i += 1
        return True

        