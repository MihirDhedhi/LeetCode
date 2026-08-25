class Solution {
public:
    string longestNiceSubstring(string s) {
        
        string ans = "";
        
        for(int i = 0; i < s.size(); i++) {
            
            bool present[52] = {false};
            
            for(int j = i; j < s.size(); j++) {
                
                if(s[j] >= 'a' && s[j] <= 'z')
                    present[s[j] - 'a'] = true;
                else
                    present[s[j] - 'A' + 26] = true;
                
                bool nice = true;
                
                for(int k = 0; k < 26; k++) {
                    if(present[k] != present[k + 26]) {
                        nice = false;
                        break;
                    }
                }
                
                if(nice && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }
        
        return ans;
    }
};