class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i =0; i<row; i++){
            for(int j = i; j<row;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i<row;i++){
            int l = 0, r = row-1;
            while(l<r){
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
    }
    
};