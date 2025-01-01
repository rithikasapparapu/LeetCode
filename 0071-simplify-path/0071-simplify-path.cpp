class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        string s = "";
        for(int i=0; i<path.length(); i++){
            if(path[i]!='/'){
                s = s + path[i];
            }
            else{
                if(s.length()!=0){
                    if(s==".."){
                        if(!st.empty())
                            st.pop();
                    }
                    else if(s==".")
                        ;
                    else{
                        st.push(s);
                    }
                    s = "";
                }
            }
        }
        if(s.length()!=0){
            if(s==".."){
                if(!st.empty())
                    st.pop();
            }
            else if(s==".")
                ;
            else{
                st.push(s);
            }
        }
        stack<string> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        if(st1.empty())
            return "/";
        string result = "";
        while(!st1.empty()){
            result += "/" + st1.top();
            st1.pop();
        }
        return result;
    }
};