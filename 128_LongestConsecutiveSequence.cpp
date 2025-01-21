#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

/*
* @Solution : 

Approach 1: Brute Force
Intuition:
The simplest way to find the longest consecutive sequence is to check every possible subsequence in the array. This involves:
    - Sorting the array to identify consecutive sequences easily.
    - Traversing the sorted array to find the longest consecutive sequence.

Algorithm:
1.If nums is empty, return 0.
2.Sort the array.
3.Iterate through the sorted array and count the length of each consecutive sequence.
4.Keep track of the maximum length.

Complexity:
- Time Complexity: O(nlogn)
    - Sorting takes O(nlogn).
    - Traversing the array takes O(n).
- Space Complexity: O(1) (ignoring the space used by sorting).
*/

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    // Sort the array
    sort(nums.begin(), nums.end());

    int maxLength = 1, currentLength = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue; // Skip duplicates
        if (nums[i] == nums[i - 1] + 1) {
            currentLength++; // Extend the sequence
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1; // Reset for a new sequence
        }
    }

    return max(maxLength, currentLength);
}

/*
Approach 2: Optimized Using HashSet
Intuition:
Instead of sorting, we can use a hash set to allow O(1) lookups. For each number in the array, check if it is the start of a sequence (i.e., num - 1 is not in the set). Then count the length of the sequence by incrementing the number.

Algorithm:
1.Add all elements to a hash set.
2.For each number in the array:
    - If num - 1 is not in the set, it is the start of a sequence.
    - Count the sequence length by incrementing num.
3.Keep track of the maximum sequence length.

Complexity:
- Time Complexity: O(n)
    Each number is processed once, and the while loop iterates over the sequence only.

- Space Complexity: O(n) for the hash set.

*/
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : nums) {
        if (!numSet.count(num - 1)) { // Start of a sequence
            int currentNum = num;
            int currentLength = 1;

            while (numSet.count(currentNum + 1)) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

/*
Approach 3: Best Using Union-Find (Disjoint Set Union)

Intuition:
Union-Find is useful for grouping numbers into sets where each set represents a consecutive sequence. Once all numbers are grouped, find the size of the largest set.

Algorithm:
1.Create a Union-Find structure where each number points to itself initially.
2.Use the Union-Find structure to group consecutive numbers into the same set.
3.Count the size of the largest set.

Complexity:
- Time Complexity: O(n⋅α(n)), where α(n) is the inverse Ackermann function (almost constant for practical purposes).
- Space Complexity: O(n) for the Union-Find data structure.

*/
class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    void add(int x) {
        if (parent.count(x) == 0) {
            parent[x] = x;
            size[x] = 1;
        }
    }
};

int longestConsecutive(vector<int>& nums) {
    UnionFind uf;

    // Add all elements to the Union-Find structure
    for (int num : nums) {
        uf.add(num);
    }

    // Union consecutive elements
    for (int num : nums) {
        if (uf.parent.count(num + 1)) {
            uf.unionSet(num, num + 1);
        }
    }

    // Find the largest set size
    int maxLength = 0;
    for (auto& [key, value] : uf.size) {
        maxLength = max(maxLength, value);
    }

    return maxLength;
}

