def dtob(n):
    return bin(n).replace("0b", "")


def xor(a, b, n):
    ans = ""
    for i in range(n):
        if (a[i] == b[i]):
            ans += "0"
        else:
            ans += "1"
    return ans

def operation(number):
    arr = []

    for i in range(len(number)):
        arr.append(str(dtob(int(number[i]))))
    if len(number) == 1:
        arr.append("0")
    res = max(arr, key=len)

    for i in range(len(arr)):
        for j in range(len(res)):
            if len(arr[i]) < len(res):
                arr[i] = "0"+arr[i]

    a = arr[0]
    b = arr[1]
    n = len(a)
    c = xor(a, b, n)
    return int(c)


def sum(first):

    string = first
    sum_digit = 0
    for x in string:
        if x.isdigit():
            sum_digit += int(x)
    return sum_digit


if __name__ == '__main__':
    number1 = input()
    number2 = input()
    first = int(number1)
    second = int(number2)
    count = 0
    while first <= second:
        ans = operation(str(first))
        avg = (sum(str(first))/2)
        if ans > avg:
            count = count+1
        first = first+1
    print(count)
