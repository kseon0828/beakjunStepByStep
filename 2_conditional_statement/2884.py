H, M = map(int, input().split())

if M < 45:  #45분 미만일 때
    M += (60-45)
    if H == 0:
        H = 23
    else:
        H -= 1
else:     #45분 이상일 때도 고려해야 함
    M -= 45

print(H, M)