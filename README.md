This is some template of CP problems. 

[code Link](https://ideone.com/gvipU8).


- `For Boundary Traversal in Binary Tree` the flow will be
    ` 👉 Root → Left wall → Bottom leaves → Right wall (reverse) `

1.  # If vector<int> arr = {1, 2, 3, 4, 5}
    ## Then how many subarray will be created by every element can we calculate this with using any type of mathamatical function (like in how many subarray 1 is present, in how many 2 is present )

    => For an array of size `n`, an element at index `i` (0-based index) appears in: `(i + 1) × (n - i)`

    A subarray that contains arr[i] must:
    - Start anywhere from index `0 to i → (i + 1)` choices
    - End anywhere from index `i to n-1 → (n - i)` choices
    - Total combinations: `(i + 1) × (n - i)`


    ### Total number of subarrays
    For array of size n: `n(n+1)/2`
	​


