//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int ntake = f(i - 1, arr, target, dp);
        int take = 0;

        if (target >= arr[i]) {
            take = f(i - 1, arr, target - arr[i], dp);
        }

        return dp[i][target] = take + ntake;
    }

    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if ((sum + d) % 2 != 0 || sum < d) return 0;

        int x = (sum + d) / 2;

        vector<vector<int>> dp(n, vector<int>(x + 1, -1));

        return f(n - 1, arr, x, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends