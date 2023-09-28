// PSID: 1921905
// Submission ID: 32e6aab1-6629-4b4b-a037-f42d9ad58cbb 

#include <iostream>
#include <sstream>
#include <vector>

int robertsPoints = 0;
int rachelsPoints = 0;

int helper(std::vector<int> &subOne, std::vector<int> &subTwo, int currIndex)
{
    int index = 0, temp = 0, final = 0;

    while(index < subTwo.size()){
        while(temp < subOne.size() && subTwo[index] > subOne[temp])
        {
            temp++;
        }
        final += temp;
        index++;
    }
    return final;
}

void merge(std::vector<int>& mergeArr1, std::vector<int>& mergeArr2, int leftPtr, int middlePtr, int rightPtr) 
{
    int size1 = middlePtr - leftPtr + 1;
    int size2 = rightPtr - middlePtr;

    std::vector<int> rob_l(size1);
    std::vector<int> rob_r(size2);
    std::vector<int> rach_l(size1);
    std::vector<int> rach_r(size2);

    for (int i = leftPtr, j = 0; i <= middlePtr; i++, j++)
    {
        rob_l[j] = mergeArr1[i];
        rach_l[j] = mergeArr2[i];
    }

    for (int i = middlePtr + 1, j = 0; i <= rightPtr; i++, j++)
    {
        rob_r[j] = mergeArr1[i];
        rach_r[j] = mergeArr2[i];
    }

    int i_for_Rob = 0;
    int j_for_Rob = 0;
    int i_for_Rach = 0;
    int j_for_Rach = 0;

    int robertIndex = leftPtr;
    int rachelIndex = leftPtr;


    if(i_for_Rob < size1 && j_for_Rob < size2)
    {
        int temp1 = helper(rach_l, rob_r, 0);
        robertsPoints += temp1;
        i_for_Rob++;
        j_for_Rob++;
    }

    if(i_for_Rach < size2 && j_for_Rach < size2)
    {
        int temp2 = helper(rob_l, rach_r, 0);
        rachelsPoints += temp2;
        i_for_Rach++;
        j_for_Rach++;
    }

    int first = 0;
    int second = 0;
    int arrI = leftPtr;

    while (first < size1 && second < size2)
    {
        if (rob_l[first] < rob_r[second])
        {
            mergeArr1[arrI] =  rob_l[first];
            first++;
        }

        else
        {
            mergeArr1[arrI] = rob_r[second];
            second++;
        }
        arrI++;
    }

    while (first < size1)
    {
        mergeArr1[arrI] = rob_l[first];
        first++;
        arrI++;
    }

    while (second < size2)
    {
        mergeArr1[arrI] = rob_r[second];
        second++;
        arrI++;
    }

    first = 0;
    second = 0;
    arrI = leftPtr;

    while (first < size1 && second < size2)
    {
        if (rach_l[first] < rach_r[second])
        {
            mergeArr2[arrI] =  rach_l[first];
            first++;
        }

        else
        {
            mergeArr2[arrI] = rach_r[second];
            second++;
        }
        arrI++;
    }

    while (first < size1)
    {
        mergeArr2[arrI] = rach_l[first];
        first++;
        arrI++;
    }

    while (second < size2)
    {
        mergeArr2[arrI] = rach_r[second];
        second++;
        arrI++;
    }
}

void mergeSort(std::vector<int>& in_list1, std::vector<int>& in_list2, int l, int r) 
{
    if (l == r)
    {
        return;
    }
    
    int middle = (l + r) / 2;
    mergeSort(in_list1, in_list2, l, middle);
    mergeSort(in_list1, in_list2, middle + 1, r);
    merge(in_list1, in_list2, l, middle, r);
}

int main() 
{   
    int read;
    int size = 0;
    std::string inString;
    std::vector<int> robertsNumbers(0);
    std::vector<int> rachelsNumbers(0);

    getline(std::cin, inString);
    std::istringstream robert(inString);

    while(robert >> read)
    {   
        robertsNumbers.push_back(read);
    }

    getline(std::cin, inString);
    std::istringstream rachel(inString);

    while(rachel >> read)
    {
        rachelsNumbers.push_back(read);
    }

    size = rachelsNumbers.size();
    mergeSort(robertsNumbers, rachelsNumbers, 0, size - 1);
    std::cout << robertsPoints << " " << rachelsPoints << std::endl;

    return 0;
}