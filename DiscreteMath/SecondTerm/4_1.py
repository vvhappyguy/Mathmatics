i = int(input())

def luckyTicket(num):
    if num <= 0:
        return "Error"
    array = [1] * 10 + [0] * (num * 9 - 9)
    for x in range(num - 1):
        array = [sum(array[x::-1]) if x < 10 \
        else sum(array[x:x-10:-1]) for x in range(len(array))]
    return sum([x**2 for x in array])

print(luckyTicket(i))