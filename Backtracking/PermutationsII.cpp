class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        queue<vector<int>> permutation;
        set<vector<int>> st;
        permutation.push({});
        st.insert({});
        for(auto num: nums){
            int n = permutation.size();
            for(int i=0;i<n;++i){
                auto oldPermutation = permutation.front();
                permutation.pop();
                for(int j=0;j<=oldPermutation.size();j++){
                    vector<int> newPermutation(oldPermutation);
                    newPermutation.insert(newPermutation.begin()+j, num);
                    if(newPermutation.size() == nums.size()){
                        if(st.find(newPermutation)==st.end()){
                             result.push_back(newPermutation);
                             st.insert(newPermutation);
                        }

                    }
                    else{
                        permutation.push(newPermutation);
                    }
                }
            }
        }
        return result;
    }
};
