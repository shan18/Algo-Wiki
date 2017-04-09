"""Merge Sort.

Time complexity: O(n log(n)).
It uses a Divide and Conquer Approach.
"""


# Combining two subproblems and calculating the inversions
def merge(a, p, q, t):

    l = a[p:q + 1]
    r = a[q + 1:t + 1]

    i, j = [0, 0]

    for k in range(p, t + 1):
        if i == len(l):
            a[k] = r[j]
            j += 1
        elif j == len(r):
            a[k] = l[i]
            i += 1
        elif l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1


# Dividing the problem into smaller subproblems
def merge_sort(a, p, t):
    if p < t:
        inversions = 0
        q = int((p + t) / 2)
        merge_sort(a, p, q)
        merge_sort(a, q + 1, t)
        merge(a, p, q, t)


if __name__ == '__main__':

    filename = input("Enter the file name containing the array: ")
    a = []
    with open(filename) as f:
        for n in f.read().split():
            a.append(int(n))

    merge_sort(a, 0, len(a) - 1)
    print("The sorted array: ", a)
