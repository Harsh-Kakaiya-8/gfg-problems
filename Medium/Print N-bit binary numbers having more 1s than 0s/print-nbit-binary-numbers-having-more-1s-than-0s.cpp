//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    if(n<=0){
            return {};
        }

        if(n==1){
            return {"1"};
        }

        vector<string>ans=NBitBinary(n-1);


        unordered_map<string,int>mp;


        vector<string>v;

        for(int i=0;i<ans.size();i++){
            string a=ans[i];
            string b=ans[i];
            int count1=0,count0=0;
            for(int j=0;j<a.size();j++){
                if(a[j]=='1'){
                    count1++;
                }
                if(a[j]=='0'){
                    count0++;
                }
            }
             a=a+'1'; b=b+'0';
            if(mp.find(a)==mp.end()&&count1+1>count0){
                mp[a]++;
                v.push_back(a);
            }
             if(mp.find(b)==mp.end()&&count1>count0){
                mp[b]++;
                 v.push_back(b);
            }
            
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends