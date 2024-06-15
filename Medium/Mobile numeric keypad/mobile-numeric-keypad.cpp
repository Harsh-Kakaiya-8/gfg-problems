//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 10;
        }
        vector<vector<int>>adj={
            {0,8},
            {1,2,4},
            {1,2,3,5},
            {2,3,6},
            {1,4,5,7},
            {2,4,5,6,8},
            {3,5,6,9},
            {4,7,8},
            {0,5,7,8,9},
            {6,8,9}
        };
        vector<vector<long long>>dp(n+1, vector<long long>(10,0));
        for(int i=0; i<=9; ++i){
            dp[1][i]=1;
        }
        for(int length=2; length<=n; ++length){
            for(int digit=0; digit<=9; ++digit){
                dp[length][digit]=0;
                for(int prev:adj[digit]){
                    dp[length][digit]+=dp[length-1][prev];
                }
            }
        }
        long long totalCount=0;
        for(int i=0; i<=9; ++i){
            totalCount+=dp[n][i];
        }
        return totalCount;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends