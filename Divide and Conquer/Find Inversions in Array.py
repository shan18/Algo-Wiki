"""Number of inversions.

The code below calculates the number of inversions inside an array in
O(n log(n)) time.
It uses a Divide and Conquer Approach (Merge Sort).
"""


# Combining two subproblems and calculating the inversions
def merge(A, p, q, t):

    l = A[p:q + 1]
    r = A[q + 1:t + 1]

    i, j, inversions = [0, 0, 0]

    for k in range(p, t + 1):
        if i == len(l):
            A[k] = r[j]
            j += 1
        elif j == len(r):
            A[k] = l[i]
            i += 1
        elif l[i] <= r[j]:
            A[k] = l[i]
            i += 1
        else:
            A[k] = r[j]
            j += 1
            inversions += len(l) - i

    return inversions


# Dividing the problem into smaller subproblems
def merge_sort(A, p, t):
    if p < t:
        inversions = 0
        q = int((p + t) / 2)
        inversions += merge_sort(A, p, q)
        inversions += merge_sort(A, q + 1, t)
        inversions += merge(A, p, q, t)
        return inversions
    else:
        return 0


if __name__ == '__main__':
    A = []
    with open('IntegerArray.txt') as f:
        for n in f.read().split():
            A.append(int(n))

    inversions = merge_sort(A, 0, len(A) - 1)
    print("Inversions: ", inversions)
