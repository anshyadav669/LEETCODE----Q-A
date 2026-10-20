class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        maxi = max(candies)
        res = []
        n= extraCandies
        for el in candies:
            if(el+n >= maxi):
                res.append(True)
            else:
                res.append(False)        


        return res        