n, k  = input().split()
n=int(n)
k=int(k)
coin=[]
for j in range(n):
    coin.append(int(input()))
j=len(coin)-1
time=0
while j>=0:
    time+=k//coin[j]
    k-=(k//coin[j])*coin[j]
    j-=1
print(time)
