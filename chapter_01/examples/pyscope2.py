import sys
if __name__ == "__main__":
    if len(sys.argv) > 1:
        N = int(sys.argv[1])
    else:
        N = 5

def fact(n):
    if n > 1:
        return n * fact(n-1)
    return 1
while N > 0:
    print(fact(N))
    if N % 4 == 0:
        fact = N * (N - 1) / 2
    N = N -1

