//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> count (string s)
        {
            //code here.
            int countUpper=0;
            int countLower=0;
            int countNumeric=0;
            int countSpecial=0;
            for(int i=0;i<s.length();i++){
                if(s[i]>='a'&&s[i]<='z'){
                    countLower++;
                }
                else if(s[i]>='A'&&s[i]<='Z'){
                    countUpper++;
                }
                else if(s[i]>='0'&&s[i]<='9'){
                    countNumeric++;
                }
                else{
                    countSpecial++;
                }
            }
            return {countUpper, countLower, countNumeric, countSpecial};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        vector <int> res = ob.count (s);
        for (int i : res)
            cout << i << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends