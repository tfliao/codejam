import sys

def gcd(x, y):
    while(y):
        x, y = y, x % y
    return x

def solv(N, v):
    r = []
    bad_cnt = 0
    last = -1
    for i in range(1, len(v)):
        if last == -1:
            if v[i - 1] == v[i]:
                continue
            q = gcd(v[i-1], v[i])
            bad_cnt = i - 1
            last = v[i] // q
            r = [v[i-1] // q, q, last]
        else:
            last = v[i] // last
            r.append(last)
    s = sorted(list(set(r)))
    m = {val: chr( ord('A') + idx) for idx, val in enumerate(s)}
    r = ''.join([m[x] for x in r])
    pre = r[0:2] * ((bad_cnt + 1) // 2)
    r = pre[-bad_cnt:] + r
    return r

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for i in range(T):
        N, L = map(int, sys.stdin.readline().split())
        v = list(map(int, sys.stdin.readline().split()))
        print('Case #{}: {}'.format(i + 1, solv(N, v)))

