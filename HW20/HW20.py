# PSID: 1921905
# Submission ID: 16adb749-949d-4917-8ff7-116c8c2b7be1 

def is_stepping_number(num_str):
    for i in range(len(num_str) - 1):
        if abs(int(num_str[i]) - int(num_str[i + 1])) != 1:
            return False
    return True

def generate_stepping_numbers_helper(current, low, high, result):
    if low <= current <= high:
        result.append(current)

    if current == 0 or current > high:
        return

    last_digit = current % 10

    next1 = current * 10 + (last_digit - 1)
    next2 = current * 10 + (last_digit + 1)

    if last_digit > 0:
        generate_stepping_numbers_helper(next1, low, high, result)
    if last_digit < 9:
        generate_stepping_numbers_helper(next2, low, high, result)

def generate_stepping_numbers(low, high):
    result = []
    for i in range(10):
        generate_stepping_numbers_helper(i, low, high, result)
    
    return sorted(result)

# Input
low = int(input())
high = int(input())

# Output
result_str = ' '.join(map(str, generate_stepping_numbers(low, high)))
print(result_str)
