class Solution:
    def countDigits(self, num: int) -> int:

        s = str(num)
        cnt = 0
        for char in s:
            i = int(char)
            if num % i == 0:
                cnt += 1

        return cnt