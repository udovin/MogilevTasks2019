from pyjudge import server
from base64 import b64encode, b64decode
from random import randint, seed
from os import unlink


seed(4242)


def d_solution(n, k, a):
    l = 0
    ans = 0
    a = sorted(a)
    for i in range(1, n):
        k -= a[i] - a[i - 1] - 1
        while k < 0:
            k += a[l + 1] - a[l] - 1
            l += 1
        ans = max(ans, a[i] - a[l] + 1 + k)
    while l < n - 1:
        k += a[l + 1] - a[l] - 1
        l += 1
        ans = max(ans, a[i] - a[l] + 1 + k)
    return ans


def d_generator():
    return (
        (8, 4, [1, 2, 3, 4, 10, 11, 14, 15]),
        (1, 1, [1]),
        (10, 1, [2, 3, 5, 6, 8, 9, 11, 12, 15, 16]),
        (10, 2, [2, 3, 5, 6, 8, 9, 11, 12, 15, 16]),
        (10, 3, [2, 3, 5, 6, 8, 9, 11, 12, 15, 16]),
        (10, 4, [2, 3, 5, 6, 8, 9, 11, 12, 15, 16])
    )

def h_solution(n, s):
    ans = ""
    temp = ""
    for i in range(n):
        temp += sorted(s[i])[0]
    for x in sorted(temp):
        ans += x
    return ans


def h_generator():    
    tests = []
    for test in range(50):
        n = randint(1, 111)
        s = []
        for i in range(n):
            m = randint(1, 111)
            s.append("")
            for j in range(m):
                s[i] += chr(randint(0, 25) + ord('a'))
        tests.append([n, s])

    return tests


def k_solution(x):
    if x == 0:
        return 0
    cnt = 0
    while x & 1 == 0:
        x = x >> 1
        cnt += 1

    return 1 << cnt


def k_generator():
    tests = []
    for test in range(100):
        tests.append((randint(0, 1000000000000000000000000000000000000),))
    return tests


def i_solution(x):
    res = []
    ff = lambda y: (y - 1) % 9 + 1
    for i in x:
        res.append(ff(i))
    return res


server.tasks = dict(
    a=dict(
        legend=(
            "2**2019 = ?\n"
        ),
        answer=2**2019,
    ),
    b=dict(
        legend=(
            "Напишите функцию, которая принимает два числа в качестве аргументов\n"
            "и возвращает сумму этих чисел.\n"
        ),
        solution=lambda a, b: a + b,
        inputs=(
            (2, 2),
            (2, -2),
            (2018, 1),
            (11, 22),
            (643, -534),
            (754, 965),
            (64345, 8645646325),
            (4564, -4647),
            (-765097, 45656854),
            (57567, -7667756),
            (0, 0),
        ),
    ),
    c=dict(
        legend=(
            "Сегодня цезарь должен должен провести секретную встречу.\n"
            "Заговорщикам удалось получить секретное сообщение с точным местом куда отправится цезарь. Вот оно:\n"
            "OMBUFAX, RGXX YAAZ\n"
            "Хм ничего непонятно...\n"
            "Помогите восстановить республику и назовите место встречи цезаря и его пресмыкателей!\n"
        ),
        answer="CAPITOL",
    ),
    d=dict(
        legend=(
            "Страну доминошек охватила паника. УЖЕ БОЛЕЕ 42 СЕКУНД НИКТО НЕ ВЫЗЫВАЛ МАКСИМАЛЬНЫЙ ЭФФЕКТ ДОМИНО.\n"
            "В ваших силах все исправить.\n"
            "Есть N доминошек.\n"
            "Все доминошки стоят на целочисленных позициях от 1 до 10^6.\n"
            "Максимальным эффектом домино называется такой единственный толчок доминошки,\n" 
            "что падает наибольшее количество доминошек(одна доминошка толкает другую только если они на соседних позициях)\n"
            "Ваша задача состоит в том, что бы вставив не более K дополнительных доминошек так, что бы длина\n"
            "МАКСИМАЛЬНОГО ЭФФЕКТА ДОМИНО была максимальна.\n"
        ),
        solution=d_solution,
        inputs=d_generator(),
    ),
    e=dict(
        legend="base64 {}".format(b64encode((
            "Это очень простая задача. Настолько простая, что решать ее не придется.\n"
            "Ответ: base64\n"
        ).encode())),
        answer="base64",
    ),
    f=dict(
        legend=(
            "Напишите функцию, которая сортирует числа.\n"
            "На вход эта функция должна принимать список чисел.\n"
            "Функция должна вернуть отсортированный список.\n"
            "ПОДСКАЗКА:\n"
            "Рекомендуем использовать сортировку TimSort.\n"
        ),
        solution=sorted,
        inputs=(
            ([1, 2, 3, 4, 5, 6],),
            ([6, 5, 4, 3, 2, 1],),
            ([6, 4, 3, 1, 2],),
            ([randint(-1000, 1000) for i in range(1000)],),
            ([randint(-1000, 1000) for i in range(10000)],),
            ([randint(-1000, 1000) for i in range(100000)],),
            ([randint(-1000000, 1000000) for i in range(100000)],),
        ),
    ),
    g=dict(
        legend=(
            "Вам должно повезти...\n"
        ),
        answer="I'm lucky",
        checker=lambda ja, pa: randint(1, 3) == 1,
    ),
    h=dict(
        legend=(
            "ЛЕНЬ ВРЕМЕНИ ОБЬЯСНЯТЬ. Вам дано число N и N строк состоящих из строчных лат\n"
            "символов. Напишитеs функцию которая принимает число N и список строк(в качестве аргументов), а на выход дает\n"
            "лексиграфически минимальную строку составленную так, что в ней содержится ровно по одному\n"
            "символу от каждой строки\n"
        ),
        solution=h_solution,
        inputs=h_generator(),
    ),
    k=dict(
        legend=(
            "Задача загадка. Но есть четыре входа и соответсвующие им выходы.\n"
            "1 - 1\n"
            "256 - 256\n"
            "1375128 - 8\n"
            "951862464 - 64\n"
            "Уже догадались какую функцию вам нужно составить?\n"
        ),
        solution=k_solution,
        inputs=k_generator(),
    ),
    i=dict(
        legend=(
            "Операция превращения представляет получение числа y из числа x пропуская её через f(x).\n"
            "f(x) работает просто если число < 10 то оно возвращает это число, иначе возвращает f(СУММА ЦИФР ЧИСЛА x)\n"
            "Вам на вход дан список целых чисел. Напишите функцию которая вернет список превращенных чисел."
        ),
        solution=i_solution,
        inputs=(
            ([1, 2, 3, 4, 5, 6],),
            ([6, 5, 4, 3, 2, 1],),
            ([6, 4, 3, 1, 2],),
            ([randint(1, 1000) for i in range(1000)],),
            ([randint(1, 1000) for i in range(10000)],),
            ([randint(1, 1000) for i in range(100000)],),
            ([randint(1, 1000000) for i in range(100000)],),
        ),
    )
)
