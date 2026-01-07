# Projet INDP1 - Longest Substring Without Repeating Characters

##  Project Information
- *Chosen Problem*: Longest Substring Without Repeating Characters
- *LeetCode Reference*: [LeetCode 3 - Medium](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- *Team*: Allani Nour / Azzabou Chayma / Hamdi Sara / Laouini Rawand
- *Date*: 2026
- *Language*: C

## Use Cases
This solution models several real-world scenarios, including:
- *Server log analysis*: Identifying the longest period without repeated events .
- *Data stream validation*: Detecting unique sequences in data streams .
- *Cybersecurity*: Analyzing patterns in passwords.
- *Bioinformatics*: Searching for unique DNA sequences.

## Approach and Solution
We implemented a sliding window approach with a simple hash table (size 256 for ASCII characters). The algorithm traverses the string only once, ensuring linear time complexity.

### Algorithm :
1.Initialize an array last_index to store the last index of each character.
2. Initialize two pointers start and end to represent the current window.
3. For each character at index end:
   - If the character is already in the window (last_index[character] >= start), move start to last_index[character] + 1.
   - Update last_index[character] with end.
   - Calculate the window length and update the maximum length.

## Complexity
- *Time Complexity*: O(n) - single pass over a string of length n.
- *Space Complexity*: O(1) - fixed-size array of 256 integers.

## Compilation and Execution

### Prerequisites:
- GCC (MinGW sur Windows, gcc sur Linux/Mac)

### Compilation
```bash
gcc -Wall -std=c99 -o longest_substring src/longest_substring.c tests/test_longest_substring.c"# longest-substring.c"
