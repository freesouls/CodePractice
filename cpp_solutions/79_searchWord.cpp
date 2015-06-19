class Solution {
public:
    int m = 0;
    int n = 0;
    int w = 0;
    
    //vector<pair<int, int> > path;
    int** used;
    //string str_word;
    bool exist(vector<vector<char>>& board, string word) {
        w = word.length();
        if (w == 0){
            return true;
        }
        m = board.size();
        if (m){
            //str_word = word;
            n = board[0].size();
            used = new int*[m];
            for (int i = 0; i < m; i++) {
                used[i] = new int[n];
                memset(used[i], 0, n);
            }
            for(int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if (board[i][j] == word[0]){
                        //path.clear();
                        if (exist(board, i, j, word, 0)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        else{
            return false;
        }
    }
    
    bool exist(vector<vector<char> >& board, int i, int j, string& word, int index){
//        if (find(path.begin(), path.end(), pair<int, int>(i, j))!= path.end()) {
//            return false;
//        }
        if (used[i][j] == 1) {
            return false;
        }
        if (board[i][j] == word[index]){
            used[i][j] = 1;
            //path.push_back(pair<int, int>(i,j));
            if (index == w-1){
                return true;
            }
            else{
                if (i > 0 && exist(board, i - 1, j, word, index + 1)){
                    return true;
                }
                if (i < m - 1 && exist(board, i + 1, j, word, index + 1)){
                    return true;
                }
                if (j > 0 && exist(board, i, j - 1, word, index + 1)){
                    return true;
                }
                if (j < n - 1 && exist(board, i, j + 1, word, index + 1)){
                    return true;
                }
                used[i][j] = 0;
                //path.pop_back();
                return false;
            }
        }
        else{
            return false;
        }
    }
};

/* version 2, used less memory but the speed is very low, find costs too much time
class Solution {
public:
    int m = 0;
    int n = 0;
    int w = 0;
    vector<pair<int, int> > path;
    bool exist(vector<vector<char>>& board, string word) {
        w = word.length();
        if (w == 0){
            return true;
        }
        m = board.size();
        if (m){
            n = board[0].size();
            for(int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if (board[i][j] == word[0]){
                        path.clear();
                        if (exist(board, i, j, word, 0)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        else{
            return false;
        }
    }
    
    bool exist(vector<vector<char> >& board, int i, int j, string& word, int index){
        if (find(path.begin(), path.end(), pair<int, int>(i, j))!= path.end()) {
            return false;
        }
        if (board[i][j] == word[index]){
            path.push_back(pair<int, int>(i,j));
            if (index == w-1){
                return true;
            }
            else{
                if (i > 0 && exist(board, i - 1, j, word, index + 1)){
                    return true;
                }
                if (i < m - 1 && exist(board, i + 1, j, word, index + 1)){
                    return true;
                }
                if (j > 0 && exist(board, i, j - 1, word, index + 1)){
                    return true;
                }
                if (j < n - 1 && exist(board, i, j + 1, word, index + 1)){
                    return true;
                }
                path.pop_back();
                return false;
            }
        }
        else{
            return false;
        }
    }
};
*/
