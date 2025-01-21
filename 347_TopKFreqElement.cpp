#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

*/

/*
* @Solution : 

Approach 1: Brute Force Using Frequency Count

Intuition:
Count the frequency of each element using a frequency map and then sort the elements by their frequencies. Pick the top k elements from the sorted list.

Algorithm:
1.Use a hash map to count the frequency of each element.
2.Sort the hash map keys based on their frequencies in descending order.
3.Select the first k elements from the sorted list.

Complexity:
- Time Complexity: O(n+nlogn)
    - O(n) for counting frequencies.
    - O(nlogn) for sorting.

- Space Complexity: O(n), for the hash map and intermediate vector

Drawback:
Sorting is unnecessary for this problem as we only need the top k elements.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Convert map to a vector of pairs
    vector<pair<int, int>> freqVector(freqMap.begin(), freqMap.end());

    // Sort by frequency in descending order
    sort(freqVector.begin(), freqVector.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    });

    // Collect the top k frequent elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqVector[i].first);
    }

    return result;
}

/*
Approach 2: Optimized Using Max Heap
Intuition:
To avoid sorting the entire frequency map, we can use a max heap to keep track of the k most frequent elements. A heap efficiently retrieves the top elements.

Algorithm:
1.Use a hash map to count the frequencies of elements.
2.Push each element-frequency pair into a max heap (priority queue) based on frequency.
3.Extract the top k elements from the heap.

Complexity:
- Time Complexity: O(n+klogn)
    - O(n) for counting frequencies.
    - O(nlogn) for inserting into the heap.
    - O(klogn) for extracting k elements.
- Space Complexity: O(n), for the hash map and heap.

*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Use a max heap (priority queue) to store pairs {frequency, element}
    priority_queue<pair<int, int>> maxHeap;
    for (auto& [num, freq] : freqMap) {
        maxHeap.push({freq, num});
    }

    // Extract the top k frequent elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

/*
Approach 3: Best Using Min Heap
Intuition:
Instead of a max heap, use a min heap of size k to store the most frequent elements. This keeps the heap size constant at k, making it more efficient for larger inputs.

Algorithm:
1.Use a hash map to count frequencies.
2.Use a min heap to store the k most frequent elements:
    - Push elements into the heap.
    - If the heap size exceeds k, remove the smallest frequency element.
3.Extract all elements from the heap to get the result.

Complexity:
- Time Complexity: O(n+nlogk)
    - O(n) for counting frequencies.
    - O(nlogk) for inserting into the heap (maintaining size k).
- Space Complexity: O(n+k)
    - O(n) for the hash map.
    - O(k) for the heap.
*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Use a min heap to keep the top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& [num, freq] : freqMap) {
        minHeap.push({freq, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract the top k elements
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

/*
Approach 4: Best Using Bucket Sort
Intuition:
If the maximum frequency is much smaller than the array size n, we can use a bucket sort approach. Group elements by their frequencies in a bucket array, where the index represents the frequency.

Algorithm:
1.Count frequencies using a hash map.
2.Create a bucket array where bucket[i] stores all elements with frequency i.
3.Traverse the bucket array in reverse (from high frequency to low) to collect the top k elements.

Complexity:
- Time Complexity: O(n)
    - O(n) for counting frequencies.
    - O(n) for bucket creation and traversal.
- Space Complexity: O(n), for the hash map and bucket array.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Create buckets for frequencies
    int n = nums.size();
    vector<vector<int>> buckets(n + 1);

    for (auto& [num, freq] : freqMap) {
        buckets[freq].push_back(num);
    }

    // Collect the top k elements from buckets
    vector<int> result;
    for (int i = n; i > 0 && result.size() < k; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }

    return result;
}
