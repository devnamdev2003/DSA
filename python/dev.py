
nums = [1, 15, 6, 3]
sum = 0
digi = 0
for val in nums:
    sum += val
    val = str(val)
    for val2 in val:
            digi=digi+int(val2)
print(abs(digi-sum))
