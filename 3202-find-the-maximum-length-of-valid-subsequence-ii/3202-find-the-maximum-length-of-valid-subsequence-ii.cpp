class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // dp[i][j] represents the maximum length of subsequence 
        // where consecutive elements have remainders i and j alternately
        int dp[k][k];
        memset(dp, 0, sizeof(dp));
      
        int maxLength = 0;
      
        // Process each number in the array
        for (int num : nums) {
            int remainder = num % k;
          
            // Try all possible previous remainders
            for (int prevRemainder = 0; prevRemainder < k; ++prevRemainder) {
                // Calculate the required remainder for the element before previous
                // to maintain the alternating sum pattern
                int targetRemainder = (prevRemainder - remainder + k) % k;
              
                // Update dp: extend the subsequence ending with (targetRemainder, remainder)
                // by appending current element with remainder
                dp[remainder][targetRemainder] = dp[targetRemainder][remainder] + 1;
              
                // Update the maximum length found so far
                maxLength = max(maxLength, dp[remainder][targetRemainder]);
            }
        }
      
        return maxLength;
    }
};
