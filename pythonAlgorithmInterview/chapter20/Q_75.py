import collections
from typing import List

def maxSlibWindow(nums:List[int], k:int) -> List[int]:
    result =[]
    window = collections.deque()

    #최댓값 교체를 위해 처음은 -inf로 설정
    current_max = float('-inf')

    for i, v in enumerate(nums):
        window.append(v)
        #(i<k-1)이 참이면 다음 코드 실행 안함
        if i<k-1:
            continue

        if current_max == float('-inf'):
            current_max = max(window)
        elif v > current_max:
            current_max = v

        result.append(current_max)

        if current_max == window.popleft():
            current_max = float('-inf')

    return result



"""
#브루투 포스 풀이
def maxSlibWindow(nums:List[int], k:int) -> List[int]:
    if not nums:
        return nums

    result = []
    for i in range(len(nums)-k+1):
        result .append(max(nums[i:i+k]))

    return result
"""