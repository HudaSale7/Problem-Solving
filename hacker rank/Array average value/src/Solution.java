
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public double average(int[] array) {
        double avr = 0;
        if(array.length != 0) {
            for(int i = 0; i < array.length; i++)
                avr += array[i];

            avr /= array.length;
        }
        return avr;
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
        System.out.println(new Solution().average(arr));
    }
}
