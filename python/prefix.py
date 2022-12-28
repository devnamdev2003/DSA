

def prefixCount( words, pref):
      count=0
      for val in words:
            if(val[:len(pref)]==pref):
                  count=count+1
      return count

words = ["leetcode","win","loops","success"]
pref = "code"
print(prefixCount(words, pref)
)