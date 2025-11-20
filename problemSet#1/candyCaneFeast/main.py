N, M = map(int, input().split())

heights = [ int(x) for x in input().split() ]
candy = [ int(x) for x in input().split() ]

for i in range(M):
    cane = [0,candy[i]]
    for j in range(N):
        if cane[1] == cane[0]:
            break
        if candy[i] <= heights[j]:
            heights[j] += candy[i] - cane[0]
            break
        if cane[0] < heights[j]:
            original = cane[0]
            cane[0] = heights[j]
            heights[j] += heights[j] - original
    
for i in heights:
  print(i)