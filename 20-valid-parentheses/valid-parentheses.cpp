class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i] == '(' or s[i] ==  '{' or s[i] ==  '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();

                if((s[i]==')' and ch!='(') or (s[i]=='}' and ch!='{') or (s[i]==']' and ch!='[')){
                    return false;
                    }
            }
        }  
        return st.empty();
               
    }
};