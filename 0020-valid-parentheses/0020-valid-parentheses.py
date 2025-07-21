class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for st in s:
            if st == '(' or st == '{' or st == '[':
                stack.append(st)
            else:
                if len(stack) == 0:
                    return False
                else:
                    if (stack[len(stack)-1] == '(' and st == ')') or (stack[len(stack)-1] == '{' and st == '}') or (stack[len(stack)-1] == '[' and st == ']'):
                        stack.pop()
                    else:
                        return False
        if len(stack) != 0:
            return False
        return True