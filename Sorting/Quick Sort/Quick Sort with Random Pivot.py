"""Quick Sort

Time complexity is O(n log(n)).
It uses a Divide and Conquer Approach.
"""


from random import randint


# Setting the pivot element to its correct location
def partition(a, start, end):
    pivot_index = randint(start, end)
    a[start], a[pivot_index] = a[pivot_index], a[start]
    i = start + 1
    for j in range(start + 1, end + 1):
        if a[j] <= a[start]:
            a[j], a[i] = a[i], a[j]
            i += 1
    a[start], a[i - 1] = a[i - 1], a[start]
    return i - 1


# Dividing the problem into smaller subproblems
def quick_sort(a, start, end):
    if start < end:
        q = partition(a, start, end)
        quick_sort(a, start, q - 1)
        quick_sort(a, q + 1, end)


if __name__ == '__main__':

    filename = input("Enter the file name containing the array: ")
    a = []
    with open(filename) as f:
        for n in f.read().split():
            a.append(int(n))

    quick_sort(a, 0, len(a) - 1)
    print("The sorted array: ", a)
