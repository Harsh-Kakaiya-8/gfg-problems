//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>>v(m+1, vector<int> (n+1));
        for (int i=1;i<=m;i++){
            v[i][1]=1;
        }
        for (int i=2; i<=n; i++){
            for(int j=1; j<=m; j++){
                for (int k=2*j;k<=m;k++){
                v[j][i]+=v[k][i-1];
            }
        }
    }
    int ans=0;
    for (int i=1; i<=m; i++){
        ans+=v[i][n];
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends