class Solution(object):
    def lengthOfLongestSubstring(self, s):
        #앞에 중복된 문자가 있는지 확인하기 위해 만든 딕셔너리
        used = {}

        max_length = start = 0

        for index, char in enumerate(s):
            #문자가 used에 존재하고 중복된 문자의 위치가 start보다 크면
            #두번째 조건이 있는 이유는 start 전에 중복된 문자가 있을 수도 있는데 그 경우는 인식하면 안돼서
            if char in used and start <= used[char]:
                #중복된 문자의 위치 다음을 start로 변경
                start = used[char]+1
            #used에 존재하지 않는 문자이면
            else:
                max_length = max(max_length, index - start +1)

            used[char]=index
        return max_length