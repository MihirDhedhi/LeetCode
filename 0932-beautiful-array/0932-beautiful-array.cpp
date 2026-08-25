class Solution {
public:
    vector<int> beautifulArray(int n) {
        
        if(n == 1)
            return {1};
        
        vector<int> odd;
        vector<int> even;
        
        // Make beautiful array for smaller numbers
        vector<int> temp = beautifulArray((n + 1) / 2);
        
        // Convert to odd numbers
        for(int i = 0; i < temp.size(); i++) {
            odd.push_back(2 * temp[i] - 1);
        }
        
        // Convert to even numbers
        temp = beautifulArray(n / 2);
        
        for(int i = 0; i < temp.size(); i++) {
            even.push_back(2 * temp[i]);
        }
        
        // Combine odd and even
        vector<int> ans;
        
        for(int x : odd)
            ans.push_back(x);
        
        for(int x : even)
            ans.push_back(x);
        
        return ans;
    }
};