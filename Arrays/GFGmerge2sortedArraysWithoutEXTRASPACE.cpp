// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Examples:

// Example 1:

// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]

// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 1,2,3,4,8,9,10.

// Example2:

// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]

// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]

// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9.

Approach:

Use a for loop in arr1.
Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
Rearrange arr2.
Repeat the process.

void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}
Time complexity: O(n*m)

Space Complexity: O(1) 
//further more optimise then we used gap methoid
  Approach:

Initially take the gap as (m+n)/2;
Take as a pointer1 = 0 and pointer2 = gap.
Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
After completion of the loop reduce the gap as gap=gap/2.
Repeat the process until gap>0.
  
  void merge(int ar1[], int ar2[], int n, int m) {
  // code here 
  int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && ar1[i] > ar1[j]) {
        swap(ar1[i], ar1[j]);
      } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        swap(ar1[i], ar2[j - n]);
      } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        swap(ar2[i - n], ar2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}
Time complexity: O(logn)

Space Complexity: O(1)
