class Solution {
public:
   bool isPalindrome(int x) {
        string st=to_string(x);
        
        int n=st.size();
        string left="";
        string right="";

        for(int i=0;i<n;i++) left+=st[i];

        for(int i=n-1;i>=0;i--) right+=st[i];

        if(left==right) return true;
        
        else return false;
        
    }
};