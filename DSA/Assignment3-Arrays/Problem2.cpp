// Question 2
// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
//            ● 0 <= a, b, c, d < n
//            ● a, b, c, and d are distinct.
//            ● nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// Time Complexity : O(n^4)
// Space Complexity : O(n)
vector<vector<int>> fourSumApproach1(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            for(int k=j+1; k<n-1; k++){
                for(int l=k+1; l<n; l++){
                    if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + 
                    (long long)nums[l] == target){
                        set.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }
    for(auto it : set){
        output.push_back(it);
    }
    return output;
}


// Approach 2: Sorting + Hashtable
// - Time Complexity : O(n^3)
// - Space Complexity : O(n)
vector<vector<int>> fourSumApproach2(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            int low = j+1, high = n-1;
            while(low < high){
                if(nums[low] + nums[high] < newTarget){
                    low++;
                }
                else if(nums[low] + nums[high] > newTarget){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++; high--;
                }
            }
        }
    }
    for(auto it : set){
        output.push_back(it);
    }
    return output;
}


int main(){
    // Input: nums = [1,0,-1,0,-2,2], 
    vector<int> nums{1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int> > ans;
    ans = fourSumApproach1(nums, target);
    ans = fourSumApproach2(nums, target);

    for(auto it: ans){
        for(auto temp: it)
            cout << temp << " ";

        cout << endl;
    }
    return 0;
}