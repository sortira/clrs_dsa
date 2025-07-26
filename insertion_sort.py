def insertion_sort(array):
    size = len(array)
    for i in range(1, size):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = key
    return array

print('Demonstration of Insertion Sort')
print('Enter the size of the array = ')
n = int(input())
array = []
print(f"Enter {n} integers = ")
for i in range(0, n):
    array.append(int(input()))
print('Sorted array')
result = insertion_sort(array)
for element in result:
    print(f"{element}, ", end="")
