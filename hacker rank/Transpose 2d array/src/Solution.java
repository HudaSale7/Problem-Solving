import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public int[][] transpose(int[][] array) {
        int size = array.length;
        int[][] tran = new int[size][size];
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                tran[i][j] = array[j][i];
            }
        }
        return tran;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        String[] s = sin.split(", ");
        int size = (int)Math.sqrt(s.length);
        int[][] arr = new int[size][size];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[][]{};
        else {
            int k = 0;
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if(k < s.length)
                        arr[i][j] = Integer.parseInt(s[k++]);
                }
            }
        }

        System.out.print("[");
        if(size > 1) {
            int[][] res = new Solution().transpose(arr);
            for(int i = 0; i < size; i++) {
                System.out.print("[");

                for(int j = 0; j < size; j++) {
                    System.out.print(res[i][j]);

                    if(j != size - 1)
                        System.out.print(", ");
                }

                System.out.print("]");
                if(i != size - 1)
                    System.out.print(", ");
            }
        }
        else if(s[0].isEmpty()) {
            System.out.print("[]");
        }
        else {
            System.out.print("[0]");
        }
        System.out.print("]");

    }
}
