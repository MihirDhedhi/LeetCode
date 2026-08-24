class Solution {
public:
    int superPow(int a, vector<int>& b) {
        
        int ans = 1;
        a = a % 1337;
        
        for(int i = 0; i < b.size(); i++) {
            
            // ans = ans^10
            int temp = 1;
            for(int j = 0; j < 10; j++) {
                temp = (temp * ans) % 1337;
            }
            
            // temp = temp * a^b[i]
            int power = 1;
            for(int j = 0; j < b[i]; j++) {
                power = (power * a) % 1337;
            }
            
            ans = (temp * power) % 1337;
        }
        
        return ans;
    }
};