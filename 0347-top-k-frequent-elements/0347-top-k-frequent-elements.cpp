class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto x : mp)
            bucket[x.second].push_back(x.first);
        
        vector<int> ans;
        
        for(int i = nums.size(); i >= 1; i--) {
            
            for(int j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);
                
                if(ans.size() == k)
                    return ans;
            }
        }
        
        return ans;
    }
};