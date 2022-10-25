
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public int[] moveValue(int[] array, int value) {
        int index = 0;
        for(int i = 0; i < array.length; i++) {
            if(array[i] == value) {
                index = i;
                break;
            }
        }
        for(int i = index + 1; i < array.length; i++) {
            if(array[i] == value) continue;
            int temp = array[index];
            array[index++] = array[i];
            array[i] = temp;
        }
        return array;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        int value = sc.nextInt();
        String[] s = sin.split(", ");;
        int[] arr = new int[s.length];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[]{};
        else {
            for(int i = 0; i < s.length; ++i)
                arr[i] = Integer.parseInt(s[i]);
        }
        new Solution().moveValue(arr, value);
        System.out.print("[");
        for(int i = 0; i < arr.length; ++i) {
            System.out.print(arr[i]);
            if(i != s.length - 1)
                System.out.print(", ");
        }
        System.out.print("]");
    }
}
