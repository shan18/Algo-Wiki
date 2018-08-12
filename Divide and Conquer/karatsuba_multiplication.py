"""Performs Karatsuba Multiplication.

  The following uses Divider and conquer technique to multiply two integers.
  The algorithm runs in O(n^log3) = O(n^1.6) time.
"""

from math import ceil


def prepend_zeros(s, n):
    zeros_to_be_added = n - len(s)
    return '0' * zeros_to_be_added + s


def karatsuba(x, y):
    str_x, str_y = str(x), str(y)

    n = max(len(str_x), len(str_y))

    if n <= 1:
        return x * y

    if len(str_x) != n:
        str_x = prepend_zeros(str_x, n)
    elif len(str_y) != n:
        str_y = prepend_zeros(str_y, n)

    n_2 = int(n / 2)

    a, b = int(str_x[:n_2]), int(str_x[n_2:])
    c, d = int(str_y[:n_2]), int(str_y[n_2:])

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    ad_bc = karatsuba(a + b, c + d) - ac - bd

    n = n if n % 2 == 0 else n + 1
    n_2 = ceil(n / 2)

    return (10 ** n * ac) + (10 ** n_2 * ad_bc) + bd


if __name__ == '__main__':
    print("This program will multiply two numbers using Karatsuba multiplication.")
    first = int(input("Enter first number: "))
    second = int(input("Enter second number: "))
    print("The product is: ", karatsuba(first, second))
