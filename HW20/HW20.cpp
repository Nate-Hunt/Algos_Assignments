#include <iostream>
#include <sstream>
#include <vector>

struct node
{
    bool isFound = false;
    int nIndex = 0;
    int n = 0;
    int kIndex = 0;
};

void find(std::vector<int> inV, node* inP, int begin, int mid, int end)
{
    if (inV.size() == 1)
    {
        if (inV[begin] == inP -> n)
        {
            inP -> isFound = true;
            inP -> nIndex = begin + 1;
            return;
        }
    }
    
    int newMidL = (begin + mid) / 2;
    int newMidR = (mid + end) / 2;

    find(inV, inP, begin, newMidL, mid);
    find(inV, inP, mid, newMidR, end);

    if (inV[mid] > inV[mid + 1])
    {
        inP -> kIndex = mid + 1;
    }

    return;
}

 

int main()
{
    node* inputPointer;
    std::string inputString1;
    std::string inputString2;
    std::stringstream inputSS;
    int inputInt1;
    int inputInt2;
    std::getline(std::cin, inputString1);
    inputSS >> inputString1;
    std::getline(std::cin, inputString2);
    inputSS >> inputString2;
    
    std::cout << inputInt1 << std::endl;

    std::cout << inputInt2 << std::endl;

    std::vector<int> inputVector;

    int mid = inputVector[inputVector.size() / 2];

    find (inputVector, inputPointer, 0, mid, inputVector[inputVector.size() - 1]);
}