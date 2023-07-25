n=input()
n_list=[]
for a in n:
    n_list.append(a)
def postfix(list1):
    
    while '(' in list1:
        m=0
        count=0
        front=0
        behind=0
        while m<len(list1):
            if list1[m]=='(':
                if count==0:
                    if front==0:
                        front=m
                count+=1
            if list1[m]==')':
                count-=1
                if count==0:
                    behind=m
                    break
            m+=1
        list1[front]=postfix(list1[front+1:behind])
        for i in range(front+1,behind+1):
            del list1[front+1]
    index=0
    while index<len(list1):
        if(list1[index]=='*' or list1[index]=='/'):
            k=list1[index-1]+list1[index+1]+list1[index]
            list1[index-1]=k
            del list1[index+1]
            del list1[index]
            index=index-1
        index=index+1
    index=0
    while index<len(list1):
        if(list1[index]=='+' or list1[index]=='-'):
            k=list1[index-1]+list1[index+1]+list1[index]
            list1[index-1]=k
            del list1[index+1]
            del list1[index]
            index=index-1
        index=index+1
    return list1[0]
print(postfix(n_list))
        
