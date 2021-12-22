class Solution {
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        vector<vector<int>> pascal;
        // pascal.push_back({1});
        for(int i=0; i<numRows; i++){
            vector<int> row(i+1);
            for(int j=0; j<=i; j++){
                if(j==0||j==i){
                    row[j]=1;
                }else{
                    row[j] = pascal[i-1][j-1]+pascal[i-1][j];
                }
            }
            pascal.push_back(row);
        }
    return pascal;
    }
};