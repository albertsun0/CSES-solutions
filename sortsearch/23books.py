def readintln(): return [int(x) for x in input().split()]
def readInt(): return int(input())

n = readInt()
books = readintln()

x = sum(books)

y = max(books)
print(max(y * 2, x))


# 
# Lets say one person starts by reading the longest book, 
#
#