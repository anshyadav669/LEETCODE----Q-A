class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        ans=[]
        for i in range(len(nums)):
            cnt=0
            for j in range(len(nums)):
                if(nums[j]<nums[i]):
                    cnt+=1

            ans.append(cnt)

        return ans    