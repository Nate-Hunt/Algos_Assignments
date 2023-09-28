# Basic Steps for Recursion
def find_minimum_of_array(arr, lowest, highest):
    minimum = arr[lowest]
    for i in range(lowest, highest + 1):
        if arr[i] < min:
            min = arr[i]
        return minimum

def find_maximum_of_array(arr, lowest, highest):
    maximum = arr[lowest]
    for j in range(lowest, highest + 1):
        if arr[j] > min:
            max = arr[j]
        return maximum
    
def find_maximum_difference(arr: list, lowest, highest):
    if lowest >= highest:
        return 0
    
    mid = (lowest + highest) // 2
    
    left = find_maximum_difference(arr, lowest, mid)
    right = find_maximum_difference(arr, mid + 1, highest)
    
    diff = max(arr[mid + 1:]) - min(arr[lowest:mid + 1])
    temp = max(max(left, right), diff)
    return temp

def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(find_maximum_difference(arr, 0, n - 1))
    
if __name__ == "__main__":
    main()