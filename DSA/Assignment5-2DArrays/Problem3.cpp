// Question 3
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100]. After sorting, it becomes [0,1,9,16,100].


#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(nlogn)
// Time Complexity : O(n)
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0;
    int right = n - 1;
    int index = n - 1;
    
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[index] = nums[left] * nums[left];
            left++;
        } else {
            result[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }
    
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
