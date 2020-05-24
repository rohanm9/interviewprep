import math
from sys import stdin,stdout
mod=1000000007

size=int(100)
fact=[0]*size
fact[0]=1
for i in range(1,size):
    fact[i]=i*fact[i-1]
def ncr(n,r,fact):
    npr=(fact[n]/fact[n-r])
    return npr/fact[r]
    
s=list(stdin.readline())
s.pop()
r=list(stdin.readline())
r.pop()
flag=False
for i in range(len(s)):
    if r[i]=='?':
        flag=True
        break
if flag==False:
    count1=0
    for i in range(len(s)):
        if s[i]=='+':
            count1+=1
    count2=0
    for i in range(len(r)):
        if r[i]=='+':
            count2+=1
    p=float(0)
    if count1==count2:
        p=float(1)
    stdout.write(f'{p}\n')
else:
    n=0
    rr=0
    for i in range(len(s)):
        if s[i]=='+':
            rr+=1
    for i in range(len(r)):
        if r[i]=='+':
            rr-=1
        if r[i]=='?':
            n+=1
    if rr<0 or rr>n:
        p=float(0)
        stdout.write(f'{p}\n')
    else:
        p=ncr(n,rr,fact)/math.pow(2,n)
        stdout.write(f'{p}\n')
        