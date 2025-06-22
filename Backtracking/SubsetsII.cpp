class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueSet;
        vector<vector<int>> result;
        vector<int> current;
        uniqueSet.insert(current);
        result.push_back(current);
        for(auto num: nums){
            int n = result.size();
            for(int i=0;i<n;++i){
                vector<int> currentSet = result[i];
                
                currentSet.push_back(num);
                // uniqueSet.insert(currentSet);
                if(uniqueSet.find(currentSet)== uniqueSet.end()){
                    result.push_back(currentSet);
                    uniqueSet.insert(currentSet);
                }
            }
        }
        return result;
    }
};
