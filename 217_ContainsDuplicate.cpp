#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem: 
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 
Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/


/*
Approach 1: Brute Force
Intuition:
The brute force approach compares each element with every other element in the array to check for duplicates. If any duplicates are found, it returns true. This approach is straightforward but has a time complexity of O(n^2), making it less efficient for large arrays.

Explanation:
The brute force approach involves comparing each element in the array with every other element to check for duplicates. If any duplicates are found, return true, otherwise return false.

The time complexity of this approach is O(n^2), where n is the length of the array.
so, this approach is not efficient for large arrays
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

/*
Approach 2: Sorting
Intuition:
The sorting approach sorts the array in ascending order and then checks for adjacent elements that are the same. If any duplicates are found, it returns true. Sorting helps in bringing duplicates together, simplifying the check. However, sorting has a time complexity of O(n log n).

Explanation:
Another approach is to sort the array and then check for adjacent elements that are the same. If any duplicates are found, return true, otherwise return false

The time complexity of this approach is O(n log n), where n is the length of the array.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

/*
Approach 3: Hash Set
Intuition:
The hash set approach uses a hash set data structure to store encountered elements. It iterates through the array, checking if an element is already in the set. If so, it returns true. Otherwise, it adds the element to the set. This approach has a time complexity of O(n) and provides an efficient way to check for duplicates.

Explanation:
A more efficient approach is to use a hash set data structure to store the encountered elements. While iterating through the array, if an element is already present in the hash set, return true. Otherwise, add the element to the hash set. If the loop completes without finding any duplicates, return false.

The time complexity of this approach is O(n), where n is the length of the array.
*/

class Solution {

public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> set;

        for(int i =0 ;i<nums.size() ; i++){
            if(set.count(nums[i])){
                return true;
            }
            else{
                set.insert(nums[i]);
            }
        }
        return false;
    }
};

/*
Approach 4: Hash Map
Intuition:
The hash map approach is similar to the hash set approach but also keeps track of the count of occurrences for each element. It uses a hash map to store the elements as keys and their counts as values. If a duplicate element is encountered (count greater than or equal to 1), it returns true. This approach provides more information than just the presence of duplicates and has a time complexity of O(n).

Explanation:
In this approach, we iterate through the array and store each element as a key in a hash map. The value associated with each key represents the count of occurrences of that element. If we encounter an element that already exists in the hash map with a count greater than or equal to 1, we return true, indicating that a duplicate has been found. Otherwise, we update the count of that element in the hash map. If we complete the iteration without finding any duplicates, we return false.
The time complexity of this approach is O(n), where n is the length of the array
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> set;
        for (int num : nums) {
            if (set[num] >= 1)
                return true;
            set[num]++;
        }
        return false;
    }
};