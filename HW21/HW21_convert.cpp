#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool is_valid_assignment(unordered_map<char, int>& symbol_to_digit, const string& s1, const string& s2, const string& s3) {
    int carry = 0;
    int n = s1.size();
    int num1;
    int num2;
    int num3;

    for (int i = n - 1; i >= 0; i--) {
        num1 = int(symbol_to_digit[s1[i]]);
        num2 = int(symbol_to_digit[s2[i]]);
        num3 = int(symbol_to_digit[s3[i]]);

        // int sum = num1 + num2 + carry;
        // carry = sum / 10;

        // if (sum % 10 != num3) {
        //     return false;
        // }
    }



    return true;
}

bool solve(vector<char>& symbols, int index, unordered_map<char, int>& symbol_to_digit, const string& s1, const string& s2, const string& s3) {
    if (index == symbols.size()) {
        return is_valid_assignment(symbol_to_digit, s1, s2, s3);
    }

    char symbol = symbols[index];
    for (int digit = index; digit <= 9; digit++) {
        if (symbol_to_digit.find(symbol) == symbol_to_digit.end()) {
            symbol_to_digit[symbol] = digit;
            if (solve(symbols, index + 1, symbol_to_digit, s1, s2, s3)) {
                return true;
            }
            symbol_to_digit.erase(symbol);
        }
    }

    return false;
}

int main() {
    string symbols_str = "ABC";
    string s1 = "ABC";
    string s2 = "CBA";
    string s3 = "ABAC";
    // cin >> symbols_str >> s1 >> s2 >> s3;

    vector<char> symbols(symbols_str.begin(), symbols_str.end());

    unordered_map<char, int> symbol_to_digit;

    if (symbols.size() > 10) {
        cout << "No solution possible!" << endl;
    } else if (solve(symbols, 0, symbol_to_digit, s1, s2, s3)) {
        for (char symbol : s1) {
            cout << symbol_to_digit[symbol];
        }
        cout << endl;
    } else {
        cout << "No solution possible!" << endl;
    }

    return 0;
}
