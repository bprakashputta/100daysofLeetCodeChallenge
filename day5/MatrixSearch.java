import java.io.*;
import java.util.*;

public Class MatrixSearch{
    class Solution {
        public boolean searchMatrix(int[][] arr, int target) {
            for(int i=0; i<arr.length-1; i++){
                if(arr[i][0] == target){
                    return true;
                }else if(arr[i][0] < target && arr[i+1][0] > target){
                    for(int j=1; j<arr[i].length; j++){
                        if(arr[i][j] == target){
                            return true;
                        }
                    }
                }
            }
            int i=arr.length-1;
            for(int j=0; j<arr[i].length; j++){
                if(arr[i][j] == target){
                    return true;
                }
            }
        return false;
        }
    }
}