n=int(input())
count=[]
for i in range(n):
    if i==0:
        count.append(1)
    elif i==1:
        count.append(3)
    else:
        count.append(count[i-1]+2*count[i-2])
print(count[n-1]%10007)
