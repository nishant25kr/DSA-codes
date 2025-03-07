//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n<3){
            if(arr[0]>arr[1]){
                return false;
            }else{
                return true;
            }
        }
        
        
        for(int i=1;i<n-1;i++){
            if(arr[i-1] < arr[i] and arr[i] < arr[i+1]){
                
            }else{
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends