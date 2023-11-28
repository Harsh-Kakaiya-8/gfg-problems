//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector <int> ans;
        bool flag=false;
        int i=0;
        while(i<n-1){
            int p1=i;
            int p2=p1+1;
            
            if(a[p1]>a[p2]){
                for(int k=p2;k<n;k++){
                    if(a[p1]>=a[k]){
                        flag=true;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(a[p1]);
                    p1++;
                }
            }
            else{
                p1=p2;
            }
            i++;
        }
        ans.push_back(a[n-1]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends