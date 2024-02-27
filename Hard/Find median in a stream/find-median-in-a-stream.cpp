//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        auto& number = x;
        
        auto maxheapSize = maxHeap.size();
        auto minHeapSize = minHeap.size();
        
        if (maxheapSize == minHeapSize){
            if(maxheapSize==0){
                maxHeap.push(number);
                balanceHeaps();
                return;
            }
            auto topMaxheap = maxHeap.top();
            if(number<=topMaxheap){
                maxHeap.push(number);
            }else{
                minHeap.push(number*-1);
                auto topMinheap = minHeap.top()*-1;
                minHeap.pop();
                
                maxHeap.push(topMinheap);
            }
        }
        if(maxheapSize>minHeapSize){
            auto topMaxheap=maxHeap.top();
            if(number>=topMaxheap){
                minHeap.push(number*-1);
            }else{
                maxHeap.pop();
                maxHeap.push(number);
                minHeap.push(topMaxheap*-1);
            }
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int result = 0;
        auto size = maxHeap.size()+minHeap.size();
        if(size%2==0){
            result=(maxHeap.top()+(minHeap.top()*-1))/2;
        }else{
            result = maxHeap.top();
        }
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends