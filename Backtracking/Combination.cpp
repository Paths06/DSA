class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int> list, int remain, int start)
    {   
        if(remain < 0) return ;
        else if(remain==0){
            result.push_back(list);
        }
        else{
            for(int i=start;i<candidates.size();++i){
                list.push_back(candidates[i]);
                backtrack(result, candidates, list, remain-candidates[i],i);
                list.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(result, candidates,{}, target,0);
        return result;
    }
};
