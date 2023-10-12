#include <iostream>
#include <sstream>
#include <vector>

bool isValid(std::string str1, std::string str2, std::string result)
{
    if(stoi(str1) + stoi(str2) == stoi(result))
    {
        std::cout << stoi(str1) << " + " << stoi(str2) << " = " << stoi(result) << std::endl;
        return true;
    }
    return false;
}

bool backtrack(int index, std::string symbols, std::string str1, std::string str2, std::string result)
{
    if (index == symbols.size())
    {
        if (isValid(str1, str2, result) == true)
        {
            return true;
        }
        return false;
    }

    for (int i = 0; i < 10; i++)
    {

    }
}

int findAssignment(std::vector<std::string> symbols, std::string str1, std::string str2, std::string result)
{

    std::string digitArr = "";
    std::string symbolArr = "";

    


    return 0;

}

int main()
{
    std::string str1 = "123";
    std::string str2 = "321";
    std::string result = "444";
    isValid(str1, str2, result);
}