//PSID: 1921905
//Submission ID: 25238547-7c04-495d-b2e6-a1f336de38df

#include <iostream>
#include <vector>
#include <algorithm>

int find_minimum_of_array(std::vector<int>& arr, int lowest, int highest) {
    int minimum = arr[lowest];
    for (int i = lowest; i <= highest; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int find_maximum_of_array(std::vector<int>& arr, int lowest, int highest) {
    int maximum = arr[lowest];
    for (int j = lowest; j <= highest; j++) {
        if (arr[j] > maximum) {
            maximum = arr[j];
        }
    }
    return maximum;
}

int find_maximum_difference(std::vector<int>& arr, int lowest, int highest) {
    if (lowest >= highest) {
        return 0;
    }
    int mid = (lowest + highest) / 2;
    int left = find_maximum_difference(arr, lowest, mid);
    int right = find_maximum_difference(arr, mid + 1, highest);
    int diff = *std::max_element(arr.begin() + mid + 1, arr.begin() + highest + 1) - *std::min_element(arr.begin() + lowest, arr.begin() + mid + 1);
    int temp = std::max(std::max(left, right), diff);
    return temp;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << find_maximum_difference(arr, 0, n - 1) << std::endl;
    return 0;
}