class Solution
{
    private:
    int getKnapSack(int idx, int w, int *val, int *wt, vector<vector<int>> &dp){
        if(idx == 0){
            if(wt[0] <= w) return val[0];
            return 0;
        }
        if(dp[idx][w] != -1) return dp[idx][w];
        
        int take = 0, notTake = 0;
        if(wt[idx]<=w)
            take = val[idx] + getKnapSack(idx-1, w-wt[idx], val, wt, dp);
        notTake = getKnapSack(idx-1, w, val, wt, dp);
        
        return dp[idx][w] = max(take, notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return getKnapSack(n-1, W, val, wt, dp);
    }
};
