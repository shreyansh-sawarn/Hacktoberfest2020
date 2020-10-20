# Merge Sort Program
def mergeSort(li):
    if len(li) > 1:
        mid = len(li) // 2

        # Dividing the array in two halfs
        L = li[:mid]
        R = li[mid:]

        mergeSort(L)  # Sorting the first half
        mergeSort(R)  # Sorting the second half
        merge(li, L, R)  # Merging the sorted arrays


def merge(li, L, R):
    i = j = k = 0

    # Copy data to temp arrays L[] and R[]
    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            li[k] = L[i]
            i += 1
        else:
            li[k] = R[j]
            j += 1
        k += 1

    # Checking if any element was left
    while i < len(L):
        li[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        li[k] = R[j]
        j += 1
        k += 1


print("Enter a space seperated array of any length:")
li = list(map(int, input().split()))
print("Unsorted Array :", *li)
print("\nMerge Sort ...\n")
mergeSort(li)
print("Array after sorting:", *li)
