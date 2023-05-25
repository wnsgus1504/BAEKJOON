num=list(map(int,input().split()))
k=2
n=[]
for i in range(num[0],num[1]+1):
    n.append(i)
while k<=num[1]:
    for i in n:
        if i%k==0:
            if i==k:
                print(i)
            n.remove(i)
    k+=1
