def chaek(word1, word2):
    return (' '.join(map(str, word1[0:]))).replace(" ", "") == (' '.join(map(str, word2[0:]))).replace(" ", "")


word1 = ["ab", "cb"]

word2 = ["ab", "cb"]

print(chaek(word1, word2))
