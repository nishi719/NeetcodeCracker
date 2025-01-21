#include<bits/stdc++.h>
using namespace std;

/*
* @Author: [Nishi Kumari]

* @Problem:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.


*/

/*
* @Solution :

Approach 1: Brute Force
Intuition:
For each element in the array, calculate the product of all elements except itself by iterating through the array. This results in 
O(n^2) time complexity.

Algorithm:
1.For each element nums[i]:
    - Initialize a product variable as 1.
    - Multiply all elements in nums except nums[i].

2.Store the result for nums[i] in the answer array.

Complexity:
- Time Complexity: O(n^2), due to the nested loops.
- Space Complexity: O(1), excluding the output array.

Drawback:
This approach is inefficient for larger arrays due to its quadratic time complexity.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= nums[j];
            }
        }
        answer[i] = product;
    }

    return answer;
}

/*
Approach 2: Optimized Using Prefix and Suffix Products

Intuition:
Instead of calculating the product for every element repeatedly, we can use prefix and suffix arrays:
    - Prefix product: Product of all elements before the current index.
    - Suffix product: Product of all elements after the current index.
    - Multiply the prefix and suffix values for each element to get the desired result.

Algorithm:
1.Compute a prefix product array, where prefix[i] contains the product of all elements before index i.
2.Compute a suffix product array, where suffix[i] contains the product of all elements after index i.
3.For each index i, the result is prefix[i] * suffix[i].

Complexity:
- Time Complexity: O(n), as we compute prefix and suffix arrays in linear time.
- Space Complexity: O(n), for the prefix and suffix arrays.

*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 1), suffix(n, 1), answer(n);

    // Calculate prefix product
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Calculate suffix product
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Multiply prefix and suffix products
    for (int i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    return answer;
}

/*
Approach 3: Optimized Space Complexity

Intuition:
Instead of using separate prefix and suffix arrays, calculate the prefix product on the fly and store it in the result array. Then, traverse the array from right to left to calculate the suffix product, while directly updating the result array.

Algorithm:
1.Traverse the array from left to right to calculate the prefix product and store it in the answer array.
2.Traverse the array from right to left to calculate the suffix product and multiply it with the corresponding value in the answer array.

Complexity:
Time Complexity: O(n), as we traverse the array twice.
Space Complexity: O(1), as no additional arrays are used.
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);

    // Calculate prefix product
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix product and multiply with prefix
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}
