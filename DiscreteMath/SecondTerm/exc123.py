dictA = {'а':0,'б':1,'в':2,'г':3,'д':4,'е':5,'ж':6,'з':7,'и':8,\
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

f1 = []
f2 = []
g = []

for i in range(3):
    f1.append(bin(int(dictA[first_name[i]])))
    f2.append(bin(int(dictA[last_name[i]])))
    g.append(bin(dict[first_name[i]]) | bin(dict[last_name[i]]))

print(f1)
print(f2)
print(g)
