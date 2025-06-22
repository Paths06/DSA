class Solution {
public:
    vector<vector<int>> result;

    // dsf/recursive approach
    void backtrack(vector<int>& nums, int start, vector<int>& current){
        result.push_back(current);
        for(int i=start;i<nums.size();++i)
        {
            current.push_back(nums[i]);
            backtrack(nums, i+1, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0) return result;
        vector<int> current;
        result.push_back(current);
        for(auto num: nums){
            int n = result.size();
            for(int i=0;i<n;++i)
            {
                vector<int> currentSet = result[i];
                currentSet.push_back(num);
                result.push_back(currentSet);
            }
        }
        // backtrack(nums, 0, current);
        return result;
    }
};
