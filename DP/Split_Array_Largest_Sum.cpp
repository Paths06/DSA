// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.




class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum){
     int subArrayCount =1;
     long long currentSum= 0;
        for(int num:nums){
            if(currentSum+num>maxSum){
                subArrayCount++;
                currentSum=num;
                if(subArrayCount>k){
                    return false;
                }
            }
            else{
                currentSum+=num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = right;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(canSplit(nums,k, mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};
