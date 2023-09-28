def merge(mergeArr1: list[int], mergeArr2: list[int]) -> list[int]:
    mergedArr = []
    while len(mergeArr1) > 0 and len(mergeArr2) > 0:
        if mergeArr1[0] <=  mergeArr2[0]:
            mergedArr.append(mergeArr1[0])
            mergeArr1.pop(0)
            
        elif mergeArr2[0] < mergeArr1[0]:
            mergedArr.append(mergeArr2[0])
            mergeArr2.pop(0)
    if len(mergeArr1) > 0:
        mergedArr += mergeArr1
        mergeArr1 = []
    if len(mergeArr2) > 0:
        mergedArr += mergeArr2
        mergeArr2 = []
    return mergedArr

def mergeSort(in_list: list[int]):
    if len(in_list) <= 1:
        return in_list
    
    midpoint = len(in_list) // 2
    left = in_list[:midpoint]
    right = in_list[midpoint:]
    
    left = mergeSort(left)
    right = mergeSort(right)
    
    return merge(left, right)
    
def main():
    exampleList = [4, 2, 8, 10, 42, 2, 4, 5, 90, 71, 17, 8]
    print(mergeSort(exampleList))

if __name__ == "__main__":
    main()