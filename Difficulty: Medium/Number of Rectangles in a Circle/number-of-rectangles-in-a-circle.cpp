//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int rect=0;
        int l=2*r;
        int b=2*r;
        int p=4*r*r;
        
        for(int i=1; i<l; i++){
            for(int j=1; j<b; j++){
                if((i*i+j*j)<=p){
                    rect++;
                }
            }
        }
        return rect;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends