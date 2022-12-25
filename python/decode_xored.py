n1 = [1,2,3]
n2 = 5
for i in range(len(n1)):
    n1b = bin(n1[i]).replace("0b", "")
    n2b = bin(n2).replace("0b", "")
    if(n1[i] > n2):
        max = n1b
        less = n2b
    else:
        max = n2b
        less = n1b
    for j in range(len(max)):
        if len(less) < len(max):
            less = "0"+less
    ans = ""
    for i in range(len(max)):
        if (max[i] == less[i]):
            ans += "0"
        else:
            ans += "1"
    print(max, less, ans,int(ans,2))
