class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxf = 0, maxlen = 0;
        int hash[26] = {0}; // Frequency array for character counts

        while (r < s.size()) {
            hash[s[r] - 'A']++;  // Increase frequency count
            maxf = max(maxf, hash[s[r] - 'A']); // Track max frequency

            // If window size minus most frequent char count exceeds k, shrink the window
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--; // Reduce count of leftmost character
                l++; // Move left pointer
            }

            // Update max length
            maxlen = max(maxlen, r - l + 1);
            r++; // Expand window
        }

        return maxlen;
    }
};
