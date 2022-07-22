H, M = map(int, input().split())
cooking = int(input())

addH = cooking//60
addM = cooking%60

H += addH
M += addM

if M >= 60:
    H += 1
    M %= 60
if H > 23:
    H %= 24

print(H, M)