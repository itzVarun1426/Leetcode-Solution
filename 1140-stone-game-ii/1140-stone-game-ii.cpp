class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int numPiles = piles.size();
      
        // Create prefix sum array to quickly calculate sum of any range
        // prefixSum[i] represents sum of piles[0...i-1]
        vector<int> prefixSum(numPiles + 1, 0);
        for (int i = 0; i < numPiles; ++i) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }
      
        // Memoization table: dp[i][m] stores the maximum stones Alice can get
        // starting from index i with parameter M = m
        vector<vector<int>> dp(numPiles, vector<int>(numPiles + 1, 0));
      
        // Recursive function with memoization
        // Returns maximum stones the current player can get starting from index 'index' with parameter 'M'
        function<int(int, int)> dfs = [&](int index, int M) -> int {
            // Base case: if we can take all remaining piles
            // (when 2*M is greater than or equal to remaining piles)
            if (2 * M >= numPiles - index) {
                return prefixSum[numPiles] - prefixSum[index];
            }
          
            // Return memoized result if already computed
            if (dp[index][M] != 0) {
                return dp[index][M];
            }
          
            int maxStones = 0;
          
            // Try taking X piles where X ranges from 1 to 2*M
            for (int X = 1; X <= 2 * M; ++X) {
                // Calculate maximum stones we can get by taking X piles
                // Total remaining stones - stones opponent will get optimally
                int stonesIfTakeX = prefixSum[numPiles] - prefixSum[index] - 
                                    dfs(index + X, max(X, M));
                maxStones = max(maxStones, stonesIfTakeX);
            }
          
            // Store and return the result
            dp[index][M] = maxStones;
            return maxStones;
        };
      
        // Start the game from index 0 with M = 1
        return dfs(0, 1);
    }
};