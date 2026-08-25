class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(s.size() < k)
            return 0;
        
        int count[26] = {0};
        
        for(int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(count[s[i] - 'a'] < k) {
                
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                
                return max(left, right);
            }
        }
        
        return s.size();
    }
};