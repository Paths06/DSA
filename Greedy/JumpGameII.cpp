class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int last =n-1, i;
        vector<int> dist(n,0);
        for(i=n-2;i>=0;--i){
            int far = last -i;
            if(nums[i]==0){
                dist[i] = INT_MAX-1000;
                continue;
            }
            if(nums[i]>=far){
                dist[i] =1;
            }
            else{
                for(int j = i+1;j<=i+nums[i];++j)
                {
                    min_dist = min(dist[j], min_dist);
                }
                dist[i] = 1+ min_dist;
                // cout<<"min_dist for "<<nums[i]<<": "<<min_dist<<" ";
            }
            // cout<<"far: "<<far<<"| ";
            // for(int z=0;z<n;++z){
            //     cout<<dist[z]<<" ";
            // }
            // cout<<endl;
        }
        return dist[0];
    }
};
