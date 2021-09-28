import java.io.*;
import java.util.*;

public Class ValidSudoku{
    public boolean isValidSudoku(char[][] board) {
        // for each row
        for(int i=0; i<9; i++){
            // declare row set, column set, box set
            HashSet<Character> rw = new HashSet<Character>();
            HashSet<Character> cl = new HashSet<Character>();
            HashSet<Character> box = new HashSet<Character>();
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' && !rw.add(board[i][j])){
                    return false;
                }
                if(board[j][i] != '.' && !cl.add(board[j][i])){
                    return false;
                }

                if(board[3*(i/3) + (j/3)][3*(i%3) + (j%3)] != '.' && !box.add(board[3*(i/3) + (j/3)][3*(i%3) + (j%3)])){
                    return false;
                }
            }
        }
    return true;
    }
}