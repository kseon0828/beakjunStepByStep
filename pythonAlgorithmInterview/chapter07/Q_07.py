#풀이1 브루트 포스
class Solution(object):
    def twoSum(self, nums, target):
        my_list = []
        for i, v in enumerate(nums):
            for j in range(i+1, len(nums)):
                if v + nums[j] == target:
                    my_list.append(i)
                    my_list.append(j)
        return my_list

s = Solution()
print(s.twoSum([2,7,11,15],9))

#풀이2 in을 이용한 탐색
def twoSum(nums, target):
    for i, v in enumerate(nums):
        complement = target - v

        if complement in nums[i + 1:]:
            return [nums.index(v), nums[i+1:].index(complement) + (i+1)]

print(twoSum([2,7,11,15],9))

#풀이3 첫번째 수를 뺀 결과 키 조회
def twoSum(nums, target):
    nums_map = {}
    #인덱스 -> 값, 값 -> 키로 바꾸어 딕셔너리 저장
    for i, num in enumerate(nums):
        nums_map[num] = i

    for i, num in enumerate(nums):
        #(target - num) 값이 nums_map에 키로 존재하고 인덱스가 nums_map의 값과 동일하지 않을 때
        if target - num in nums_map and i != nums_map[target - num]:
            return [i, nums_map[target - num]]

print(twoSum([2,7,11,15],9))

#풀이4 풀이3의 구조 개선
def twoSum(nums, target):
    nums_map = {}
    for i, num in enumerate(nums):
        if target - num in nums_map:
            return [nums_map[target - num], i]
        nums_map[num] = i

print(twoSum([2,7,11,15],9))