//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long ans=-1;
        stringstream ss(sentence);
        string temp;
        
        while(getline(ss, temp, ' ')){
            if(temp[0]<'0' || temp[0]>'9') continue;
            bool containsNine=false;
            for(char c:temp){
                if(c=='9'){
                    containsNine=true;
                    break;
                }
            }
            if (!containsNine){
                ans=max(ans, stoll(temp));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends