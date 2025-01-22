class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>>result(rows,vector<int>(cols,-1));
        queue <pair<int,int>> q; 
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    result[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int val = result[i][j] + 1;
            if(i-1>=0 && result[i-1][j]==-1){
                result[i-1][j] = val;
                q.push(make_pair(i-1,j));
            }
            if(i+1<=rows-1 && result[i+1][j]==-1){
                result[i+1][j] = val;
                q.push(make_pair(i+1,j));
            }
            if(j-1>=0 && result[i][j-1]==-1){
                result[i][j-1] = val;
                q.push(make_pair(i,j-1));
            }
            if(j+1<=cols-1 && result[i][j+1]==-1){
                result[i][j+1] = val;
                q.push(make_pair(i,j+1));
            }
            q.pop();
        }
        return result;
    }
};