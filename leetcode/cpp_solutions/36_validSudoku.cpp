class Solution {
public:
    inline bool checkUsed(int num, bool* used){
        if (used[num]){
            return true;
        }
        else{
            used[num] = true;
            return false;
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        for (int i = 0; i < 9; i++){
            fill(used, used+9, false);
            for (int j = 0; j < 9; j++){
                if(board[i][j] != '.' && checkUsed(board[i][j]-'1', used)){
                    return false;
                }
            }
            
            fill(used, used+9, false);
            for (int j = 0; j < 9; j++){
                if(board[j][i] != '.' && checkUsed(board[j][i]-'1', used)){
                    return false;
                }
            }
        }
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                fill(used, used+9, false);
                for (int k = i*3; k < i*3+3; k++){
                    for (int l = j*3; l < j*3+3; l++){
                        if(board[k][l] != '.' && checkUsed(board[k][l]-'1', used)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};