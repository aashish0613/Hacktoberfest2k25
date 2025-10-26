/*
 * Maximum Sum of Non-Adjacent Elements
 * 
 * Problem: Given an array of positive integers, find the maximum sum 
 * of elements such that no two selected elements are adjacent.
 * 
 * Approach: Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(n) for array-based, O(1) for space-optimized
 * 
 * Author: Aashish (@aashish0613)
 * Hacktoberfest Contribution 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxSumNonAdjacentSolver {
private:
    // Helper method for space-optimized approach
    int solveSpaceOptimized(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        
        int prev2 = arr[0];                    // dp[i-2]
        int prev1 = max(arr[0], arr[1]);       // dp[i-1]
        
        for (int i = 2; i < n; i++) {
            int current = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
    
    // Helper method for array-based DP 
    int solveWithArray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        if (n == 2) return max(arr[0], arr[1]);
        
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }

public:
    /**
     * Find maximum sum of non-adjacent elements (Space Optimized)
     * @param arr: input array of positive integers
     * @return: maximum possible sum
     */
    int maxSum(vector<int>& arr) {
        return solveSpaceOptimized(arr);
    }
    
    /**
     * Find maximum sum of non-adjacent elements (Array-based DP)
     * @param arr: input array of positive integers
     * @return: maximum possible sum
     */
    int maxSumWithArray(vector<int>& arr) {
        return solveWithArray(arr);
    }
};

int main() {
    // Implementation ready for use
    return 0;
}