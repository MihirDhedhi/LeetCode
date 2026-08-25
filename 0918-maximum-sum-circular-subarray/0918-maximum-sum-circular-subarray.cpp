class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = 0;
        
        int maxSum = nums[0];
        int currentMax = nums[0];
        
        int minSum = nums[0];
        int currentMin = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            
            total += nums[i];
            
            if(i > 0) {
                currentMax = max(nums[i], currentMax + nums[i]);
                maxSum = max(maxSum, currentMax);
                
                currentMin = min(nums[i], currentMin + nums[i]);
                minSum = min(minSum, currentMin);
            }
        }
        
        // If all numbers are negative
        if(maxSum < 0)
            return maxSum;
        
        int circularSum = total - minSum;
        
        return max(maxSum, circularSum);
    }
};