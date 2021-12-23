class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Logic is to take transpose of matrix
        // and then reverse every row
        
        // Step 1 : Take transpose of matrix
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[i].size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Step 2 : Reverse every row of matrix
        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};