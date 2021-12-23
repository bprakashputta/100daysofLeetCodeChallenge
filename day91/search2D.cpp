class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we have to make use of the fact that rows are sorted 
        // and each row starting element is greater than the last 
        // element of previous row
        if(matrix.size()==1){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[0][j] == target){
                    return true;
                }
            }               
        }
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] == target){
                return true;
            }else if(i == matrix.size()-1){
                for(int j=0; j<matrix[i].size(); j++){
                    if(matrix[i][j] == target){
                        return true;
                    }
                }
            }else if(i<matrix.size()-1 && matrix[i][0] < target && matrix[i+1][0] > target){
                for(int j=0; j<matrix[i].size(); j++){
                    if(matrix[i][j] == target){
                        return true;
                    }
                }   
            }else{
                continue;
            }
        }
    return false;
    }
};