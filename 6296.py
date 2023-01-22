n=886996
s=str(n)

sum=0
for i in range(0,len(s)):
          if(i%2==0):
                  sum=sum+int(s[i])
                  
          else:
                  sum=sum-int(s[i])
print(sum)