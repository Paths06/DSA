// There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).

// There are n + 1 taps located at points [0, 1, ..., n] in the garden.

// Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

// Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.









class Solution {





public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1,0);
        for(int i=0;i<=n;i++){
            int left = max(0, i-ranges[i]);
            int right = min(n, i+ranges[i]);
            maxReach[left] = max(maxReach[left],right);
        }
        int taps =0;
        int farthest =0;
        int currentEnd =0;
        for(int i=0;i<=n;i++){
            if(i>farthest) return -1;
            farthest = max(farthest, maxReach[i]);
            if(i==currentEnd){
                if(i!=n){
                    taps++;
                }
                currentEnd = farthest;
            }
        }
        return taps;
    }
};
