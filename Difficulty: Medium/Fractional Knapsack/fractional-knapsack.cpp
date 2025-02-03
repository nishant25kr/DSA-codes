//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n = val.size();
        vector<pair<double, int>> items; // {value/weight, index}

        // Compute value/weight ratio and store with index
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        // Sort items based on value/weight ratio in descending order
        sort(items.rbegin(), items.rend());

        double total_val = 0.0;

        // Pick items greedily
        for (int i = 0; i < n; i++) {
            int idx = items[i].second; // Original index

            if (wt[idx] <= capacity) { 
                // Take the whole item
                total_val += val[idx];
                capacity -= wt[idx];
            } else { 
                // Take a fraction of the item
                total_val += (val[idx] * ((double)capacity / wt[idx]));
                break; // Knapsack is full
            }
        }

        return total_val;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends