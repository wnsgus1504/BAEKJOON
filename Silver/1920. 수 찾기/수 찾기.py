def binary_search(array, target, start, end):
    if start > end:
        return 0
    mid = (start + end) // 2

    if array[mid] == target:
        return 1
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)
    else:
        return binary_search(array, target, mid + 1, end)

N = int(input())

A = [*map(int, input().split())]

A.sort()

length = int(input())
B = [*map(int, input().split())]
for i in B:
    print(binary_search(A, i, 0, N - 1))