// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4



#include <bits/stdc++.h>
using namespace std;

// Approach : Binary Search
// - Time Complexity : O(logn)
// - Space Complexity : O(1)

int search(vector<int>& nums, int target) {
    int start= 0;
    int end= nums.size()-1;
    while(start<= end){
        int mid= (start+end)/2;
        if(nums[mid]== target) return mid;
        else if(nums[mid]<target) start= mid+1;
        else end= mid-1;
    }
    return -1;
}

int main(){
	vector<int> nums{-1,0,3,5,9,12};
	int target= 9;
	cout << search(nums, target) << endl;
	return 0;
}