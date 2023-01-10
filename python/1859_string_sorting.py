s = "is2 sentence4 This1 a3"
li = s.split(" ")
li2 = []
print(li)
for val in li:
    li2.append(val[-1:]+val[:-1])
li2.sort()
li.clear()
for val in li2:
    li.append(val[1:]+" ")
s2 = ""
print(s2.join(li))
print(len(li))
