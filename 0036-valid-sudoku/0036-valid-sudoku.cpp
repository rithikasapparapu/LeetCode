class Solution {
public:
    bool isValidSquare(vector<vector<char>>& board, int i, int j){
        unordered_map <int,int> map;
        for(int x=i; x<i+3; x++){
            for(int y=j; y<j+3; y++){
                if(board[x][y]!='.'){
                    if(map.count(board[x][y])!=1){
                        map[board[x][y]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            unordered_map <int,int> map;
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(map.count(board[i][j])!=1){
                        map[board[i][j]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        for(int j=0; j<9; j++){
            unordered_map <int,int> map;
            for(int i=0; i<9; i++){

                if(board[i][j]!='.'){
                    if(map.count(board[i][j])!=1){
                        map[board[i][j]]++;
                    }
                    else{

                        return false;
                    }
                }
            }
        }

        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                if(!isValidSquare(board,i,j))
                    return false;
            }
        }
        return true;
    }
};