"""The code below sorts an array in
O(n log(n)) time.
It uses a Divide and Conquer Approach (Quick Sort).
This code uses the median of the first, the last and the middle element of the
array as the pivot.

The Data for the algorithm is in a file QuickSortData.txt
"""


# Setting the pivot element to its correct location
def partition(A, start, end):
    middle = int((start + end) / 2)
    if A[start] <= A[middle] <= A[end] or A[end] <= A[middle] <= A[start]:
        A[start], A[middle] = A[middle], A[start]
    elif A[middle] <= A[end] <= A[start] or A[start] <= A[end] <= A[middle]:
        A[start], A[end] = A[end], A[start]

    pivot = A[start]
    i = start + 1
    for j in range(start + 1, end + 1):
        if A[j] <= pivot:
            A[j], A[i] = A[i], A[j]
            i += 1
    A[start], A[i - 1] = A[i - 1], A[start]
    return i - 1


# Dividing the problem into smaller subproblems
def quick_sort(A, start, end):
    comparisons = 0
    if start < end:
        q = partition(A, start, end)
        quick_sort(A, start, q - 1)
        quick_sort(A, q + 1, end)


if __name__ == '__main__':
    A = []
    with open('QuickSortData.txt') as f:
        for n in f.read().split():
            A.append(int(n))

    quick_sort(A, 0, len(A) - 1)
    print(A)
