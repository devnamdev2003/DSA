banned = [11]
n = 7
maxSum = 60
sum = 0
count = 0
for i in range(1, n+1):
    if i not in banned:
            sum = sum+i
            if(sum <= maxSum):
                  count = count+1
            else:
                  break    
print(count)
