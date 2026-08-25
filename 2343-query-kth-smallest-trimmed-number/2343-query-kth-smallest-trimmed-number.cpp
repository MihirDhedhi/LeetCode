class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        for(int q = 0; q < queries.size(); q++) {
            
            int k = queries[q][0];
            int trim = queries[q][1];
            
            vector<pair<string, int>> temp;
            
            for(int i = 0; i < nums.size(); i++) {
                
                string s = nums[i].substr(nums[i].size() - trim);
                
                temp.push_back({s, i});
            }
            
            sort(temp.begin(), temp.end());
            
            ans.push_back(temp[k - 1].second);
        }
        
        return ans;
    }
};