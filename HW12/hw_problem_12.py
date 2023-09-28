import queue

# pq = queue.PriorityQueue()

def divisible(arr: list[int], k):
    if len(arr) % k != 0:
        return False
    else:
        return True
    
def recursion_fairy(arr, k):
    while 
    
# def create_frequency_heap(arr, k):
#     frequency_heap = []
#     temp = arr
#     count = 0
#     n = 0
#     n = 0
#     while n < len(temp):
#         m = n
#         while m < len(temp) and temp[m] == temp[n]:
#             count += 1
#             m += 1
#         n = m 
    
#         frequency_heap.append(count)
#         count = 0
    
#     return frequency_heap

def main():
    # arr = [int(x) for x in input().split()]
    arr = [3, 2, 2, 1, 7, 5]
    arr.sort() # min heap
    # k = int(input())
    k = 2
    print(create_frequency_heap(arr, k))
    
if __name__ == "__main__":
    main()
