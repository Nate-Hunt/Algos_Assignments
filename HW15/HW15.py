# PSID: 1921905
# Submission ID: 497d36b2-66e1-4e82-8b25-e666b03b33d9

def stairMaster(height, max_steps):
    if height == 0:
        return 1

    variations = 0

    for step in range(1, min(height, max_steps) + 1):
        variations += stairMaster(height - step, max_steps)

    return variations

height = int(input())
max_steps = int(input())
permutations = stairMaster(height, max_steps)
print(permutations)

