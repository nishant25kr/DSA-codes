//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    struct Meeting {
        int start;
        int end;
        int pos;
    };

    // Comparator function for sorting
    static bool compare(Meeting m1, Meeting m2) {
        if (m1.end == m2.end)
            return m1.pos < m2.pos; // If end times are the same, sort by position
        return m1.end < m2.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings(n);
        
        // Storing meetings with start, end, and index
        for (int i = 0; i < n; i++) {
            meetings[i] = {start[i], end[i], i + 1};
        }

        // Sorting meetings based on their end time
        sort(meetings.begin(), meetings.end(), compare);

        int count = 1; // The first meeting is always selected
        int lastEndTime = meetings[0].end;

        // Iterate through the sorted meetings
        for (int i = 1; i < n; i++) {
            if (meetings[i].start > lastEndTime) { // If a meeting starts after the last selected meeting ends
                count++;
                lastEndTime = meetings[i].end; // Update last meeting end time
            }
        }

        return count;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends