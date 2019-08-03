# Enter your code here. Read input from STDIN. Print output to STDOUT
# python3
class DisjointSet:
    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.total = [1] * N

    def union(self, a, b):
        aParent = self.find(a)
        bParent = self.find(b)
        if aParent != bParent:
            self.parent[bParent] = aParent
            self.total[aParent] += self.total[bParent]

    def find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def getTotal(self, a):
        return self.total[self.find(a)]

if __name__ == "__main__":
    N = int(input())
    ds = DisjointSet(N)
    for i in range(N-1):
        x, y, color = input().split()
        if color == 'b':
            ds.union(int(x) - 1, int(y) - 1)
    setSize = {ds.find(i): ds.getTotal(i) for i in range(N)}
    complement = sum(x * (x-1) * (N - x) // 2 +
                    x * (x-1) * (x - 2) // 6
                    for x in setSize.values())
    print((N * (N - 1) * (N - 2) // 6 - complement) % (10 ** 9 + 7))
