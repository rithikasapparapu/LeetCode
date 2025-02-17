class Solution {
public:
    void f(string temp, string tiles, vector<int>& visited, unordered_set<string>& result){
        for(int i=0; i<tiles.length(); i++){
            if(visited[i]==0){
                temp += tiles[i];
                result.insert(temp);
                visited[i]++;
                f(temp, tiles, visited, result);
                visited[i]--;
                temp.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> visited(tiles.size(),0);
        unordered_set<string> result;
        f("", tiles, visited, result);
        return result.size();
    }
};