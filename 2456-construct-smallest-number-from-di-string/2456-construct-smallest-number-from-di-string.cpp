class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        int n = pattern.length();
        vector<int> visited(n+2,0);
        int count = 0;
        int prev = 0;
        for(int i=0; i<pattern.length(); i++){
            if(i==0 && pattern[i]=='D'){
                count = 1;
                int counter = i;
                while(1){
                    if(counter<pattern.length()-1 && pattern[counter]==pattern[counter+1]){
                        count++;
                        counter++;
                    }
                    else break;
                }
                int j;
                for(j=1; j<=visited.size(); j++){
                    if(visited[j]==0) break;
                }
                prev = count+j;
                visited[prev]++;
                result += to_string(prev);
            }
            else if(i==0 && pattern[i]=='I'){
                prev = 1;
                visited[prev] = 1;
                result += to_string(prev);
            }
            else{
                if(pattern[i-1]=='D' && pattern[i]=='D'){
                    prev -= 1;
                    visited[prev]++;
                    result += to_string(prev);
                }
                else if(pattern[i-1]=='I' && pattern[i]=='D'){
                    count = 1;
                    int counter = i;
                    while(1){
                        if(counter<pattern.length()-1 && pattern[counter]==pattern[counter+1]){
                            count++;
                            counter++;
                        }
                        else break;
                    }
                    int j;
                    for(j=1; j<=visited.size(); j++){
                        if(visited[j]==0) break;
                    }
                    prev = count+j;
                    visited[prev]++;
                    result += to_string(prev);
                }
                else{
                    int j;
                    for(j=1; j<visited.size(); j++){
                        if(visited[j]==0) break;
                    }
                    prev = j;
                    visited[prev]++;
                    result += to_string(prev);
                }
            }
        }
        int j;
        for(j=1; j<=visited.size(); j++){
            if(visited[j]==0) break;
        }
        result += to_string(j);
        return result;
    }
};