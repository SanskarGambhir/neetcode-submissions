class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {       
        for(int i=0; i<9; i++){
            unordered_map<char, int> rows;
            unordered_map<char, int> columns;
            unordered_map<char, int> boxes;

            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    rows[board[i][j]]++;
                }
                if(board[j][i] != '.'){
                    columns[board[j][i]]++;
                }
                int row = 3*(i/3)+(j/3);
                int column = 3*(i%3)+j%3;
                if(board[row][column] != '.'){
                    boxes[board[row][column]]++;
                }
            }

            for(auto r:rows){
                if(r.second>1){
                    return false;
                }
            }

            for(auto c:columns){
                if(c.second>1){
                    return false;
                }
            }

            for(auto b:boxes){
                if(b.second>1){
                    return false;
                }
            }
        }

        return true;
    }
};
