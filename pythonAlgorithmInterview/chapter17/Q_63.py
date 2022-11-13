def sortColor(nums):
    #red, white는 0에서 시작
    #blue는 배열의 길이이므로, 인덱스 밖에 존재
    red, white, blue = 0,0,len(nums)

    while white <blue:
        #1(mid)을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 스왑
        if nums[white] < 1:
            nums[red], nums[white] = nums[white], nums[red]
            white += 1
            red +=1
        elif nums[white] > 1:
            blue -=1
            nums[white], nums[blue] = nums[blue], nums[white]
        else:
            white +=1