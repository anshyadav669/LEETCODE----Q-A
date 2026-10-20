class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        s = str(n)
        add = 0
        prod = 1
        for char in s:
            add += int(char)
            prod *= int(char)

        return prod - add
