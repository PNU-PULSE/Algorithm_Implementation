import sys
input = sys.stdin.readline


def match(T, P):
    cnt = 0
    ans = []
    pi = [0 for _ in range(len(P) + 1)]
    n, m = len(T), len(P)
    for i in range(1, m):
        while cnt and P[i] != P[cnt]:
            cnt = pi[cnt - 1]
        if P[i] == P[cnt]:
            cnt += 1
            pi[i] = cnt

    cnt = 0
    for i in range(n):
        while cnt and T[i] != P[cnt]:
            cnt = pi[cnt - 1]
        if T[i] == P[cnt]:
            if cnt == m - 1:
                ans.append(i - m + 2)
                cnt = pi[cnt]
            else:
                cnt += 1
    return ans


T = input().rstrip("\n")
P = input().rstrip("\n")
arr = match(T, P)
print(len(arr))
print(*arr, sep = "\n")
