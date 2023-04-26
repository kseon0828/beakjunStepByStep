def hammingWeight(n : int)->int:
    #1의 개수를 새는 변수 count
    count = 0

    #입력 n이 0이 될 때까지 반복
    while n:
        n &= n-1
        count +=1
    return count