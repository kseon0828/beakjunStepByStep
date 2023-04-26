#풀이1 투포인터로 합 계산
from typing import List

def threeSum(nums: List[int]):
    results = []
    nums.sort()

    for i in range(len(nums)-2):
        #중복된 값 건너뛰기
        if i>0 and nums[i] == nums[i-1]:
            continue

        #간격을 좁혀가며 합 sum 계산
        left, right = i+1, len(nums)-1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if sum<0:
                left += 1
            elif sum>0:
                right -= 1
            else:
                results.append([nums[i], nums[left], nums[right]])

                #left 포인터를 조절할 때 동일한 값은 건너뛰고
                while left < right and nums[left] == nums[left+1]:
                    left+=1
                while left < right and nums[right] == nums[right-1]:
                    right-=1
                left+=1
                right-=1

    return results

print(threeSum([-1, 0, 1, 2, -1, -4]))