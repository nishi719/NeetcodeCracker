#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem:

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

/*
Approach 1: Brute Force

Intuition:
A simple way to solve the problem is:
1.Extract only alphanumeric characters from the string.
2.Reverse the filtered string.
3.Compare the reversed string with the original filtered string.

Algorithm:
1.Create a new string containing only alphanumeric characters (ignoring cases).
2.Reverse this filtered string.
3.Check if the filtered string matches its reversed version.

Complexity:
- Time Complexity: O(n) for filtering and O(n) for reversing the string, so overall O(n).
    
- Space Complexity: O(n) for the filtered string and reversed string.
*/


bool isPalindrome(string s) {
    string filtered = "";
    
    // Filter out non-alphanumeric characters
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    
    // Reverse the filtered string
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());

    // Compare filtered and reversed strings
    return filtered == reversed;
}

/*
Approach 2: Two-Pointer Technique (Optimized)
Intuition:
Instead of creating a new string, use two pointers:
1.One pointer starts at the beginning (left), and the other starts at the end (right) of the string.
2.Move the pointers towards the center, skipping non-alphanumeric characters.
3.Check if the characters at left and right match (ignoring case).

Algorithm:
1.Initialize two pointers: left = 0 and right = s.length() - 1.
2.While left < right:
    - Move left forward if it points to a non-alphanumeric character.
    - Move right backward if it points to a non-alphanumeric character.
    - If the characters at left and right do not match, return false.
3.Return true if the loop completes.

Complexity:
- Time Complexity: O(n) since each character is processed once.
- Space Complexity: O(1) as no extra space is used.
*/

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        // Compare characters, ignoring case
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        // Move pointers
        left++;
        right--;
    }

    return true;
}

/*
Approach 3: Best (Optimized Two-Pointer with Early Exit)

Intuition:
Same as the two-pointer technique, but with an additional optimization:
    - Exit early if left becomes greater than or equal to right after skipping non-alphanumeric characters.

Algorithm:
Same as the optimized two-pointer technique, with an emphasis on early exit.


Complexity:
- Time Complexity: O(n) for processing the string once with early exits when mismatches are found.
- Space Complexity: O(1).
*/

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        // Check mismatch early
        if (left < right && tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        // Move pointers
        left++;
        right--;
    }

    return true;
}
