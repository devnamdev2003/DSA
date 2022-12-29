ans = 0
nums = [12,345,2,6,7896]
for i in nums:
    if(len(str(i)) % 2 == 0):
        ans = ans+1
print(ans)
