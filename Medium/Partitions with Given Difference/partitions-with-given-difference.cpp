//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod =(int)1e9+7;
    int solve(int ind, vector<int> &arr, int k, vector<vector<int>> &dp){
        if(ind==0){
            if(k==0 and arr[0]==0)
                return 2;
            if(k==0 or arr[0]==k)
                return 1;
            return 0;
        }
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int notTake=solve(ind-1,arr, k, dp);
        int take=0;
        
        if(arr[ind]<=k)
            take=solve(ind-1, arr, k-arr[ind], dp);
        return dp[ind][k]=(take+notTake)%mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        int k=sum-d;
        
        if(k<0 or k%2==1)
            return 0;
        k/=2;
        
        vector<vector<int>>dp(n, vector<int> (k+1, -1));
        return solve(n-1, arr, k, dp);
    }
    // int countPartitions(int n, int d, vector<int>& arr){
    //     int sum=accumulate(arr.begin(), arr.end(), 0);
    //     int k=sum-d;
        
    //     if(k<0 or k%2==1)
    //         return 0;
            
    //     k/=2;
    //     vector<vector<int>>dp(n, vector<int>(k+1, 0));
    //     for(int i=0; i<n; i++)
    //         dp[i][0]=1;
    //     if(arr[0]<=k)
    //         dp[0][arr[0]]=1;
    //     if(arr[0]==0)
    //         dp[0][0]=2;
    //     for(int i=1; i<n; i++){
    //         for(int j=0; j<=k; j++){
    //             int notTake=dp[i-1][j];
    //             int take=0;
                
    //             if(arr[i]<=j)
    //                 take=dp[i-1][j-arr[i]];
    //             dp[i][j]=(take+notTake)%mod;
    //         }
    //     }
    //     return dp[n-1][k];
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends