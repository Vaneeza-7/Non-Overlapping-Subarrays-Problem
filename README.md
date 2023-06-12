# Non-Overlapping-Subarrays-Problem

This repository contains a C++ implementation of the "Maximum Disjoint Subarrays" or "Non-overlapping subarrays" problem. The problem involves finding the maximum number of disjoint subarrays from a given array.

## Problem Description

Given an array of numbers and a set of groups, the goal is to determine whether each group can be formed from disjoint subarrays in the given array. Two subarrays are considered disjoint if they do not share any common elements or overlap in any way.

## Implementation

The solution is implemented in C++ and consists of the following files:

- `string.cpp`: Contains the main code for solving the problem.
- This also contains the test cases for the problem which aims to find n disjoint subarrays/groups in the nums array.
- The time complexity of this problem is `O(mnk^2)`, where m is size of nums array, n is size of groups array and k is size of each group inside groups.

## Usage

To use the code, follow these steps:

1. Clone the repository to your local machine.
2. Compile the code using a C++ compiler.
3. Run the compiled executable.

The code includes several test cases that can be used to verify the correctness of the implementation. These test cases cover a range of scenarios and can be found in the `string.cpp` file.

Feel free to modify the test cases or the code to suit your specific needs.

## License

This repository is licensed under the [MIT License](LICENSE).
