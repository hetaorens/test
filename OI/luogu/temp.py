def longest_consecutive_sequence(nums, n):
    count_dict = {}
    max_length = 0
    left = 0

    for right in range(len(nums)):
        count_dict[nums[right]] = count_dict.get(nums[right], 0) + 1

        while len(count_dict) > n:
            count_dict[nums[left]] -= 1
            if count_dict[nums[left]] == 0:
                del count_dict[nums[left]]
            left += 1

        max_length = max(max_length, right - left + 1)

    return max_length
nums=[1, 2, 3, 2, 1, 4, 5, 1]
n=3
print(longest_consecutive_sequence(nums, n))