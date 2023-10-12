# PSID: 1921905
# Submission ID: 096d7eb0-4535-45c0-92f6-92573a3cccfb 

def findK(arr, low, high):
    if high < low:
        return 0
    if high == low:
        return low

    mid = (low + high) // 2

    if mid < high and arr[mid] > arr[mid + 1]:
        return mid + 1
    if mid > low and arr[mid] < arr[mid - 1]:
        return mid

    if arr[high] > arr[mid]:
        return findK(arr, low, mid - 1)
    return findK(arr, mid + 1, high)

array = list(map(int, input().split()))

rotation_count = findK(array, 0, len(array) - 1)

def findN(arr, low, high, x):
    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == x:
        return mid

    if arr[low] <= arr[mid]:
        if arr[low] <= x <= arr[mid]:
            return findN(arr, low, mid - 1, x)
        return findN(arr, mid + 1, high, x)

    if x >= arr[mid] and x <= arr[high]:
        return findN(arr, mid + 1, high, x)
    return findN(arr, low, mid - 1, x)

valN = int(input())
indexN = findN(array, 0, len(array) - 1, valN)

print(rotation_count)
print(indexN)