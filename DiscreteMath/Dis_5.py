def nod(a,b):
    while a!=0 and b!=0:
       if a > b:
          a = a % b
       else:
          b = b % a
    return (a+b)

def nok(a,b):
    return a*b/nod(a,b)

def Factor(n):
    Ans = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            Ans.append(d)
            n //= d
        else:
            d += 1
    if n > 1:
        Ans.append(n)
    return Ans

def deof(a,b,c):
    print("Решение диофантова уравнения"+str(a)+"*x + \
          " + str(b) + "*y = " + str(c)               )
    assert c != 0

    nodAB = nod(abs(a),abs(b))
    if c % nodAB:
        print("Impossible")
    else:
        a //= nodAB
        b //= nodAB
        c //= nodAB

        for k in range(abs(a)):
            if ( c - b * k ) % a == 0:
                y = k
                x = (c - b * y) // a
                return [x,y]


dict = {'а':0,'б':1,'в':2,'г':3,'д':4,'е':5,'ж':6,'з':7,'и':8,\
        'й':9,'к':10,'л':11,'м':12,'н':13,'о':14,'п':15,'р':16,\
        'с':17,'т':18,'у':19,'ф':20,'х':21,'ц':22,'ч':23,'ш':24,\
        'щ':25,'ъ':26,'ы':27,'ь':28,'э':29,'ю':30,'я':31}
n_numbers = []
m_numbers = []
ALPH = 32
obr = 0

print("Введите своё имя")
first_name = str(input())
print("Введите свою фамилию")
last_name = str(input())

first_name = first_name[:3].lower()
last_name = last_name[:3].lower()

print(first_name + " " + last_name)

dict[first_name[0]]
for i in range(3):
    n_numbers.append(dict[first_name[i]])
    m_numbers.append(dict[last_name[i]])
print(n_numbers)
print(m_numbers)

n = n_numbers[0]*ALPH*ALPH + n_numbers[1]*ALPH + n_numbers[2]
m = m_numbers[0]*ALPH*ALPH + m_numbers[1]*ALPH + m_numbers[2]
n_2 = n * n

print(m)
print(n)
print(n_2)

print("1). Обратный к вычету m по умножению, если он есть.\n\
       Необходимо решить диофантово уравнение вида:\n\
       < x*m + y*(n^2) = 1>\n\
       Если nod(m,n^2)!=1, то обратного элемента нет.")
if(nod(m, n_2) != 1):
    print("Обратного элемента нет!")
else:
    print("Обратный элемент есть!\n\
           Найдём его.")
    obr = (n_2 % m + m ) % m
    print(obr)

print("Идёт вычисление идемпотентных и нильпотентных элементов...")
nils = 0
idem = 0

for i in range(2,n_2):
   if ((i * i) % n_2 == i):
            idem += 1
for i in range(2,n_2):
    if((i * i) % n_2) == 0:
            nils += 1

print("2). Количество идемпотентных элементов:" + str(idem))
print("3). Количество нильпотентных элементов:" + str(nils))
print("Для пунктов 4 и 5 понадобиться разложение на простые в степенях")

simple_numbers = Factor(184362084)
print(simple_numbers)
grad = {}
for i in range(len(simple_numbers)):
    if(simple_numbers[i] not in grad):
        grad[simple_numbers[i]] = 1
    else:
        grad[simple_numbers[i]] = grad[simple_numbers[i]] + 1
        
print(grad)
