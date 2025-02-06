class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int len=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<char, int> hash;
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                len=j-i+1;
                maxlen=max(maxlen,len);
                hash[s[j]]=1;  
            }
        }
    return maxlen;
    }
};