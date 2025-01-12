#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

/*
* @Solution :
Intuition
The Two Sum problem asks us to find two numbers in an array that sum up to a given target value. We need to return the indices of these two numbers.

Approach 1 : Brute Force
One brute force approach is to consider every pair of elements and check if their sum equals the target. This can be done using nested loops, where the outer loop iterates from the first element to the second-to-last element, and the inner loop iterates from the next element to the last element. However, this approach has a time complexity of O(n^2).

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};

/*
Approach 2 :Hash table:
A more efficient approach is to use a hash table (unordered_map in C++). We can iterate through the array once, and for each element, check if the target minus the current element exists in the hash table. If it does, we have found a valid pair of numbers. If not, we add the current element to the hash table.

Approach using a hash table:

1.Create an empty hash table to store elements and their indices.
2.Iterate through the array from left to right.
3.For each element nums[i], calculate the complement by subtracting it from the target: complement = target - nums[i].
4.Check if the complement exists in the hash table. If it does, we have found a solution.
5.If the complement does not exist in the hash table, add the current element nums[i] to the hash table with its index as the value.
6.Repeat steps 3-5 until we find a solution or reach the end of the array.
7.If no solution is found, return an empty array or an appropriate indicator.

This approach has a time complexity of O(n) since hash table lookups take constant time on average. It allows us to solve the Two Sum problem efficiently by making just one pass through the array

*/

//(Two-pass Hash Table)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

//(One-pass Hash Table)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

/*
Approach 3 : Two-pointer approach.

Approach -> 
1. Index Tracking: Since we need the original indices, store each number along with its index in a pair.
2. Sorting: Sort the array based on the number values.
3. Two-Pointer Technique: Use two pointers, one starting at the beginning (left) and the other at the end (right) of the sorted array.
   --Calculate the sum of the numbers pointed to by left and right.
   --If the sum matches the target, return the indices.
   --If the sum is less than the target, move the left pointer forward to increase the sum.
   --If the sum is greater than the target, move the right pointer backward to decrease the sum.

Complexity -> 
- Time complexity: O(nlogn)
  Sorting the array takes O(nlogn), and the two-pointer traversal is O(n).
- Space complexity: O(n)
  Extra space is required to store the indexed pairs.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store numbers along with their original indices
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }

        // Sort the array by the number values
        sort(indexedNums.begin(), indexedNums.end());

        // Initialize two pointers
        int left = 0, right = nums.size() - 1;

        // Two-pointer approach to find the target sum
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            
            // Check if the current pair matches the target
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } 
            // If sum is less than target, move the left pointer
            else if (sum < target) {
                ++left;
            } 
            // If sum is greater than target, move the right pointer
            else {
                --right;
            }
        }

        // Return an empty vector if no solution is found
        return {};
    }
};