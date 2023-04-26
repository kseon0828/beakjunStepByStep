def productExceptSelf(nums):
    out = []
    p = 1

    #왼쪽 곱셈
    #이때 인덱스 0은 자기 자신을 제외해야 하므로, p를 1로 설정
    for i in range(0, len(nums)):
        out.append(p)
        p *= nums[i]

    #왼쪽 곱셈 결과에 오른쪽 값을 차레대로 곱셈
    #이것도 인덱스가 맨 끝에 있는 것은 자기 자신을 제외하기 위해 p를 1로 하여 곱함
    p = 1
    for i in range(len(nums)-1, -1, -1):
        out[i] = out[i]*p
        p = p * nums[i]

    return out

print(productExceptSelf([1,2,4,6]))