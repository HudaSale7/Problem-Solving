import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public int fibonacci(int n) {
        int n1 = 1;
        int n2 = 0;
        int fib = 0;
        if(n == 1)
            return n2;

        else if (n == 2)
            return n1;

        else {
            for(int i = 3; i <= n; i++) {
                fib = n1 + n2;
                n2 = n1;
                n1 = fib;
            }
        }
        return fib;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int fib = sc.nextInt();
        System.out.println(new Solution().fibonacci(fib));
    }
}
