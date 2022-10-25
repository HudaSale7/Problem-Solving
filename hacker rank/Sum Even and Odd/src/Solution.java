
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public int[] sumEvenOdd(int[] array) {
        int even = 0;
        int odd = 0;
        if(array.length != 0) {
            for(int i = 0; i < array.length; i++) {
                if(array[i] % 2 == 0)
                    even += array[i];
                else
                    odd += array[i];
            }
        }
        int[] res = new int[2];
        res[0] = even;
        res[1] = odd;
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        String[] s = sin.split(", ");;
        int[] arr = new int[s.length];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[]{};
        else {
            for(int i = 0; i < s.length; ++i)
                arr[i] = Integer.parseInt(s[i]);
        }
        int[] res = new Solution().sumEvenOdd(arr);
        System.out.print("[" + res[0] + ", " + res[1] + "]");
    }
}
