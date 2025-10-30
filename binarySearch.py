sorted_list = [1, 4, 7, 9, 11, 34, 78, 80, 100]

left = 0
right = len(sorted_list) - 1 # 8
target_value = 78

while sorted_list[left] != target_value:
    test_index = (left + right)//2 # divide and round down

    test_value = sorted_list[test_index]

    if test_value > target_value:
        right = test_index
    else:
        left = test_index
print(left)
