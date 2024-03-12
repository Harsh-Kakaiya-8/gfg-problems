//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<long long>>multiply(vector<vector<long long>>mat1, vector<vector<long long>>mat2, long long m)
    {
        int r1=mat1.size(), c2=mat2[0].size(), c1=mat1[0].size();
        vector<vector<long long>>mat(r1, vector<long long>(c2, 0));
        
        for(int i=0; i<r1;i++){
            for(int j=0; j<c2; j++){
                for(int k=0; k<c1; k++){
                    mat[i][j]=(mat[i][j]%m + (mat1[i][k]%m * mat2[k][j]%m)%m)%m;
                }
            }
        }
        return mat;
    }
    vector<vector<long long>>power(vector<vector<long long>>mat, long long n, long long m)
    {
        vector<vector<long long>>res{{1,0,0},{0,1,0},{0,0,1}};
        
        while(n){
            if(n%2){
                res=multiply(res, mat, m);
                n--;
            }else{
                mat=multiply(mat, mat, m);
                n/=2;
            }
        }
        return res;
    }
  public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        vector<vector<long long>>mat{{a,b,1},{1, 0, 0}, {0, 0, 1}};
        
        vector<vector<long long>>M=power(mat, n-2, m);
        vector<vector<long long>>temp{{1}, {1}, {c}};
        vector<vector<long long>>ans=multiply(M, temp, m);
        return ans[0][0];
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends