class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        queue<vector<int>> permutation;
        permutation.push({});
        for(auto num: nums){
            int n = permutation.size();
            for(int i=0;i<n;++i){
                auto oldPermutation = permutation.front();
                permutation.pop();
                for(int j=0;j<=oldPermutation.size();j++){
                    vector<int> newPermutation(oldPermutation);
                    newPermutation.insert(newPermutation.begin()+j, num);
                    if(newPermutation.size() == nums.size()){
                        result.push_back(newPermutation);
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
