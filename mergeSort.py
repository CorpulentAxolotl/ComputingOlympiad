def split_and_sort(arr): #splitting and running merge
    if len(arr) <= 1: # if the length hits 1 we're done splitting
        return arr
    
    mid = len(arr) // 2 # middle index of current sublist

    left = split_and_sort(arr[:mid]) # colon slices the array at the middle index
    right = split_and_sort(arr[mid:]) #left colon means left slice, right colon means right slice
    #we recursively call merge_sort on smaller and smaller arrays 
    return merge_sort(left, right) #this line is reached when the array is done splitting

def merge_sort(left, right): # merging function
    result = [] # to be sorted array
    i = j = 0 # the indexes of the elements to compare
    
    while i < len(left) and j < len(right): # repeat until one sub-array is empty
        if left[i] < right[j]: # add the smallest to the result
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    # Add leftovers, since they are the greater than all values in current result array
    # one of these will be empty
    result.extend(left[i:])
    result.extend(right[j:])

    # return the sorted sub-array to be sorted into a bigger sub-array
    return result

# Test
arr = [6, 4, 5, 8, 2, 10, 34, 12, 11]
print(split_and_sort(arr))
