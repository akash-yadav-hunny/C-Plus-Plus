class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int num = 0;
        stack<int>st{{sign}};
        for(int i=0 ; i<s.size() ; ++i){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i]=='('){
                st.push(sign);
            }
            else if(s[i]==')'){
                st.pop();
            }
            else if(s[i]=='+' || s[i]=='-'){
                ans+=sign*num;
                sign = (s[i]=='+'?1 : -1) * st.top();
                num=0;
            }
        }return ans + sign*num;

    }
};
