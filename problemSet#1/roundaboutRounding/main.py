T = int(input())

def repeated1s(l):
    s = 0
    for i in range(l):
        s += 10**i
    return s

for _ in range(T):
    sum = 0
    N = input().strip()
    L = len(N)-1
    N = int(N)
    for i in range(L):
        if i != L-1:
            sum += 5 * repeated1s(i + 1)
    for i in range(L):
        if (N >= 4 * repeated1s(L-i)*10**(i+1) + 5*10**(i)):
            sum += min(5*10**i, N - (4 * repeated1s(L-i)*10**(i+1) + 5*10**(i)) + 1)
        else:
            break
    print(sum)
