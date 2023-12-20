//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    // Create a frequency map for array a1
    std::unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < n; i++) {
        frequencyMap[a1[i]]++;
    }
    // Check if elements of a2 are present in a1
    for (int i = 0; i < m; i++) {
        // If the current element in a2 is not present in a1 or its frequency is 0,
        // then a2 is not a subset of a1
        if (frequencyMap.find(a2[i]) == frequencyMap.end() || frequencyMap[a2[i]] == 0) {
            return "No";
        }
        // Decrease the frequency of the current element in a1
        frequencyMap[a2[i]]--;
    }
    // If the loop completes, a2 is a subset of a1
    return "Yes";
}