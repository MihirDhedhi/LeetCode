class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> values;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int x = matrix[i][j];
                
                if(i > 0)
                    x = x ^ matrix[i - 1][j];
                
                if(j > 0)
                    x = x ^ matrix[i][j - 1];
                
                if(i > 0 && j > 0)
                    x = x ^ matrix[i - 1][j - 1];
                
                matrix[i][j] = x;
                
                values.push_back(x);
            }
        }
        
        sort(values.begin(), values.end(), greater<int>());
        
        return values[k - 1];
    }
};