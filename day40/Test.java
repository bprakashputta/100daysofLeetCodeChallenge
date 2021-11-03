import java.util.*;
import java.lang.*;
import java.io.*;

public class Test{
   public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        int arr[];
        try{
            input = reader.readLine().split("\\s");
            arr = new int[input.length];
            for (int i = 0; i < input.length; i++) {
                arr[i] = Integer.parseInt(input[i]);
            }    

            // webs
            int numWebs = 1;
            int prev = 1;
            for(int i=1; i<arr.length; i++){
                if(arr[i]<=arr[i-1]){
                    numWebs = numWebs+1;
                    prev = numWebs;
                }else{
                    // prev = prev + 1;
                    numWebs = numWebs + prev + 1;
                    System.out.println(numWebs);
                }
            }

            System.out.println("Number of Webs: "+numWebs);
        }catch(Exception ex){
            System.out.println(ex);
        }
    }
}