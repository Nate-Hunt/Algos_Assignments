#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> mergeArr1, std::vector<int> mergeArr2) {
    std::vector<int> mergedArr;
    while (!mergeArr1.empty() && !mergeArr2.empty()) {
        if (mergeArr1[0] <= mergeArr2[0]) {
            mergedArr.push_back(mergeArr1[0]);
            mergeArr1.erase(mergeArr1.begin());
        } else if (mergeArr2[0] < mergeArr1[0]) {
            mergedArr.push_back(mergeArr2[0]);
            mergeArr2.erase(mergeArr2.begin());
        }
    }
    if (!mergeArr1.empty()) {
        mergedArr.insert(mergedArr.end(), mergeArr1.begin(), mergeArr1.end());
        mergeArr1.clear();
    }
    if (!mergeArr2.empty()) {
        mergedArr.insert(mergedArr.end(), mergeArr2.begin(), mergeArr2.end());
        mergeArr2.clear();
    }
    return mergedArr;
}

std::vector<int> mergeSort(std::vector<int> in_list) {
    if (in_list.size() <= 1) {
        return in_list;
    }
    int midpoint = in_list.size() / 2;
    std::vector<int> left(in_list.begin(), in_list.begin() + midpoint);
    std::vector<int> right(in_list.begin() + midpoint, in_list.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    std::vector<int> exampleList = {4, 2, 8, 10, 42, 2, 4, 5, 90, 71, 17, 8};
    std::vector<int> sortedList = mergeSort(exampleList);
    for (int num : sortedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}