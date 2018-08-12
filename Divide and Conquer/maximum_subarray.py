def find_max_crossing_subarray(A, low, mid, high):
    left_sum = A[mid]
    max_left = 0
    total = A[mid]
    for i in range(mid - 1, low, -1):
        total += A[i]
        if total > left_sum:
            left_sum = total
            max_left = i

    right_sum = mid + 1
    max_right = 0
    total = A[mid + 1]
    for i in range(mid + 2, high + 1):
        total += A[i]
        if total > right_sum:
            right_sum = total
            max_right = i

    return (max_left, max_right, left_sum + right_sum)


def find_max_subarray(A, low, high):
    if high == low:
        return (low, high, A[low])
    else:
        mid = int((low + high) / 2)
        (leftLow, leftHigh, left_sum) = find_max_subarray(A, low, mid)
        (rightLow, rightHigh, right_sum) = find_max_subarray(A, mid + 1, high)
        (crossLow, crossHigh, crossSum) = find_max_crossing_subarray(
            A, low, mid, high)
        if left_sum >= right_sum and left_sum >= crossSum:
            return (leftLow, leftHigh, left_sum)
        elif right_sum >= left_sum and right_sum >= crossSum:
            return (rightLow, rightHigh, right_sum)
        else:
            return (crossLow, crossHigh, crossSum)


if __name__ == '__main__':
    A = [int(x) for x in input().split()]
    (low, high, total) = find_max_subarray(A, 0, len(A))
    print("low=%d, high=%d, sum=%d" % (low, high, total))
