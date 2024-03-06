//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> v;
            int left=0,right=0;
            int ans=-1;
            
            while(left<=text.size()-pattern.size()){
                if(text[left]==pattern[right]){
                    int idx=left;
                    ans=left;
                    
                    while(right<pattern.size()&&text[idx]==pattern[right]){
                        idx++;
                        right++;
                    }
                    if(right==pattern.size())
                        v.push_back(ans+1);
                    right=0;
                }
                left++;
            }
            return v;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends