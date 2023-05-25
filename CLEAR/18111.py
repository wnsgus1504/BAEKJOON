n, m, k = map(int, input().split())
ground=[list(map(int,input().split()))for i in range(n)]
lst=[]
time=0
inv=0

height=0
for i in range(min(map(min, ground)),max(map(max, ground))+1):
    for j in range(n):
        for t in range(m):
            need=ground[j][t]-i
            if need<0:
                time+=need*(-1)
                inv+=(-1)*need
            if need>=0:
                time+=need*(2)
                inv-=need
    if inv<=k:
        if i==min(map(min, ground)):
            mint=time
            height=i
        elif mint>=time:
            mint=time
            height=i
    time=0
    inv=0


print(mint, height)
