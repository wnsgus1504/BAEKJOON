import copy
def count(lst1):
    global a, finish, result, p, step
    lst2 = copy.deepcopy(lst1)
    for o in range(len(lst1)):
        for j in range(2):
            for k in range(int(m)):
                if int(lst1[o])==int(a[k][j]):
                    if j==0:
                        if not int(a[k][1]) in finish:
                            if not int(a[k][1]) in lst1:
                                lst1.append(int(a[k][1]))
                    else:
                        if not int(a[k][0]) in finish:
                            if not int(a[k][0]) in lst1:
                                lst1.append(int(a[k][0]))
    for r in range(len(lst2)):
        if lst2[r] in lst1:
            lst1.remove(lst2[r])
    for u in range(len(lst2)):
        word=lst2.pop()
        if not word in finish:
            finish.append(word)
            
n, m  = input().split()
i=0
a = [[0 for col in range(2)] for row in range(int(m))]
while i<int(m):
    a[i][0], a[i][1]  = input().split()
    i+=1
i=0
while i<int(m):
    a[i][0]=int(a[i][0])
    a[i][1]=int(a[i][1])
    i+=1
num=[]
finish=[]
result=[0 for t in range(int(n))]
step=1
for p in range(int(n)):
    num.append(p+1)
    while len(finish)!=int(n):
        count(num)
        result[p]+=len(num)*step
        step+=1
        
    num=[]
    finish=[]
    step=1
answer=0
for e in range(len(result)):
    if result[answer]>result[e]:
        answer=e
print(answer+1)
