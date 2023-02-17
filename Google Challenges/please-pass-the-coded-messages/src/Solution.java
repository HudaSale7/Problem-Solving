import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        System.out.println(solution(new int[]{1, 1, 1, 1, 1}));
    }
    public static int solution(int[] l) {
        if(l.length == 0) return 0;
        Arrays.sort(l);
        int temp = 0;
        for( int i = 0; i < l.length/2; ++i ) {
            temp = l[i];
            l[i] = l[l.length - i - 1];
            l[l.length - i - 1] = temp;
        }

        if(toInt(l) % 3 == 0) return toInt(l);
        int size = l.length - 1;

        for (int i = size; i >= 1; i--) {
            int comb = bt(l, new Stack<Integer>(), i, 0);
            if(comb != 0) return comb;
        }
        return 0;
    }

    public static int bt(int[] arr, Stack<Integer> comb, int size, int start) {
        if(comb.size() == size) {
            if(toInt(comb) % 3 == 0) return toInt(comb);
            else return 0;
        }
        for(int i = start; i < arr.length; i++) {
            comb.push(arr[i]);
            int num = bt(arr, comb, size, i+1);
            if(num != 0) return num;
            comb.pop();
        }
        return 0;
    }

    public static int toInt(Stack<Integer> arr) {
        StringBuilder s = new StringBuilder();
        for (int i : arr) {
            s.append(i);
        }
        return Integer.parseInt(s.toString());
    }

    public static int toInt(int[] arr) {
        StringBuilder s = new StringBuilder();
        for (int i : arr) {
            s.append(i);
        }
        return Integer.parseInt(s.toString());
    }

}
