n, m  = input().split()
n=int(n)
m=int(m)
num=list(map(int,input().split()))
result = [[0 for col in range(2)] for row in range(m)]
c=0
answer=[]
def plus(a,b):
    global num, c
    for i in range(a-1,b):
        c+=num[i]
for i in range(m):
    result[i]=list(map(int,input().split()))
    plus(result[i][0],result[i][1])
    answer.append(c)
    c=0
for i in range(m):
    print(answer[i])
