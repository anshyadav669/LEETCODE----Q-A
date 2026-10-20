class Solution:
    def isPalindrome(self, x: int) -> bool:
        s= str(x)
        a= "".join(reversed(s))

        if(s==a):
            return True
        else:
            return False    