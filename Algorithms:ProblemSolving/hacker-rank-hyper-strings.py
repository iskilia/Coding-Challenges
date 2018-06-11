# Hackerrank HyperString Challenge
import sys
from functools import wraps

def memo(func):
    cache = {}
    @wraps(func)
    def wrap(*args):
            if args not in cache:
                    cache[args] = func(*args)
            return cache[args]
    return wrap


def Calculate(temp_val):
    global  H, M
    if temp_val == M:
            return 0
    total = 0
    for s in H:
            temp = temp_val + len(s)
            if temp <= M:
                    total += Calculate(temp) + 1
    return total

def Verify(s, first = False):
    global H
    if len(s) == 0:
            return True

    for s2 in H:
            if len(s2) <= len(s):
                    if first and s2 == s:
                            continue
                    if s[:len(s2)] == s2:
                            if Verify(s[len(s2):]):
                                    return True
    return False

if __name__ == "__main__":
    Calculate = memo(Calculate)
    data = sys.stdin.readlines()
    H = []

    line_input = data[0].rstrip('\n').split()
    N = int(line_input[0])
    M = int(line_input[1])

    for i in range(1, len(data)):
        H.append(data[i].rstrip('\n'))

    H = set(H)
    removed = []

    for s in H:
        if Verify(s, True):
            removed.append(s)

    for s in removed:
        H.remove(s)

    ans = (Calculate(0)+1) % 1000000007
    print(ans)
