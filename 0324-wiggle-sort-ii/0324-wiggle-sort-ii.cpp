class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> temp = nums;
        
        int n = nums.size();
        int mid = (n + 1) / 2;
        
        int j = mid - 1;
        int k = n - 1;
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                nums[i] = temp[j--];
            else
                nums[i] = temp[k--];
        }
    }
};