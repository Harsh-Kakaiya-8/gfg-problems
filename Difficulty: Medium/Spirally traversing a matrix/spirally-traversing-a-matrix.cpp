//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int u=0, d=matrix.size()-1,l=0,r=matrix[0].size()-1;
        bool H=true, F=true;
        vector<int>ans;
        while(u<=d && l<=r){
            if(H){
                if(F){
                    for(int i=l; i<=r; i++) ans.push_back(matrix[u][i]);
                    u++;
                    H=false;
                }else{
                    for(int i=r; i>=l; i--) ans.push_back(matrix[d][i]);
                    d--;
                    H=false;
                }
            }else{
                if(F){
                    for(int i=u; i<=d; i++) ans.push_back(matrix[i][r]);
                    r--;
                    H=true;
                    F=false;
                }else{
                    for(int i=d; i>=u; i--)ans.push_back(matrix[i][l]);
                    l++;
                    H=true;
                    F=true;
                }
            }
        }return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends