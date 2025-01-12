#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem: 

Given an array of strings strs, group the 
anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

/*
* @Solution : 
Key Intuition :
Strings that are anagrams of each other will have the same "signature" if sorted or represented by the frequency of their characters. By grouping strings based on their signature, we can efficiently identify and group anagrams.

Approach 1: Sorting as a Signature :
Idea:
-- Sort each string alphabetically. Anagrams will have the same sorted version.
-- Use a hashmap where the key is the sorted string, and the value is a list of anagrams.

Algorithm:
1.Initialize an empty hashmap.
2.For each string in the array:
  --Sort the string.
  --Use the sorted string as a key in the hashmap and append the original string to the value list.
3.Return all values in the hashmap as the result.

Complexity:
Time Complexity: O(n . k log k), where n is the number of strings, and k is the average length of a string (sorting each string takes O(k log k).
Space Complexity: O(n.k), for the hashmap storage.

*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& entry : anagramMap) {
            result.push_back(entry.second);
        }
        return result;
    }
};

/*
Approach 2: Frequency Count as a Signature

Idea:
Instead of sorting, use the frequency of each character (a 26-element array for lowercase English letters) as the signature. This avoids the overhead of sorting.

Algorithm:
1.Initialize an empty hashmap.
2.For each string in the array:
  -- Compute a frequency count for the string.
  -- Use the frequency count (converted to a tuple) as a key in the hashmap and append the original string to the value list.
3.Return all values in the hashmap as the result.


Complexity:
Time Complexity: O(n . k), where nis the number of strings, and k is the average length of a string (building the frequency count takes O(k).
Space Complexity: O(n . k), for the hashmap storage.

*/
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& str : strs) {
            array<int, 26> charCount = {0};
            for (char c : str) {
                charCount[c - 'a']++;
            }
            string key = "";
            for (int count : charCount) {
                key += "#" + to_string(count);
            }
            anagramMap[key].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& entry : anagramMap) {
            result.push_back(entry.second);
        }
        return result;
    }
};


/*
Example Walkthrough :
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Sorting Approach:

After sorting:

"eat" → "aet"
"tea" → "aet"
"tan" → "ant"
"ate" → "aet"
"nat" → "ant"
"bat" → "abt"

Grouping by sorted key:

Key "aet" → ["eat", "tea", "ate"]
Key "ant" → ["tan", "nat"]
Key "abt" → ["bat"]

Frequency Count Approach:
Frequency counts:

"eat" → [1, 0, 0, ..., 1, 1, 0]
"tea" → [1, 0, 0, ..., 1, 1, 0]
"tan" → [1, 0, ..., 1, 0, 0]
"ate" → [1, 0, 0, ..., 1, 1, 0]
"nat" → [1, 0, ..., 1, 0, 0]
"bat" → [1, 1, ..., 0, 0, 0]

Grouping by frequency key:

Key [1, 0, ..., 1, 1, 0] → ["eat", "tea", "ate"]
Key [1, 0, ..., 1, 0, 0] → ["tan", "nat"]
Key [1, 1, ..., 0, 0, 0] → ["bat"]
*/