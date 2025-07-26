def merge_sort(array):
    size = len(array)
    if size == 1:
        return array
    mid = (size % 2 == 0) ? n // 2 - 1 : n // 2
    left = []
    right = []
    
