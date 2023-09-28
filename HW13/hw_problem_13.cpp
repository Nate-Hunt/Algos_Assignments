#include <iostream>
#include <vector>
#include <sstream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) 
    {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

TreeNode* LCA(TreeNode* head, int val1, int val2)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    else if(head -> val == val1 and head -> val == val2)
    {
        return head;
    }

    else if(val1 > head -> val && val2 > head -> val)
    {
        LCA(head -> right, val1, val2);
    }

    else if (val1 < head -> val && val2 < head -> val)
    {
        LCA(head -> left, val1, val2);
    }

    return head;
}

int search(TreeNode* root, int key, int level)
{
    if (root == NULL)
        return -1;
    
    if (root -> val == key)
        return level;
 
    if (root->val < key)
        return search(root->right, key, level + 1);
 
    return search(root->left, key, level + 1);
}

int main()
{
    TreeNode* root = nullptr;
    
    std::string input;
    std::string input2;
    std::vector<int> numbers;
    std::vector<int> numbers2;

    // std::cout << "Enter a space-separated list of integers: ";
    std::getline(std::cin, input);
    std::getline(std::cin, input2);

    std::istringstream iss(input);
    std::istringstream iss2(input2);
    int number;
    int number2;

    while (iss >> number)  
    {
        // numbers.push_back(number);
        root = insert(root, number);
    }

    while (iss2 >> number2)
    {
        numbers2.push_back(number2);
    }

    int leftTree = search(LCA(root, numbers2[0], numbers2[1]), numbers2[0], 0);
    int rightTree = search(LCA(root, numbers2[0], numbers2[1]), numbers2[1], 0);
    std::cout << leftTree + rightTree  << std::endl;
        


    // return 0;
    
}