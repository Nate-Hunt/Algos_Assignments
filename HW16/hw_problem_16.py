# PSID: 1921905
# Submission ID: c89cd794-1029-429e-8388-35661897a31d 

def seesaw(val, nums_remaining, step, is_left):
    if nums_remaining <= 1:
        return val
    else:
        if is_left or nums_remaining % 2 == 1:
            val += step
        return seesaw(val, nums_remaining // 2, step * 2, not is_left)
    
    
    
def main():
    input_n = input()
    print(seesaw(1, int(input_n), 1, True))
    
if __name__ == "__main__":
    main()