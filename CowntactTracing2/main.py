import math

N = int(input())
cows = [int(x) for x in input()]

groups = [] #group length will give #2 - #1 + 1
currGroup = -1
for i in range(N):
    if cows[i] == 1 and currGroup < 0:
        currGroup = i
    if cows[i] == 0 and currGroup >= 0:
        groups.append([currGroup, i-1])
        currGroup = -1
if currGroup != -1:
    groups.append([currGroup, N-1])

maxNights = 1000000
for group in groups:
    if group[0] == 0 or group[1] == N-1:
        if maxNights > group[1] - group[0]:
            maxNights = group[1] - group[0]
        continue
    if math.floor((group[1] - group[0])/2) < maxNights:
        maxNights = math.floor((group[1] - group[0])/2)

answer = 0

for group in groups:
    answer += math.ceil((group[1] - group[0] + 1)/(2*maxNights+1))

print(int(answer))