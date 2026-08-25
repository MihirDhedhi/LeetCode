class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        long long MOD = 1000000007;
        
        for(int i = 0; i < queries.size(); i++) {
            
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            
            for(int j = l; j <= r; j += k) {
                nums[j] = (nums[j] * 1LL * v) % MOD;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        
        return ans;
    }
};