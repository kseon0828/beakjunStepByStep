def search(nums, target):

    #binary_search 재귀함수
    def binary_search(left, right):
        #left가 right보다 작거나 같으면 재귀 진행
        #mid 중간 값 계산
        if left <= right:
            mid = (left+right) //2

            #target이 mid보다 오른족에 위치해있을 때
            #탐색 공간을 mid 우측으로 변경
            if nums[mid]<target:
                return binary_search(mid+1, right)
            #target이 mid보다 왼족에 위치해있을 때
            #탐색 공간을 mid 좌측으로 변경
            elif nums[mid]>target:
                return binary_search(left, mid-1)
            #target과 mid 값이 같으면 mid 반환
            else:
                return mid

        else:
            return -1

    return binary_search(0, len(nums)-1)