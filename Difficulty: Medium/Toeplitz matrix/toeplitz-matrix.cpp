//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    if(n==1 && m==1)
        return true;
    int i = n-2, j = 0;
    while(i>0){
        int k = i, t = 0;
        int p = mat[i][0];
        while(k<n && t<m){
            if(mat[k][t] != p){
                return false;
            }
            k++;
            t++;
        }
        i--;
    }
    i = 0;
    j = 0;
    while(j < m-1){
        int k = 0, t = j;
        int p = mat[0][j];
        while(k<n && t<m){
            if(mat[k][t] != p){
                return false;
            }
            k++;
            t++;
        }
        j++;
    }
    return true;
}