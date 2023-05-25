a=int(input())
def result(string):
    count=0
    k=0
    for i in range(len(string)):
        if string[i]==")":
            count-=1
        if string[i]=="(":
            count+=1
        if count<0:
            print('NO')
            k=1
            break
    if count==0:
        print('YES')
    else:
        if k==0:
            print('NO')
b=[]
for j in range(a):
    b.append(input())
for j in range(a):
    result(b[j])
