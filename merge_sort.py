def merge_sort(array):
    size = len(array)
    if size < 2:
        return array
    mid = 0
    if size % 2 == 0:
        mid = size // 2 - 1
    else:
        mid = size // 2
    left = []
    right = []
    for i in range(0, mid + 1):
        left.append(array[i])
    for i in range(mid + 1, size):
        right.append(array[i])
    left = merge_sort(left)
    right = merge_sort(right)
    result = []    
    i = 0
    j = 0
    while i < len(left) or j < len(right):
        if i < len(left) and j < len(right) and left[i] < right[j]:
            result.append(left[i])
            i = i + 1
        elif i < len(left) and j < len(right) and right[j] <= left[i]:
            result.append(right[j])
            j = j + 1
        elif i >= len(left):
            result.append(right[j])
            j = j + 1
        else:
            result.append(left[i])
            i = i + 1
    return result

print('Demonstration of Merge Sort')
print('Enter the size of the array: ')
size = int(input())
print(f'Enter {size} integers: ')
array = []
for i in range(0, size):
    array.append(int(input()))
array = merge_sort(array)
print('Sorted array')
for element in array:
    print(f'{element} ', end="")
print("\n")
