def find_unique_assignment(symbols, str1, str2, str3):
    symbol_to_digit = {}
    digit_to_symbol = {}
    
    def is_valid_assignment():
        int1 = int("".join([symbol_to_digit[s] for s in str1]))
        int2 = int("".join([symbol_to_digit[s] for s in str2]))
        int3 = int("".join([symbol_to_digit[s] for s in str3]))
        return int1 + int2 == int3
    
    def backtrack(index):
        if index == len(symbols):
            if is_valid_assignment():
                return True
            return False
        
        for digit in range(10):
            symbol = symbols[index]
            if digit not in digit_to_symbol:
                symbol_to_digit[symbol] = str(digit)
                digit_to_symbol[digit] = symbol
                
                if backtrack(index + 1):
                    return True
                
                del symbol_to_digit[symbol]
                del digit_to_symbol[digit]
        
        return False
    
    if backtrack(0):
        assignment = [symbol_to_digit[s] for s in symbols]
        return "".join(assignment)
    else:
        return "No valid assignment found"

symbols = input()
str1 = input()
str2 = input()
str3 = input()

result = find_unique_assignment(symbols, str1, str2, str3)
print(result)
